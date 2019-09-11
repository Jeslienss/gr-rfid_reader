/* -*- c++ -*- */
/* 
 * Copyright 2019 Jiawei.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "gate_impl.h"

namespace gr {
    namespace rfid_reader {

        gate::sptr
        gate::make(int sample_rate) {
            return gnuradio::get_initial_sptr
                    (new gate_impl(sample_rate));
        }

        /*
         * The private constructor
         */
        gate_impl::gate_impl(int sample_rate)
                : gr::block("gate",
                            gr::io_signature::make(1, 1, sizeof(gr_complex)),
                            gr::io_signature::make(1, 1, sizeof(gr_complex))),
                  n_samples(0), win_index(0), dc_index(0), num_pulses(0), signal_state(NEG_EDGE), avg_ampl(0),
                  dc_est(0, 0) {
            n_samples_T1 = T1_D * (sample_rate / pow(10, 6));
            n_samples_PW = PW_D * (sample_rate / pow(10, 6));
            n_samples_TAG_BIT = TAG_BIT_D * (sample_rate / pow(10, 6));

            win_length = WIN_SIZE_D * (sample_rate / pow(10, 6));
            dc_length = DC_SIZE_D * (sample_rate / pow(10, 6));

            win_samples.resize(win_length);
            dc_samples.resize(dc_length);


        }

        /*
         * Our virtual destructor.
         */
        gate_impl::~gate_impl() {
        }

        void
        gate_impl::forecast(int noutput_items, gr_vector_int &ninput_items_required) {
            ninput_items_required[0] = noutput_items;
        }

        int
        gate_impl::general_work(int noutput_items,
                                gr_vector_int &ninput_items,
                                gr_vector_const_void_star &input_items,
                                gr_vector_void_star &output_items) {
            const gr_complex *in = (const gr_complex *) input_items[0];
            gr_complex *out = (gr_complex *) output_items[0];

            // Do <+signal processing+>
            // Tell runtime system how many input items we consumed on
            // each input stream.
            consume_each(noutput_items);

            // Tell runtime system how many output items we produced.
            return noutput_items;
        }

    } /* namespace rfid_reader */
} /* namespace gr */


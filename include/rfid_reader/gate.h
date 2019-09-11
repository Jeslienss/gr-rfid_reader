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


#ifndef INCLUDED_RFID_READER_GATE_H
#define INCLUDED_RFID_READER_GATE_H

#include <rfid_reader/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace rfid_reader {

    /*!
     * \brief <+description of block+>
     * \ingroup rfid_reader
     *
     */
    class RFID_READER_API gate : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<gate> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of rfid_reader::gate.
       *
       * To avoid accidental use of raw pointers, rfid_reader::gate's
       * constructor is in a private implementation
       * class. rfid_reader::gate::make is the public interface for
       * creating new instances.
       */
      static sptr make( int sample_rate);
    };

  } // namespace rfid_reader
} // namespace gr

#endif /* INCLUDED_RFID_READER_GATE_H */


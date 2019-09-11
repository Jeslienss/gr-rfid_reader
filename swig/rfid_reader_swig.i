/* -*- c++ -*- */

#define RFID_READER_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "rfid_reader_swig_doc.i"

%{
#include "rfid_reader/reader.h"
#include "rfid_reader/global_vars.h"
#include "rfid_reader/gate.h"
%}


%include "rfid_reader/reader.h"
GR_SWIG_BLOCK_MAGIC2(rfid_reader, reader);
%include "rfid_reader/global_vars.h"
%include "rfid_reader/gate.h"
GR_SWIG_BLOCK_MAGIC2(rfid_reader, gate);

#!/bin/sh
export VOLK_GENERIC=1
export GR_DONT_LOAD_PREFS=1
export srcdir=/home/jiawei/gr-rfid_reader/lib
export PATH=/home/jiawei/gr-rfid_reader/cmake-build-debug/lib:$PATH
export LD_LIBRARY_PATH=/home/jiawei/gr-rfid_reader/cmake-build-debug/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-rfid_reader 

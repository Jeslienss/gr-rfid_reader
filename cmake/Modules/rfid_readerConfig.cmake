INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_RFID_READER rfid_reader)

FIND_PATH(
    RFID_READER_INCLUDE_DIRS
    NAMES rfid_reader/api.h
    HINTS $ENV{RFID_READER_DIR}/include
        ${PC_RFID_READER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    RFID_READER_LIBRARIES
    NAMES gnuradio-rfid_reader
    HINTS $ENV{RFID_READER_DIR}/lib
        ${PC_RFID_READER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(RFID_READER DEFAULT_MSG RFID_READER_LIBRARIES RFID_READER_INCLUDE_DIRS)
MARK_AS_ADVANCED(RFID_READER_LIBRARIES RFID_READER_INCLUDE_DIRS)


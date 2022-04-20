set(FIND_LOGLIB_PATHS
        /home/s3ba/Desktop/logging-library/logging-library/LogLib)

find_path(LOGLIB_INCLUDE_DIR Logger.h
        PATH_SUFFIXES include
        PATHS ${FIND_LOGLIB_PATHS})

find_library(LOGLIB_LIBRARY
        NAMES loglib
        PATH_SUFFIXES lib
        PATHS ${FIND_LOGLIB_PATHS})
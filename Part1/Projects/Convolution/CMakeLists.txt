CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(Convolution C)

SET(EXEC_TARGET conv)

SET(CMAKE_C_STANDARD 11)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)

SET(HEADERS 
    ./include/array/common.h
    ./include/array/float32.h
    ./include/array/int16.h
    ./include/array/uint8.h
    ./include/convolve.h
    ./include/types.h)

SET(SOURCES 
    ./source/array/common.c
    ./source/array/float32.c
    ./source/array/int16.c
    ./source/array/uint8.c
    ./source/convolve.c
    ./source/main.c)

ADD_EXECUTABLE(${EXEC_TARGET} ${SOURCES} ${HEADERS})
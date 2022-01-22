cmake_minimum_required(VERSION 3.13)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# CMake Modules Path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Clone Sub-Modules
execute_process(COMMAND git submodule sync
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
execute_process(COMMAND git submodule update --init
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

include(${CMAKE_CURRENT_LIST_DIR}/lib/pico-sdk/pico_sdk_init.cmake)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/pico-examples)

## Project Name ##
project(CS466 ASM C CXX)

# C/C++ Standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

## Pico SDK ##
message(STATUS "Initialize the SDK")
pico_sdk_init()
message(STATUS "Initialize complete")

## FreeRTOS Kernel Config ##
# Include the FreeRTOS kernel and configure it for the ARM M0 port.
set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS-Kernel)
set(FREERTOS_KERNEL_PORT ARM_CM0)
set(FREERTOS_KERNEL_CONFIG ${CMAKE_CURRENT_LIST_DIR}/config)
set(FREERTOS_KERNEL_HEAP_FILE heap_3)
include(FreeRTOS-Kernel)

add_compile_options(
    -Wall
    -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
    -Wno-unused-function # we have some for the docs that aren't called
    -Wno-maybe-uninitialized
)

add_subdirectory(lab1)
add_subdirectory(lab2)

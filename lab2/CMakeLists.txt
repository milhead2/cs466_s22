cmake_minimum_required(VERSION 3.13)

# create target and add source files.
add_executable(lab2
    lab2.c
)

# pull in common dependencies
target_link_libraries(lab2
    pico_stdlib
    FreeRTOS-Kernel
)

# create map/bin/hex file etc.
pico_add_extra_outputs(lab2)

# add url via pico_set_program_url
# example_auto_set_url(blink)

cmake_minimum_required(VERSION 3.13)

# create target and add source files.
add_executable(lab1
    lab1.c
)

# pull in common dependencies
target_link_libraries(lab1
    pico_stdlib
)

# create map/bin/hex file etc.
pico_add_extra_outputs(lab1)

# add url via pico_set_program_url
# example_auto_set_url(blink)

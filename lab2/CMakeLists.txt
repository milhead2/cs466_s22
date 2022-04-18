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

# tell the pico library that you will be using usb serial and not an actual uart on the 
# processor
pico_enable_stdio_usb(lab2 1)
pico_enable_stdio_uart(lab2 0)


# create map/bin/hex file etc.
pico_add_extra_outputs(lab2)

add_custom_command(TARGET lab2 POST_BUILD COMMAND arm-none-eabi-size lab2.elf)

# add url via pico_set_program_url
# example_auto_set_url(blink)

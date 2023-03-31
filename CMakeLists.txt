cmake_minimum_required(VERSION 3.24)


# Pull in SDK (must be before project)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)


project(Encryption C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Initialize the SDK
pico_sdk_init()

add_executable(Encryption aes.c aes.h "serialrecieve_2.c")
target_include_directories(Encryption PRIVATE ${CMAKE_CURRENT_LIST_DIR})

# pull in common dependencies
target_link_libraries(Encryption pico_stdlib )

pico_enable_stdio_usb(Encryption 1)
pico_enable_stdio_uart(Encryption 0)
# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(Encryption)

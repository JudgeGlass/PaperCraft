cmake_minimum_required(VERSION 3.21)
project(PaperCraft)

set(CMAKE_CXX_STANDARD 17)
file(GLOB SRC_SOURCES src/*.cpp)
file(GLOB SRC_HEADERS src/*.h)
LINK_LIBRARIES(SDL2main SDL2 SDL2_image SDL2_mixer)
add_compile_options(-municode)
add_executable(PaperCraft ${SRC_SOURCES} ${SRC_HEADER})

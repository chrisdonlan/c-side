project(c-connectors)
cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

find_package(PkgConfig)
pkg_search_module(Tesseract REQUIRED IMPORTED_TARGET tesseract)
pkg_search_module(Leptonica REQUIRED IMPORTED_TARGET lept)

# Work around common Leptonica packaging bugs...
if (";${Leptonica_INCLUDE_DIRS};" MATCHES ";([^;]+)[/\\]leptonica[/\\]?;")
    target_include_directories(
        PkgConfig::Leptonica BEFORE INTERFACE "${CMAKE_MATCH_1}")
endif ()

add_executable(hello-world-cxx hello-world-cxx.cpp)
add_executable(ocr-memtest-cxx ocr-memtest-cxx.cpp)
add_executable(ocr-memtest-c ocr-memtest-c.c)

target_link_libraries(hello-world-cxx PRIVATE PkgConfig::Tesseract PkgConfig::Leptonica)
target_link_libraries(ocr-memtest-cxx PRIVATE PkgConfig::Tesseract PkgConfig::Leptonica)
target_link_libraries(ocr-memtest-c PRIVATE PkgConfig::Tesseract PkgConfig::Leptonica)

cmake_minimum_required(VERSION 3.22)
project(paragraph_searcher C)

set(CMAKE_C_STANDARD 11)

add_executable(paragraph_searcher main.c
        files.h
        files.c
        paragraph.c
        paragraph.h)

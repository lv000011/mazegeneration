cmake_minimum_required(VERSION 3.29)
project(mazegeneration)

set(CMAKE_CXX_STANDARD 20)

add_executable(mazegeneration
        main.cpp
        rbt.cpp
        rbt.h
        sqr.cpp
        sqr.h
        aba.cpp
        aba.h
        wll.cpp
        wll.h
        hka.cpp
        hka.h
        UnionFind.cpp
        UnionFind.h
        kru.cpp
        kru.h
        prm.cpp
        prm.h
        tst.cpp
        tst.h
)

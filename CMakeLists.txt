cmake_minimum_required(VERSION 3.17)
project(par_sys_exc2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fopenmp")
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/CMakeFiles/CPM.cmake")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")

##FIND_PACKAGE(OpenMP REQUIRED)
##if (OPENMP_FOUND)
    ##message("OPENMP FOUND")
    ##st(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_CXX_FLAGS}")
  ##  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
##endif ()
##set(GCC_COVERAGE_COMPILE_FLAGS " -Wall -pedantic -lm -O3 -funroll-loops -fopenmp")


add_executable(par_sys_exc2_v4

main.cpp
        CSVWriter.h
        fibocalc.h
)
target_link_libraries(
        par_sys_exc2_v4
        -static-libgcc -static-libstdc++


)

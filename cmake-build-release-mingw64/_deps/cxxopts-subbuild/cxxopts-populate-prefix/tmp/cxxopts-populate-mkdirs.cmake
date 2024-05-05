# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-src"
  "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-build"
  "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-subbuild/cxxopts-populate-prefix"
  "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-subbuild/cxxopts-populate-prefix/tmp"
  "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-subbuild/cxxopts-populate-prefix/src/cxxopts-populate-stamp"
  "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-subbuild/cxxopts-populate-prefix/src"
  "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-subbuild/cxxopts-populate-prefix/src/cxxopts-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-subbuild/cxxopts-populate-prefix/src/cxxopts-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Harry/CLionProjects/par_sys_exc2/cmake-build-release-mingw64/_deps/cxxopts-subbuild/cxxopts-populate-prefix/src/cxxopts-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

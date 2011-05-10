################################################################################
#          Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(bsppp)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
SET(SRC_DIRECTORY "${PROJECT_SOURCE_DIR}/src")

INCLUDE_DIRECTORIES( 
  "${PROJECT_SOURCE_DIR}/include/"
  "CMAKE_MODULE_PATH"
  )

# Find packages
INCLUDE(bsp.boost)
INCLUDE(bsp.mpi)

# Compiling sources
FILE( GLOB_RECURSE source_files
      ${SRC_DIRECTORY}/*
    )

# Generate the shared library.

ADD_LIBRARY(bsppp_omp STATIC ${source_files})
SET_TARGET_PROPERTIES(bsppp_omp PROPERTIES COMPILE_FLAGS "-DBSP_OMP_TARGET" )

ADD_LIBRARY(bsppp_mpi STATIC ${source_files})
SET_TARGET_PROPERTIES(bsppp_mpi PROPERTIES COMPILE_FLAGS "-DBSP_MPI_TARGET" )

ADD_LIBRARY(bsppp_hyb STATIC ${source_files})
SET_TARGET_PROPERTIES(bsppp_hyb PROPERTIES COMPILE_FLAGS "-DBSP_HYB_TARGET" )
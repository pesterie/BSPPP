################################################################################
#          Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(bsppp)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
SET(SRC_DIRECTORY "${PROJECT_SOURCE_DIR}/src")

SET(INCLUDE_INSTALL_DIR
    "${CMAKE_INSTALL_PREFIX}/include/bsppp"
    )

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

# Generate the shared and static libraries.

ADD_LIBRARY(bsppp_omp STATIC ${source_files})
SET_TARGET_PROPERTIES(bsppp_omp PROPERTIES COMPILE_FLAGS "-fopenmp -DBSP_OMP_TARGET" LINK_FLAGS "-fopenmp" )
TARGET_LINK_LIBRARIES(bsppp_omp ${Boost_PROGRAM_OPTIONS_LYBRARY} ${Boost_SERIALIZATION_LYBRARY})


ADD_LIBRARY(bsppp_omp_dyn SHARED ${source_files})
SET_TARGET_PROPERTIES(bsppp_omp_dyn PROPERTIES COMPILE_FLAGS "-fopenmp -DBSP_OMP_TARGET" LINK_FLAGS "-fopenmp" )
TARGET_LINK_LIBRARIES(bsppp_omp_dyn ${Boost_PROGRAM_OPTIONS_LYBRARY} ${Boost_SERIALIZATION_LYBRARY})
SET_TARGET_PROPERTIES(bsppp_omp_dyn PROPERTIES OUTPUT_NAME bsppp_omp)

ADD_LIBRARY(bsppp_mpi STATIC ${source_files})
SET_TARGET_PROPERTIES(bsppp_mpi PROPERTIES COMPILE_FLAGS "-DBSP_MPI_TARGET" )
TARGET_LINK_LIBRARIES(bsppp_mpi ${Boost_LIBRARIES} ${MPI_LIBRARY} ${MPI_EXTRA_LIBRARY})
ADD_LIBRARY(bsppp_mpi_dyn SHARED ${source_files})
SET_TARGET_PROPERTIES(bsppp_mpi_dyn PROPERTIES COMPILE_FLAGS "-DBSP_MPI_TARGET" )
TARGET_LINK_LIBRARIES(bsppp_mpi_dyn ${Boost_LIBRARIES} ${MPI_LIBRARY} ${MPI_EXTRA_LIBRARY})
SET_TARGET_PROPERTIES(bsppp_mpi_dyn PROPERTIES OUTPUT_NAME bsppp_mpi)

ADD_LIBRARY(bsppp_hyb STATIC ${source_files})
SET_TARGET_PROPERTIES(bsppp_hyb PROPERTIES COMPILE_FLAGS "-fopenmp -DBSP_HYB_TARGET" )
TARGET_LINK_LIBRARIES(bsppp_hyb ${Boost_LIBRARIES} ${MPI_LIBRARY} ${MPI_EXTRA_LIBRARY})
ADD_LIBRARY(bsppp_hyb_dyn SHARED ${source_files})
SET_TARGET_PROPERTIES(bsppp_hyb_dyn PROPERTIES COMPILE_FLAGS "-fopenmp -DBSP_HYB_TARGET" )
TARGET_LINK_LIBRARIES(bsppp_hyb_dyn ${Boost_LIBRARIES} ${MPI_LIBRARY} ${MPI_EXTRA_LIBRARY})
SET_TARGET_PROPERTIES(bsppp_hyb_dyn PROPERTIES OUTPUT_NAME bsppp_hyb)


# Examples for the 3 versions

ADD_CUSTOM_TARGET(examples)
ADD_DEPENDENCIES(examples examples_omp examples_mpi examples_hyb)
ADD_CUSTOM_TARGET(examples_omp)
ADD_CUSTOM_TARGET(examples_mpi)
ADD_CUSTOM_TARGET(examples_hyb)
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/examples EXCLUDE_FROM_ALL)

# Install bsppp

INSTALL( DIRECTORY ${PROJECT_SOURCE_DIR}/include/
         DESTINATION ${CMAKE_INSTALL_PREFIX}/include
         FILES_MATCHING
         PATTERN "*.hpp"
       )
INSTALL( TARGETS bsppp_omp bsppp_mpi bsppp_hyb bsppp_omp_dyn bsppp_mpi_dyn bsppp_hyb_dyn
         LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
	 ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/)



MESSAGE ( STATUS "
################################################################################

 BSPPP is now configured. 
 * If you use make or GNU make, you may run:
   - make all to build the static and shared library 
   - make install to install the compiled binary and library headers on your 
     system
   - make bsppp_omp build only the OpenMP version of the library
     make bsppp_mpi build only the MPI version of the library
     make bsppp_hyb build only the hybrid version of the library
   - make examples will build all the examples
     make examples_omp/mpi/hyb to build the examples dedicated to one version

################################################################################
        ")

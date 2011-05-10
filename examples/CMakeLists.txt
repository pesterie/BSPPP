################################################################################
#          Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include/")

################################################################################
# Examples for Hybrid
################################################################################
SET(SOURCES_HYB
    #gmm.cpp
    #hello.cpp
    inprod.cpp
    #psrs.cpp
    #psrs_hyb.cpp
    )

################################################################################
# For each filename
################################################################################
FOREACH( SRC ${SOURCES_HYB})
  ##**************************************************************************
  ## Build the executable filename from the example source filename
  ##**************************************************************************
  STRING(REGEX REPLACE ".cpp" ".example_hyb" EXECUTABLE "${SRC}")

  ##**************************************************************************
  ## Add as a target
  ##**************************************************************************
  ADD_EXECUTABLE(${EXECUTABLE} ${SRC})
  SET_TARGET_PROPERTIES(${EXECUTABLE} PROPERTIES COMPILE_FLAGS "-fopenmp -DBSP_HYB_TARGET" LINK_FLAGS "-fopenmp")
  TARGET_LINK_LIBRARIES(${EXECUTABLE} bsppp_hyb)
  ADD_DEPENDENCIES(examples_hyb bsppp_hyb ${EXECUTABLE})
ENDFOREACH()


################################################################################
# Examples for MPI
################################################################################
SET(SOURCES_MPI
    #gmm.cpp
    #hello.cpp
    inprod.cpp
    #psrs.cpp
    #psrs_hyb.cpp
    )

################################################################################
# For each filename
################################################################################
FOREACH( SRC ${SOURCES_MPI})
  ##**************************************************************************
  ## Build the executable filename from the example source filename
  ##**************************************************************************
  STRING(REGEX REPLACE ".cpp" ".example_mpi" EXECUTABLE "${SRC}")

  ##**************************************************************************
  ## Add as a target
  ##**************************************************************************
  ADD_EXECUTABLE(${EXECUTABLE} ${SRC})
  SET_TARGET_PROPERTIES(${EXECUTABLE} PROPERTIES COMPILE_FLAGS "-DBSP_MPI_TARGET" )
  TARGET_LINK_LIBRARIES(${EXECUTABLE} bsppp_mpi)
  ADD_DEPENDENCIES(examples_mpi bsppp_mpi ${EXECUTABLE})
ENDFOREACH()

################################################################################
# Examples for OMP
################################################################################
SET(SOURCES_OMP
    #gmm.cpp
    #hello.cpp
    inprod.cpp
    #psrs.cpp
    #psrs_hyb.cpp
    )

################################################################################
# For each filename
################################################################################
FOREACH( SRC ${SOURCES_OMP})
  ##**************************************************************************
  ## Build the executable filename from the example source filename
  ##**************************************************************************
  STRING(REGEX REPLACE ".cpp" ".example_omp" EXECUTABLE "${SRC}")

  ##**************************************************************************
  ## Add as a target
  ##**************************************************************************
  ADD_EXECUTABLE(${EXECUTABLE} ${SRC})
  SET_TARGET_PROPERTIES(${EXECUTABLE} PROPERTIES COMPILE_FLAGS "-fopenmp -DBSP_OMP_TARGET" LINK_FLAGS "-fopenmp" )
  TARGET_LINK_LIBRARIES(${EXECUTABLE} bsppp_omp)
  ADD_DEPENDENCIES(examples_omp bsppp_omp ${EXECUTABLE})
ENDFOREACH()
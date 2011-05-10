################################################################################
#          Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
INCLUDE(FindMPI)
FIND_PACKAGE(MPI)

IF(MPI_FOUND)
 SET(BSP_HAS_MPI TRUE)
 LINK_DIRECTORIES(${MPI_LIBRARY})
 INCLUDE_DIRECTORIES(${MPI_INCLUDE_PATH})
ELSE()
 SET(BSP_HAS_MPI FALSE)
ENDIF()

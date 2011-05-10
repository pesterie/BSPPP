################################################################################
#          Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET(Boost_ADDITIONAL_VERSIONS "1.43" "1.43.0")
INCLUDE(FindBoost)
FIND_PACKAGE( Boost 1.43.0 REQUIRED serialization mpi program_options )

IF(Boost_FOUND)
 SET(BSP_HAS_BOOST TRUE)
 LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
 INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
ELSE()
 SET(BSP_HAS_BOOST FALSE)
ENDIF()

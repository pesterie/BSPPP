/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_SYNC_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_SYNC_HPP_INCLUDED

#if defined (BSP_MPI_TARGET) || defined(BSP_HYB_TARGET)
#include <bsppp/details/primitives/sync/mpi.hpp>
#endif
#if defined (BSP_OMP_TARGET) || defined(BSP_HYB_TARGET)
#include <bsppp/details/primitives/sync/omp.hpp>
#endif
#include <bsppp/details/primitives/sync/gpu.hpp>

#endif

/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_ENVIRONMENT_HPP_INCLUDED
#define BSPPP_DETAILS_ENVIRONMENT_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Parallel environnement headers:
// When compiling a BSP++ programm, user must specify the parallel target on
// which the program has to be run.
////////////////////////////////////////////////////////////////////////////////

#include <bsppp/details/env/gpu.hpp>

#if defined (BSP_MPI_TARGET) || defined(BSP_HYB_TARGET)
#include <bsppp/details/env/mpi.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    struct environment
    {
       environment(int argc,char** argv)  { runtime::startup(argc,argv);  }
      ~environment()                      { runtime::shutdown();          }
    };
  }
}
}

#endif
#if defined (BSP_OMP_TARGET) || defined(BSP_HYB_TARGET)
#include <bsppp/details/env/omp.hpp>

namespace OMP
{
namespace bsp
{
  namespace details
  {

     struct environment
     {
       environment(int argc,char** argv)  { runtime::startup(argc,argv);  }
      ~environment()                      { runtime::shutdown();          }
     };

  }
}
}

#endif
#endif

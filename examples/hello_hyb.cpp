/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <iostream>
#include <bsppp/bsppp.hpp>

using namespace std;
namespace bl = boost::lambda;

void fun_omp(int argc, char** argv, int mpi_pid)
{
  BSP_HYB_START(argc,argv)
    {
      int omp_pid= pid();
      int omp_size=size();
      
      cout<<"I'm thread rank "<<omp_pid<<" of MPI process rank "<<mpi_pid<<endl;
    }
  BSP_HYB_END()
}

int bsp_main(int argc, char** argv)
{
  fun_omp(argc, argv, pid());
  
  return 0;
}

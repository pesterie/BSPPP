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

int bsp_main(int argc, char** argv)
{
  par<int> a;
  a=pid()*3;
  
  cout<<"I m process rank "<<pid()<<" of "<<size()<<"my local value of a is "<<*a<<endl;
  
  return 0;
}


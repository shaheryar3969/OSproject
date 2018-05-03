# OSproject
This is a university research based project.
It is about implementing sorting algorithms with different multithreading APIs,
and then compare which API give the best running time oneach algorithim.

#APIs used
-> Pthreads
   -Pthreads are defined as a set of C language programming types and procedure calls,
   implemented with a pthread.h header/include file and a thread library -though this
   library may be part of another library, such as libc,
   in some implementations. 
   -For Pthreads there is no intermediate memory copy required because threads share the
   same address space within a single process. There is no data transfer, per se. 
   It can be as efficient as simply passing a pointer. 

-> OpenMP
   -Used for multi-threaded parallel processing
   -Used on shared-memory multi-processor (core) computers
   -Part of program is a single thread and part is multi-threaded
   -Has 3 components
      -directives that can be put into C/C++ or Fortran programs
      -runtime library for setting and querying parallel parameters (ex. # of threads)
      -environment variables that define runtime parallel parameters (ex. # of threads)

#Algorithims used
1- Insertion sort
2- Merge sort
3- Radix sort

#Team members
1- Sanif Ali Momin
2- Syed Shaheryar Ali
3- Qaiser Hassan

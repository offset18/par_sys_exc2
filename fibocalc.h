//
// Created by wolfelias (https://github.com/wolfelias)
//



#ifndef PAR_SYS_EXC2_FIBOCALC_H
#define PAR_SYS_EXC2_FIBOCALC_H



#endif //PAR_SYS_EXC2_FIBOCALC_H

#include <omp.h>
#include <parallel/quicksort.h>

#include <stdio.h>
using namespace __gnu_parallel;





    long long parallel_fib(long long n, int num_threads) {
        int threads_left;
       if (threads_left == 1) {

           long long is, js;
           if (n < 2)
               return n;
           else {
               is = (n - 1);
               js = (n - 2);
               printf("Last long: %d is on thread %d\n", is + js, omp_get_thread_num());
               return is + js;
           }
       }

        if ((num_threads % 2) == 1)
            threads_left = num_threads / 2 + 1;
        else
            threads_left = num_threads / 2;


        printf("Num threads left: %d\n", threads_left);
        double start;
        double end;
        double exct;
        long long i, j;
        if (n < 2)
            return n;
        else {
            start = omp_get_wtime();
#pragma omp parallel sections num_threads(num_threads)
            {
#pragma omp section
                i = parallel_fib(n - 1, threads_left);
#pragma omp section
                j = parallel_fib(n - 2, threads_left);
#pragma omp section
                printf("Current long %d is on thread %d \n", i + j, omp_get_thread_num());
            }

            end = omp_get_wtime();
            exct = end - start;
          ;
            printf("Time taken is %f\n", exct);

        }

        return i + j;
    }


void printfib (long long n, int num_threads) {


                    printf("fib(%d) = %d\n", n, parallel_fib(n, num_threads));




        }



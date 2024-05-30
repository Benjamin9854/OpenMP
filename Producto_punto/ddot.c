/**
    @brief Sample program for cblas_ddot function
    @autor Julio José Águila Guerrero
    @date March 24th, 2022
*/
#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif
#ifndef ARRAY_H
    #include "array.h"
#endif
#include <cblas.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <sys/time.h>
#include <omp.h>

static int main_ddot(const int t, const CBLAS_INDEX n, const int elements_type, const char* verbose);

int main
(
    int argc,
    char** argv
)
{
    fprintf(stdout, "ddot: sample program for cblas_ddot function.\n");
    fputc('\n', stdout);
    if(argc != 5)
    {
        fprintf(stdout, "Use: ddot <t:int> <n:CBLAS_INDEX> <0|1|2> <on|off>.\n");
        return EXIT_FAILURE;
    }
    main_ddot(atoi(argv[1]), (CBLAS_INDEX)atoi(argv[2]), atoi(argv[3]), argv[4]);
    return EXIT_SUCCESS;
}

static int main_ddot
(
    const int t,
    const CBLAS_INDEX n,
    const int elements_type,
    const char* verbose
)
{
    double c = 0.0;
    double* x = NULL;
    double* y = NULL;
    CBLAS_INDEX incx = 1;
    CBLAS_INDEX incy = 1;
    struct timeval start, finish;
    double runtime = 0.0; // seconds.
    CBLAS_INDEX n_aux = 0;

    assert(n > 0);
    assert(elements_type >= ZEROS && elements_type <= RAND);
    x = array_new(n, 1, elements_type);
    assert(x != NULL);
    y = array_new(n, 1, elements_type);
    assert(y != NULL);
    n_aux = n / t;
    gettimeofday(&start, NULL);
    omp_set_num_threads(t);
    #pragma omp parallel reduction(+:c)
    {
        int p = omp_get_thread_num();
        c += cblas_ddot(n, x + n_aux * p, incx, y + n_aux * p, incy);
        fprintf(stdout, "Thread = %d, n_aux * p = %d\n", p, n_aux * p);
    }
    gettimeofday(&finish, NULL);
    if(strcmp(verbose, "on") == 0)
    {
        array_show(n, 1, x, "x");
        array_show(n, 1, y, "y");
    }
    fprintf(stdout, "c = %lf\n", c);
    runtime = timeval_diff(&finish, &start);
    fprintf(stdout, "Data: %d %lf\n", t, runtime);
    free(x);
    free(y);
    return EXIT_SUCCESS;
}
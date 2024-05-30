/**
    @brief Functions implementation for arrays: source file
    @author Julio José Águila Guerrero
    @date March 20th, 2021
*/
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef ARRAY_H
#include "array.h"
#endif
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>  // Incluir la cabecera de CBLAS para CBLAS_INDEX

double* array_new
(
    const CBLAS_INDEX m,
    const CBLAS_INDEX n,
    const int elements_type
)
{
    double* array = NULL;
    CBLAS_INDEX i = 0;
    assert(m > 0);
    assert(n > 0);
    assert(elements_type >= ZEROS && elements_type <= RAND);
    array = (double*)calloc(m * n, sizeof(double));
    assert(array != NULL);
    if(elements_type == ZEROS)
        for(i = 0; i < m * n; i++)
            array[i] = 0.0;
    else if(elements_type == ONES)
        for(i = 0; i < m * n; i++)
            array[i] = 1.0;
    else
    {
        srand(time(NULL));
        for(i = 0; i < m * n; i++)
            array[i] = (rand() % 10000) / 10000.0 - 0.5; // Range: [-0.5 - 0.5]
    }
    return array;
}

int array_show
(
    const CBLAS_INDEX m,
    const CBLAS_INDEX n,
    const double* array,
    const char* array_name
)
{
    CBLAS_INDEX i = 0;
    CBLAS_INDEX j = 0;
    assert(m > 0);
    assert(n > 0);
    assert(array != NULL);
    assert(array_name != NULL);
    fprintf(stdout, "%s=\n", array_name);
    if(m == 1)
    {
        for(j = 0; j < n && j < MAX_VERBOSE; j++)
            fprintf(stdout, "%7.4lf", array[j]);
        if(n > MAX_VERBOSE)
            fprintf(stdout, "%7d columns left", n - j);
        fputc('\n', stdout);
    }
    else if(n == 1)
    {
        for(i = 0; i < m && i < MAX_VERBOSE; i++)
            fprintf(stdout, "%7.4lf\n", array[i]);
        if(m > MAX_VERBOSE)
            fprintf(stdout, "%7d rows left\n", m - i);
    }
    else
    {
        for(i = 0; i < m && i < MAX_VERBOSE; i++)
        {
            for(j = 0; j < n && j < MAX_VERBOSE; j++)
                fprintf(stdout, "%7.4lf", array[n * i + j]);
            if(n > MAX_VERBOSE)
                fprintf(stdout, "%7d columns left", n - j);
            fputc('\n', stdout);
        }
        if(m > MAX_VERBOSE)
            fprintf(stdout, "%7d rows left\n", m - i);
    }
    fputc('\n', stdout);
    return EXIT_SUCCESS;
}

double timeval_diff(struct timeval *finish, struct timeval *start)
{
    return
    (double)(finish->tv_sec + (double)finish->tv_usec / 1000000) -
    (double)(start->tv_sec + (double)start->tv_usec / 1000000);
}
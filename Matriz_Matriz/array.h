/**
    @brief Functions implementation for arrays: header file
    @author Julio Jos&eacute; &Aacute;guila Guerrero
    @date March 20th, 2021
*/
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef ARRAY_H
#define ARRAY_H

#include <cblas.h>  // Incluir la cabecera de CBLAS para CBLAS_INDEX

#define ZEROS 0
#define ONES 1
#define RAND 2
#define MAX_VERBOSE 5
extern double* array_new(const CBLAS_INDEX m, const CBLAS_INDEX n, const int elements_type);
extern int array_show(const CBLAS_INDEX m, const CBLAS_INDEX n, const double* array, const char* array_name);
#include <sys/time.h>
extern double timeval_diff(struct timeval *finish, struct timeval *start);
#endif
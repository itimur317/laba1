#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
void* create_array(int*, int*);
void quick_sort(void**, int*, int*, int*);
void* concatenation(void**, int*, int*);
void map(void*, int*, int*, void(void*, int*));
void* where(void*, int*, int*, int(void*, int*));
void inc2(void*, int*);
int comparison(void*, int*);
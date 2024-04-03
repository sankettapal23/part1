#ifndef _ARRAY_H
#define _ARRAY_H
#include<stddef.h>

#define SUCCESS 1
#define INDEX_OUT_OF_RANGE 2

typedef int data_t;
typedef int status_t;
typedef long long s_size_t;
typedef s_size_t index_t;
typedef struct array array_t;


struct array 
{
    data_t* arr;
    s_size_t N;
};
array_t* create_array(s_size_t N);
void* xcalloc(size_t nr_elements,size_t size_per_element);
s_size_t size(array_t* p_arr);
status_t set(array_t* p_arr,index_t index,data_t data);
void show(array_t* p_arr,const char* msg);

#endif
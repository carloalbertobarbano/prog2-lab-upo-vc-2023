#ifndef _ARRAY_H
#define _ARRAY_H

void *create_array(size_t size, int n);  
void *expand_array(void *arr, size_t size, int n);
void delete_array(void *arr);

#endif
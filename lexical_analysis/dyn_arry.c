/*************************************************************************
	> File Name: dyn_arry.c
	> Author: 
	> Mail: 
	> Created Time: 2018年01月07日 星期日 16时30分54秒
 ************************************************************************/

#include<stdio.h>
#include"dyn_arry.h"




void dyn_arry_alloc(dyn_arry * start,int new_size){
    
    void * temp ;
    temp = (void *)malloc(sizeof(char) * new_size);
    memcpy(start->data,temp,start->count);
    free(start->data);
    start->data = temp;
    start->all_size = new_size;
    
    
}

void dyn_arry_add(dyn_arry * start,void *data){
    
    int count ;
    count = start->count + 1;
    if(count * sizeof(void *) > start->all_size){
        dyn_arry_alloc(start,count * sizeof(void*));
    }
    start->data[count-1] = data;
    start->count = count;

}



void dyn_arry_init(dyn_arry * start,int size){
    
    if(start != NULL){
        start->data = (void *)malloc(sizeof(void *) * size);
        start->count =  0;
        start->all_size = size;
    }
    
}


void dyn_arry_free(dyn_arry * start){
    
    void **temp;
    for(temp = start->data;start->count;++temp,--start->count){
        if(*temp){
            free(*temp);
        }
    }
    free(start->data);
    start->data = NULL;

}


int dyn_arry_search(dyn_arry * start, int key){
    
    int i ;
    int **p;
    p = (int **)start->data;
    for(i = 0; i < start->count;++i,p++){
        if(key == **p){
            return i;
        }
    }
    return -1;

}



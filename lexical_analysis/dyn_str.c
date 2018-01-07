/*************************************************************************
	> File Name: dyn_str.c
	> Author: 
	> Mail: 
	> Created Time: 2018年01月07日 星期日 15时29分46秒
 ************************************************************************/

#include<stdio.h>
#include"dyn_str.h"



void init_dyn_string(dyn_string * start ,int size ){       /*init string and  set all_size*/
    
    if(start != NULL){

        start = (dyn_string *)malloc(sizeof(char) * size);
        start->count = 0;
        start->all_size = size;
        start->data = NULL;
    }
}

void free_dyn_string(dyn_string * start){                  /*free dyn_string */
    
    if(start != NULL){
        free(start);
    }

}


void reset_dyn_string(dyn_string * start){              /*reset all dyn_string with SYN_STRING*/
    
        free_dyn_string(start);
        init_dyn_string(start,DYN_STRING);

}


void reset_dyn_string_size(dyn_string * start,int new_size){    /*reset all_size with new_size*/
    
        free_dyn_string(start);
        init_dyn_string(start,new_size);

}


void reset_dyn_string_alloc(dyn_string * start, int new_size){  /*realloc data size*/
    
    char * temp ;
    temp = (char *)malloc(sizeof(char) * new_size);
    memcpy(start->data,temp,start->count);
    free(start->data);
    start->data = temp;
    start->all_size = new_size;
    
}



void add_dyn_string(dyn_string * start,int ch){                 /* add  final char*/
    
        int count;
        count = start->count;
        count += 1;

        if(count > start->all_size){
            reset_dyn_string_alloc(start,count); 
        }

        start->data[count] = ch;
        start->count = count;
}





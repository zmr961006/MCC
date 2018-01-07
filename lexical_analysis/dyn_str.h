/*************************************************************************
	> File Name: dyn_str.h
	> Author: 
	> Mail: 
	> Created Time: 2018年01月07日 星期日 15时40分57秒
 ************************************************************************/

#ifndef _DYN_STR_H
#define _DYN_STR_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*dynmaic string for MCC */

#define DYN_STRING  16
#define MAX_SIZE    1024

typedef struct dyn_str{

        int count;     /*size of data*/
        int all_size;  /*size of buffer*/
        char * data;   /*start point of data*/

}dyn_string;


void init_dyn_string(dyn_string * start,int size);
void free_dyn_string(dyn_string * start);
void reset_dyn_string(dyn_string * start);
void reset_dyn_string_size(dyn_string * start,int new_size);
void add_dyn_string(dyn_string * start,int ch);
void reset_dyn_string_alloc(dyn_string * start,int new_size);


#endif

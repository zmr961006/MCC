/*************************************************************************
	> File Name: dyn_arry.h
	> Author: 
	> Mail: 
	> Created Time: 2018年01月07日 星期日 16时31分03秒
 ************************************************************************/

#ifndef _DYN_ARRY_H
#define _DYN_ARRY_H

#include<stdio.h>
#include<string.h>
#include<malloc.h>


/*dynamic ARRY for MCC*/

typedef struct dyn_arry{
    
    int count   ; /*size of dara */
    int all_size; /*size of dyn_arry */
    void **data ; /*data point */

}dyn_arry;

void dyn_arry_alloc(dyn_arry * start,int new_size); /*reset data*/
void dyn_arry_add(dyn_arry * start,void *data);/*realloc arry elem*/
void dyn_arry_init(dyn_arry * start,int size);/*init dyn_arry_init*/
void dyn_arry_free(dyn_arry * start);         /*free array elem*/
int dyn_arry_search(dyn_arry * start, int key); /*find key index*/













#endif

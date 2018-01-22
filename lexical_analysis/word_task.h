/*************************************************************************
	> File Name: word_task.h
	> Author: 
	> Mail: 
	> Created Time: 2018年01月22日 星期一 15时24分15秒
 ************************************************************************/

#ifndef _WORD_TASK_H
#define _WORD_TASK_H

#include<stdio.h>
#include<stdlib.h>
#include"hash.h"
#include"dyn_arry.h"
typedef struct wordtask {

    int word_code;
    struct wordtask *next;
    char *string_obj;
    //struct symbol *sym_struct;
    //struct symbol *sym_identifier;
}wordtask;


wordtask * wordtask_insert(wordtask * tw);

wordtask * wordtask_search(char *p,int keyno);

wordtask * wordtask_search_insert(char *p);

void * mallocz(int size);




#endif

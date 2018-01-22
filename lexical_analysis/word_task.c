/*************************************************************************
	> File Name: word_task.c
	> Author: 
	> Mail: 
	> Created Time: 2018年01月22日 星期一 15时23分50秒
 ************************************************************************/

#include<stdio.h>
#include"word_task.h"

wordtask * wt_hashtable[MAXKEY];   /*word hash table*/
dyn_arry wttable;                  /*word table*/


wordtask * wordtask_insert(wordtask * tw){

    int keyno;
    dyn_arry_add(&wttable,tw);
    keyno = elf_hash(tw->string_obj);
    tw->next = wt_hashtable[keyno];
    wt_hashtable[keyno] = tw;
    return tw;

}

wordtask * wordtask_search(char * p,int keyno){
    
    wordtask * temp = NULL;
    wordtask * temp1 = NULL;
    for(temp1 = wt_hashtable[keyno];temp1;temp1=temp1->next){
        if(!strcmp(p,temp1->string_obj)){
            //token = temp1->word_code;
            temp = temp1;
        }
    }
    return temp;

}


wordtask * wordtask_search_insert(char *p){
    
    wordtask * temp;
    int keyno;
    char *s;
    char *end;
    int length;

    keyno = elf_hash(p);
    temp = wordtask_search(p,keyno);
    if(temp == NULL){
        length = strlen(p);
        temp = (wordtask *)mallocz(sizeof(wordtask) + length + 1);
        temp->next = wt_hashtable[keyno];
        wt_hashtable[keyno] = temp;
        dyn_arry_add(&wttable,temp);
        temp->word_code = wttable.count -1;
        s = (char *)temp + sizeof(wordtask);
        temp->string_obj = (char *)s;
        for(end = p + length;p <end;){
            *s++ = *p++;
        }
        *s = (char *)'\0';
    }
    return temp;

}


void * mallocz(int size){
    
    void *ptr;
    ptr = malloc(size);
    if(!ptr && size){
        printf("alloc failed %d\n",__LINE__);
    }
    memset(ptr,0,size);
    return ptr;

}

void init_lex(){

	wordtable * temp;
        static wordtable keywords[]={
        	{TK_PLUS,NULL,"+",NULL,NULL},
		{TK_MINUS,NULL,"-",NULL,NULL},
		{TK_STAR,NULL,"*",NULL,NULL},
		{TK_DIVIDE,NULL,"/",NULL,NULL},
		{TK_MOD,NULL,"%",NULL,NULL},
		{TK_EQ,NULL,"==",NULL,NULL},
		{TK_NEQ,NULL,"!=",NULL,NULL},
		{TK_LT,NULL,"<",NULL,NULL},
		{TK_LEQ,NULL,"<=",NULL,NULL},
		{TK_GT,NULL,">",NULL,NULL},
		{TK_GEQ,NULL,">=",NULL,NULL},
		{TK_ASSIGN,NULL,"=",NULL,NULL},
		{TK_POINTSTO,NULL,"->",NULL,NULL},
		{TK_DOT,NULL,".",NULL,NULL},
		{TK_AND,NULL,"&",NULL,NULL},
		{TK_OPENPA,NULL,"(",NULL,NULL},
		{TK_CLOSEPA,NULL,")",NULL,NULL},
		{TK_OPENBR,NULL,"[",NULL,NULL},
		{TK_CLOSEBR,NULL,"]",NULL,NULL},
		{TK_BEGIN,NULL,"{",NULL,NULL},
		{TK_END,NULL,"}",NULL,NULL},
		{TK_SEMICOLON,NULL,";",NULL,NULL},
		{TK_COMMA,NULL,",",NULL,NULL},
		{TK_ELLIPSIS,NULL,"...",NULL,NULL},
		{TK_EOF,NULL,"End_Of_File",NULL,NULL},
		{TK_CINT,NULL,"intvar",NULL,NULL},
		{TK_CCHAR,NULL,"charvar",NULL,NULL},
		{TK_CSTR,NULL,"stringvar",NULL,NULL},
		{TK_CHAR,NULL,"char",NULL,NULL},
		{TK_SHORT,NULL,"short",NULL,NULL},
		{TK_INT,NULL,"int",NULL,NULL},
		{TK_VOID,NULL,"void",NULL,NULL},
		{TK_STRUCT,NULL,"struct",NULL,NULL},
		{TK_IF,NULL,"if",NULL,NULL},
		{TK_ELSE,NULL,"else",NULL,NULL},
		{TK_FOR,NULL,"for",NULL,NULL},
		{TK_CONTINUE,NULL,"continue",NULL,NULL},
		{TK_BREAK,NULL,"break",NULL,NULL},
		{TK_RETURN,NULL,"return",NULL,NULL},
		{TK_SIZEOF,NULL,"sizeof",NULL,NULL},
		{TK_ALIGN,NULL,"__align",NULL,NULL},
		{TK_CDECL,NULL,"__cdecl",NULL,NULL},
		{TK_STDCALL,NULL,"__stdcall",NULL,NULL},
		{TK_STDCALL,NULL,NULL,NULL,NULL},
		
        };

	dyn_arry_init(&wttable,8);
	for(temp = &keyword[0];temp->string_obj != NULL;temp++){
		wordtask_insert(temp);
	}

}





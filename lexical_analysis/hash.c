/*************************************************************************
	> File Name: hash.c
	> Author: 
	> Mail: 
	> Created Time: 2018年01月07日 星期日 17时30分49秒
 ************************************************************************/

#include<stdio.h>
#include"hash.h"

int elf_hash(char *key){

    int h =0,g;
    while(*key){
        h = (h << 4)+*key++;
        g = h & 0xf0000000;
        if(g){
            h ^= g >> 24;
        }
        h &= ~g;
    }
    return h % MAXKEY;
}


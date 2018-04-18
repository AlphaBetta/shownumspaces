/**
 * rch.c -- функция удаления символа справа от курсора
 *
 * Copyright (c) 2017, Ruslan Sergeev <sergeev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 


#include <ctype.h>
#include <string.h>
#include "_text.h"

void rch(text txt)
{
    char *current = txt->cursor->line->contents;
    int pos = txt->cursor->position;
    int i, len;
    len = strlen(current);
    
    if (current[pos] != '\n' && current[pos] != '\0'){
      for (i = pos; i <= len; i++){
	current[i] = current[i + 1];
      }
    } else {
      printf("Сannot delete character!\n"); 
        return;
    }
}

/**
 * shownumspaces.c -- функция для нахождения числа пробелов в строке
 *
 * Copyright (c) 2017, Ruslan Sergeev <sergeev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 


#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"

static void show_num_spaces(int index, char *contents);

void shownumspaces(text txt)
{
    process_forward(txt, show_num_spaces);
}

static void  show_num_spaces(int index, char *contents)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемый параметр */
    UNUSED(index);

    int kol = 0;
    int	i;


    for (i = 0; i <= (int)strlen(contents)-1; i++){
	if (contents[i] == ' ')
	    kol++;
    }
    printf("%d spaces\n", kol);
    
}



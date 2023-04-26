#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionnary.h"

#define MAX_WORD_SIZE 256

struct dictionnary_t{
    char **words;
    int size;
};

Dictionnary *dictionnary_init(char *filename){
    if(!filename)
        return NULL;
    
    FILE *f = fopen(filename, "r");
    if(!f)
        return NULL;

    Dictionnary *d = malloc(sizeof(Dictionnary));
    if(!d){
        fclose(f);
        return NULL;
    }

    char *dict_size = malloc(sizeof(char) * 4);
    if(!dict_size){
        fclose(f);
        free(d);
        return NULL;
    }

    fgets(dict_size, 4, f);
    d->size = atoi(dict_size);
    
    d->words = malloc(sizeof(char *) * d->size);
    if(!d->words){
        fclose(f);
        free(d);
        free(dict_size);
        return NULL;
    }

    for(int i = 0; i < d->size; i++){
        d->words[i] = malloc(sizeof(char) * MAX_WORD_SIZE);
        if(!d->words[i]){
            for(int j = 0; j < i; j++)
                free(d->words[j]);
            fclose(f);
            free(d);
            return NULL;
        }
        fscanf(f, "%s", d->words[i]);
    }

    fclose(f);
    free(dict_size);
    return d;
}

void dictionnary_free(Dictionnary *d){
    if(!d)
        return;
    
    for(int i = 0; i < d->size; i++)
        free(d->words[i]);
    free(d->words);
    free(d);
}

char *dictionnary_get_from_word(Dictionnary *dictionnary, char *key){
    if(!dictionnary || !key)
        return NULL;
    
    for(int i = 0; i < dictionnary->size; i++){
        if(strcmp(dictionnary->words[i], key) == 0)
            return dictionnary->words[i];
    }

    return NULL;
}

char *dictionnary_get_from_index(Dictionnary *dictionnary, int index){
    if(!dictionnary || index < 1 || index > dictionnary->size)
        return NULL;
    
    return dictionnary->words[index - 1];
}

int dictionnary_size(Dictionnary *dictionnary){
    if(!dictionnary)
        return -1;
    
    return dictionnary->size;
}
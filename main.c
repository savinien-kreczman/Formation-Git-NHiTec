/**
 * \file main.c
 * \author 
 * \brief 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dictionnary.h"
#include "print.h"

int main(int argc, char *argv[]){

    srand(time(NULL));

    char *filename = "dictionnary.txt";

    Dictionnary *d = dictionnary_init(filename);
    if(!d){
        printf("Erreur lors de l'initialisation du dictionnaire\n");
        return 1;
    }

    int index = (rand() % dictionnary_size(d)) + 1;

    print(dictionnary_get_from_index(d, index));

    dictionnary_free(d);

    return 0;
}
#ifndef __DICTIONNARY__
#define __DICTIONNARY__

typedef struct dictionnary_t Dictionnary;

Dictionnary *dictionnary_init(char *filename);
void dictionnary_free(Dictionnary *dictionnary);
char *dictionnary_get_from_word(Dictionnary *dictionnary, char *key);
char *dictionnary_get_from_index(Dictionnary *dictionnary, int index);
int dictionnary_size(Dictionnary *dictionnary);


#endif /* __DICTIONNARY__ */

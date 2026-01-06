/*traversal.c prepares the files for processing, it just opens the file and calls process_file() from text.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"

void processFile(const char *file_path,const char *search_word){
        FILE *fptr;
        if ((fptr=fopen(file_path,"r"))==NULL) {
        printf("error opening the file%s\n",file_path); return;
        }
fclose(fptr);
process_file(file_path, search_word);
}

/*this file reads the file contents and coverts the word to uppercase and updates the nbr of changes made. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "report.h"
void process_file(const char *file_path, const char *search_word){
        FILE *fptr=fopen(file_path,"r"); // open the file
        if (fptr==NULL){printf("error: cannot open file:%s\n", file_path); return;}

        fseek(fptr,0,SEEK_END);
        long size=ftell(fptr);
        rewind(fptr);

        char *buffer=malloc(size+1); // malloc is used here as we don't know the size of the file yet, so we create a memory space of +1 to make sure we have enough.
        if (buffer==NULL){printf("error:memory not allocated.\n"); fclose(fptr); return;}

        fread(buffer,1,size,fptr);
        buffer[size]='\0';
        fclose(fptr);
int change_count=0;
// here the word is converted to uppercase and the nbr of times we changed a word is updated
for(int i=0; buffer[i]!='\0';i++){
	if (strncasecmp(&buffer[i],search_word,strlen(search_word))==0){
		for(int j=0;j<strlen(search_word);j++){buffer[i+j]=toupper(buffer[i+j]);}
           i+=strlen(search_word)-1;
           change_count++;}
}
// now we need to change the files themselves
fptr=fopen(file_path,"w");
	if (fptr==NULL){printf("error in file:%s\n",file_path);free(buffer);return;}
fwrite(buffer,1,strlen(buffer),fptr);
fclose(fptr);
add_to_report(file_path, change_count);// update the report
free(buffer); // we then free the memory 
}


/*This file goes through the directory to find the .txt before processing them. It also contains "the apps starting function" (templace.c)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "traversal.h"
#include "report.h"
#include <dirent.h>
#define MAX_LINE 1024
#define MAX_FILENAME 256

int main(int argc, char *argv[]) {
struct dirent *pDirent;
DIR *pDir;
    if (argc != 2) {fprintf(stderr, "%s <search_word>\n", argv[0]); return 1;}
	pDir=opendir("."); // need to check if it successfully opened the directory
        if (pDir == NULL) {
	perror("Error opening directory");
		exit(EXIT_FAILURE);
        }
// The while loop reads and processes .txt files one at a time and skips the non .txt files.
while ((pDirent = readdir(pDir)) != NULL) {
        if (strstr(pDirent->d_name, ".txt") != NULL) {
            char file_path[MAX_FILENAME];
	snprintf(file_path, sizeof(file_path), "./%.*s", MAX_FILENAME - 3, pDirent->d_name);
            processFile(file_path, argv[1]);
        }
    }
closedir(pDir); // close directory
print_report();
cleanReport();
//return 0;
printf("Thanks for using this program");
return EXIT_SUCCESS;
}

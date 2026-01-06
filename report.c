/*report.c stores and displays how many changes occured in the file.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "report.h"

#define MAX_FILES 100
#define MAX_FILENAME 100

typedef struct {
    char file_path[MAX_FILENAME];
    int changes;
} ReportEntry;

ReportEntry entries[MAX_FILES];
int count=0;

void add_to_report(const char *file_path, int change_count){
    if (change_count == 0) return; 
    if (count < MAX_FILES) {
        strncpy(entries[count].file_path, file_path, MAX_FILENAME);
        entries[count].file_path[MAX_FILENAME - 1] = '\0'; 
        entries[count].changes = change_count;
        count++;
    } else {
        printf("Warning: report full, cannot add more files\n");
    }
}

// helper function
int compare(const void *a, const void *b) {
    ReportEntry *entryA = (ReportEntry *)a;
    ReportEntry *entryB = (ReportEntry *)b;
	if ((entryA->changes)>(entryB->changes)){return -1;}
	else if ((entryA->changes)<(entryB->changes)){return 1;}
	else return 0; // equal
}
void print_report(void){
    printf("Showing the report\n");
    printf("Showing the files ordered/sorted by number of changes (most changes first):\n");
    qsort(entries, count, sizeof(ReportEntry), compare);
    for (int i = 0; i < count; i++){
        printf("%d %s\n", entries[i].changes, entries[i].file_path);
    }
}

void cleanReport(){
count=0;
}



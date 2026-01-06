#ifndef REPORT_H
#define REPORT_H
void initialize_report(void);
void add_to_report(const char *file_path, int change_count);
void print_report(void);
void cleanReport(void);
#endif

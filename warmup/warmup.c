#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "include/warmup_solver.h"

const char WARMUP_INSTANCE[] = "01-tecla-king/";
const char INPUT_DIR[] = "input/";
const char FILE_PREFIX[] = "instance_";

int main() {

    DIR *dir;
    FILE *fptr;
    int success, total_success, total_failures;
    struct dirent *str_dir;
    char input_dir[100], file_path[100];

    input_dir[0] = '\0';
    strcat(input_dir, WARMUP_INSTANCE);
    strcat(input_dir, INPUT_DIR);

    dir = opendir(input_dir);

    if (dir) {

        int prefix_length = strlen(FILE_PREFIX);
        total_success = total_failures = 0;

        while ((str_dir  = readdir(dir)) != NULL) {

            if (strncmp(str_dir->d_name, FILE_PREFIX, prefix_length)) {
                continue;
            }

            file_path[0] = '\0';
            strcat(file_path, WARMUP_INSTANCE);
            strcat(file_path, INPUT_DIR);
            strcat(file_path, str_dir->d_name);

            fptr = fopen(file_path, "r");
            if (fptr == NULL) {
                printf("File '%s' can't be opened\n", file_path);
                return 1;
            }

            solve_warmup(fptr, str_dir->d_name, WARMUP_INSTANCE);
            success = check_warmup_solution(str_dir->d_name, WARMUP_INSTANCE);

            printf("Test %s %s.\n", str_dir->d_name, success ? "SUCCESS" : "FAILURE");

            if (success) {
                total_success++;
            } else {
                total_failures++;
            }

            fclose(fptr);
        }

        printf("Total Success: %d\nTotal Failures: %d\n", total_success, total_failures);

        closedir(dir);
    }

    return 0;
}

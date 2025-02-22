#ifndef WARMUP_SOLVER_H
#define WARMUP_SOLVER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance);

int check_warmup_solution(const char* file_name, const char* warmup_instance);

#endif // WARMUP_SOLVER_H
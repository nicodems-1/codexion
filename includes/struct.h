#ifndef __STRUCT_H
# define __STRUCT_H

#define ERROR 0
#define SUCCESS 1
#include <string.h>
#include <limits.h>
#include <stdlib.h>
typedef struct s_param {
    int numbers_of_coders;
    int time_to_burnout;
    int time_to_compile;
    int time_to_debug;
    int time_to_refactor;
    int numbers_of_compiles_required;
    int dongle_cooldown;
    int scheduler;
} t_param;

int is_number(char *str);
int is_digit(char c);

#endif
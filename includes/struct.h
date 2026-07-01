#ifndef __STRUCT_H
# define __STRUCT_H

#define ERROR 0
#define SUCCESS 1
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


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

typedef struct s_dongle
{
    pthread_mutex_t left_dongle;
    pthread_mutex_t  right_dongle;

} t_dongle;

typedef struct s_coder 
{
    int last_compiled;
    int times_compiled;
    pthread_t thread_id; //pthread create will create on his own the thread id so no need to assign manually
    t_param *rules; //should contain the param_struct pointer for each and every coder
} t_coder;


int is_number(char *str);
int is_digit(char c);
int parsing(int ac, char **av, t_param *p);
void create_coders(const t_param *p);

#endif
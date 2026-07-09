#ifndef STRUCT_H
# define STRUCT_H

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdbool.h>

typedef enum flags
{
    BURNOUT,
    CONTINUING,
    SUCCESS,
};

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
    pthread_mutex_t mutex;
    long long   time_released;
} t_dongle;

typedef struct s_coder 
{
    long long last_compiled;
    int nb_of_compilation;
    pthread_t thread_id;
    int id;
    t_param *rules;
    t_data *data;
    int *end_init;
    pthread_mutex_t health_coder;

    t_dongle *left_dongle;
    t_dongle *right_dongle;
} t_coder;

typedef struct s_data
{
    int start_time;
    int simulation_status;
    pthread_mutex_t status_mutex;
    pthread_mutex_t print_mutex;
    t_coder *coder_array;
} t_data;

int lauch_simulation(void);
int is_number(char *str);
int is_digit(char c);
int parsing(int ac, char **av, t_param *p);
void create_coders(const t_param *p, t_data data);
void    print_parsed(const t_param *p);
long long convert_ms_to_micros(long long microsecond);
long long actual_time_ms(void);
long long convert_micros_to_ms(long long ms);
int ft_usleep(t_data *data, long long time_to_sleep);
int check_status(t_data *data);
ft_strncmp(char *str1, char *str2, int len);
void    print_log(t_data *data, int id, char *action);
#endif
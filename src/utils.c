#include "../includes/struct.h"

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_number(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if (is_digit(str[i]) == 0)
            return(0);
        i++;
    }
    return(1);
}

long long convert_ms_to_micros(long long microsecond)
{
    return (microsecond * 1000);
}

long long convert_micros_to_ms(long long milisecond)
{
    return (milisecond / 1000);
}

unsigned long actual_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return(((tv.tv_sec)*1000) + (tv.tv_usec/1000));
}

void    print_parsed(const t_param *p)
{
        printf("\n");
    printf("********************************\n");
    printf("NUMBER OF CODER = %d\n", p->numbers_of_coders);
    printf("Time to burnout = %d\n", p->time_to_burnout);
    printf("Time to compile = %d\n", p->time_to_compile);
    printf("Time_to_debug= %d\n", p->time_to_debug);
    printf("number_of_compiles_required = %d\n", p->numbers_of_compiles_required);
    printf("dongle_cooldown = %d\n", p->dongle_cooldown);
    printf("Time_to_refactor=%d\n", p->time_to_refactor);
    printf("scheduler = %d\n", p->scheduler);
    printf("********************************\n\n");
    return;
}

void    garbage_collector()
{
    
}
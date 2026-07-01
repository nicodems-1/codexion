#include <stdio.h>
#include <string.h>
#include "../includes/struct.h"

int *check_int_max(char **str)
{
    int i;
    i = 1;
    int *array_int;
    array_int = malloc(sizeof(int)*8);
    int number;
    while(str[i])
    {
        number = atoi(str[i]);
        if (number < 0)
            array_int[i-1] = -1;
        else 
            array_int[i-1] = number;
        i++;
    }
    return array_int;
}

int update_struct(int ac, char **av, t_param *p)
{
    int *parsed;
    parsed = check_int_max(av);
    int i;
    i = 0;
    while(i < 8)
    {
        if(parsed[i] < 0)
        {
        printf("%s", "Wrong Input, negatives integers ");
        printf("%s\n", "or integers bigger than INT MAX are not allowed");
        return ERROR;
        }
        i++;
    }
    p->numbers_of_coders = parsed[0];
    p->time_to_burnout = parsed[1];
    p->time_to_compile = parsed[2];
    p->time_to_debug = parsed[3];
    p->time_to_refactor = parsed[4];
    p->numbers_of_compiles_required = parsed[5];
    p->dongle_cooldown = parsed[6];
    p->scheduler = parsed[7];
}

int check_number(int ac, char **av)
{
    int i = 1;
    while (i != ac)
    {
        if (is_number(av[i]) == 0)
            return ERROR;
        i++;
    }
    return(1);
}

int parsing(int ac, char **av, t_param *p)
{
    if (ac != 9)
    {
        printf("ERROR");
        return ERROR;
    }
    if (check_number(ac, av) == 0)
    {
        printf("%s", "provide digit between 0 to 9, others inputs are forbidden");
        return(ERROR);
    }
    update_struct(ac, av, p);
    return SUCCESS;
}
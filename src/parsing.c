#include <stdio.h>
#include <string.h>
#include "../includes/struct.h"

int *check_int_max(char **str)
{
    printf("%s\n", "check_int_max");
    int i;
    i = 1;
    int *array_int;
    array_int = malloc(sizeof(int)*7);
    size_t number;

    while(str[i])
    {
        printf("to be converted aka string: %s\n", str[i]);
        number = atoi(str[i]);
        if (number > INT_MAX)
            array_int[i-1] = -1;
        array_int[i-1] = (int)(number);
        i++;
    }
    i = 0;
    while(i < 8)
    {
        printf("ARRAY_INTEGER %d\n", array_int[i]);
        i++;
    }
    return array_int;
}

int update_struct(int ac, char **av, t_param p)
{
    printf("%s\n", "Update struct");
    int *parsed;
    *parsed = check_int_max;
    int i;
    i = 0;
    while(parsed[++i])
        if(parsed[i] < 0)
        {
            printf("%s\n", "NOOOOOPEEEEEE");
            return ERROR;
        }
    parsed = check_int_max(av);
    p.numbers_of_coders = parsed[0];
    p.time_to_burnout = parsed[1];
    p.time_to_compile = parsed[2];
    p.time_to_debug = parsed[3];
    p.time_to_refactor = parsed[4];
    p.numbers_of_compiles_required = parsed[5];
    p.dongle_cooldown = parsed[6];
    p.scheduler = parsed[7];
}

int parsing(int ac, char **av)
{
    printf("%s\n", "PARSING");
    t_param p;
    int i = 1;
    while (i != ac)
    {
        if (is_number(av[i]) == 0)
            return ERROR;
        i++;
    }
    update_struct(ac, av, p);
    return(1);
}

int main(int ac, char **av)
{
    t_param p;
    if (ac != 9)
    {
        printf("ERROR");
        return ERROR;
    }
    if (parsing(ac, av) == 0)
        return(ERROR);
}
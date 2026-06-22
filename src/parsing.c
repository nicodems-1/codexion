#include <stdio.h>
#include <string.h>
#include "../includes/struct.h"

void    parsing(int ac, char **av)
{
    t_param p;

}

int main(int ac, char **av)
{
    parsing(ac, av);
    t_param el_data;
    el_data.numbers_of_coders = 3;
    printf("%d\n", el_data.numbers_of_coders);
}

//needing to verify parsed values are number
//if values are number, update the struct
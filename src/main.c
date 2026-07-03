#include "../includes/struct.h"

int main(int ac, char **av)
{
    t_param p;
    t_param value;
    parsing(ac, av, &p); //self explanatory (parsing)
    create_coders(&p); //create thread and join thread
    // lauch_simulation();
    return SUCCESS;
}
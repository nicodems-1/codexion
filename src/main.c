#include "../includes/struct.h"

int main(int ac, char **av)
{
    t_param p;
    t_data data;
    t_param value;
    data.start_time = actual_time_ms();
    parsing(ac, av, &p); //self explanatory (parsing)
    create_coders(&p, data); //create thread and join thread
    // lauch_simulation();
    return SUCCESS;
}
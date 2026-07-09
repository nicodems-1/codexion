#include "../includes/struct.h"


void *monitor(t_coder *coder_array)
{
    t_param p;
    int index;
    int finished;
    unsigned long time;
    unsigned long last_compiled;

    p = *coder_array[1].rules;
    while(1)
    {
        index = 0;
        finished = 0;
        while(index != p.numbers_of_coders)
        {
            pthread_mutex_lock(&coder_array[index].health_coder);
            last_compiled = coder_array[index].last_compiled;
            time = last_compiled - actual_time_ms();
            if (time > p.time_to_burnout)
            {
                coder_array[index].data->simulation_status = BURNOUT;
                pthread_mutex_unlock(&coder_array[index].health_coder);
                //exit dans une autre fonction nettoyage
            }
            if ((&coder_array[index].nb_of_compilation) == p.numbers_of_compiles_required)
                finished++;
            pthread_mutex_unlock(&coder_array[index].health_coder);
            index++;
        }
        if (finished == p.numbers_of_coders)
            coder_array[index].data->simulation_status = SUCCESS;
        usleep(1000);
        return NULL;
    }
}
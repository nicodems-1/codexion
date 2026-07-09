#include "../includes/struct.h"


void *codeur_routine(void *coder)
{ 
    return NULL;
}

void init_dongles(t_param *p, t_coder *coder_array, t_data data)
{
    int i;
    i = 0;
    t_dongle *dongle_array;
    dongle_array = malloc(sizeof(t_dongle) * p->numbers_of_coders);
    pthread_mutex_init(&data.status_mutex, NULL);
    while(i < p->numbers_of_coders)
    {
        coder_array[i].left_dongle = &dongle_array[(i % p->numbers_of_coders)];
        dongle_array->time_released = 0;
        coder_array[i].right_dongle = &dongle_array[((i + 1)% p->numbers_of_coders)];
        dongle_array->time_released = 0;
        pthread_mutex_init(&dongle_array[i].mutex, NULL);
        pthread_mutex_init(&coder_array[i].health_coder, NULL);
        i++;
    }
}

void create_coders(const t_param *p, t_data data)
{
    t_coder *coder_array;
    int i;
    int end;

    i = 0;
    coder_array = malloc(sizeof(t_coder)*p->numbers_of_coders);
    init_dongles(&p, coder_array, data);
    while(i < p->numbers_of_coders)
    {
        coder_array[i].id = i;
        pthread_create(&(coder_array[i].thread_id) , NULL, &codeur_routine, (void *)&coder_array[i]);
        i++;
    }
    i = 0;
    while( i < p->numbers_of_coders)
    {
        pthread_join(coder_array[i].thread_id, NULL);
        i++;
    }
    exit(0);
}


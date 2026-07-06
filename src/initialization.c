#include "../includes/struct.h"

//need to update the struct later so it will not be a global variable
pthread_mutex_t starting_race;
pthread_mutex_t finish_init_mutex;
pthread_cond_t finish_init;


void *routine(void *coder)
{ 

    pthread_mutex_lock(&starting_race);
    while (*((t_coder*)(coder))->end_init != 1)
    {
        pthread_cond_wait(&finish_init, &starting_race);
    }

    printf("%d , COOKING PIZZA\n", ((t_coder*)(coder))->id);
    pthread_mutex_unlock(&starting_race);
    if (((t_coder*)(coder))->id % 2 == 0)
        usleep(10000);
    
     pthread_mutex_lock(&starting_race);
    printf("PIZZA COOKED\n");
    pthread_mutex_unlock(&starting_race);
    return NULL;
}

void init_dongles(t_param *p, t_coder *coder_array)
{
    int i;
    i = 0;
    pthread_mutex_t *dongle_array;
    dongle_array = malloc(sizeof(pthread_mutex_t) * p->numbers_of_coders);
    while(i< p->numbers_of_coders)
    {
        coder_array[i].left_dongle = &dongle_array[(i % p->numbers_of_coders)];
        coder_array[i].right_dongle = &dongle_array[((i + 1)% p->numbers_of_coders)];
        pthread_mutex_init(&dongle_array[i], NULL);
        i++;
    }
}

void create_coders(const t_param *p)
{
    int end_init = 0;
    pthread_mutex_init(&starting_race, NULL);
    pthread_cond_init(&finish_init, NULL);
    t_coder c;
    int i;
    int *thread_array;
    t_coder *coder_array;
    int end;
    i = 0;
    coder_array = malloc(sizeof(t_coder)*p->numbers_of_coders);
    pthread_cond_init(&finish_init, NULL);
    init_dongles(&p, coder_array);
    while(i < p->numbers_of_coders)
    {
        coder_array[i].id = i;
        coder_array[i].end_init = &end_init;
        pthread_create(&(coder_array[i].thread_id) , NULL, &routine, (void *)&coder_array[i]);
        printf("YES CAMRAD\n");
        i++;
    }
    // pthread_mutex_lock(&starting_race);
    end_init = 1;
    // pthread_mutex_unlock(&starting_race);
    i = 0;
    pthread_cond_broadcast(&finish_init);
    while( i < thread_count)
    {
                pthread_join(coder_array[i].thread_id, NULL);
                i++;
    }
    pthread_mutex_unlock(&starting_race);
    exit(0);
}


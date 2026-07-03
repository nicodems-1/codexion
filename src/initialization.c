#include "../includes/struct.h"

//need to update the struct later so it will not be a global variable
pthread_mutex_t starting_race;
pthread_mutex_t finish_init_mutex;
pthread_cond_t finish_init;
int end_init = 0;

void* routine()
{
    pthread_mutex_lock(&starting_race);
    while (end_init == 0)
    {
        pthread_cond_wait(&finish_init, &starting_race);
    }
    printf("COOKING PIZZA\n");
    usleep(500000);
    printf("PIZZA COOKED\n");
    pthread_mutex_unlock(&starting_race);
    return NULL;
}

void create_coders(const t_param *p)
{
    pthread_mutex_init(&starting_race, NULL);
    pthread_cond_init(&finish_init, NULL);
    t_coder c;
    int i;
    int thread_count;
    int *thread_array;
    int *coder_array;

    // print(p);
    i = 0;
    thread_count = p->numbers_of_coders; //allocating enough room to store coders struct in an array, each struct contains threads init
    coder_array = malloc(sizeof(t_coder)*thread_count);
    pthread_cond_init(&finish_init, NULL);
    while(i < thread_count)
    {
        pthread_create(&coder_array[i], NULL, &routine, NULL);
        printf("YES CAMRAD\n");
        i++;
    }
    end_init = 1;
    i = 0;
    pthread_cond_broadcast(&finish_init);
    while( i <= thread_count)
    {
                pthread_join(coder_array[i], NULL);
                i++;
    }
    pthread_mutex_unlock(&starting_race);
    exit(0);
}


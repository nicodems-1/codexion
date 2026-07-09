#include <sys/time.h>
#include <stdio.h>

int main(void)
{
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);
    printf("%lu\n", tv.tv_sec);
    printf("%lu\n", tv.tv_usec);
    printf("total_time would be %lu\n", ((tv.tv_sec)*1000) + (tv.tv_usec/1000));
}
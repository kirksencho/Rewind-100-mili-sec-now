#include <stdio.h>
#include <sys/time.h>

/* Rewind 100mili sec program */

int main(void)
{
    struct timeval t0;

    gettimeofday(&t0, NULL);

    /* Display now time */
    printf("Now time: %dusec\n", t0.tv_sec, t0.tv_usec);

    if ( t0.tv_usec > 100000 ) {
        t0.tv_usec = t0.tv_usec - 100000;
    } else {
        t0.tv_sec = t0.tv_sec - 1;
        t0.tv_usec = t0.tv_usec + 900000;
    }

    settimeofday(&t0, NULL);

    /* Display after sub time */
    gettimeofday(&t0, NULL);
    printf("After sub 100mili seconds: %dsec %dusec\n", t0.tv_sec, t0.tv_usec);

    return 0;
}

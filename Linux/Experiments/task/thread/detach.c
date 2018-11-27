#include<stdio.h>   
#include <pthread.h>
#include <errno.h>

void threa ( void )
{
    int ret = 8;
    printf ("\n in thread\n");
    sleep ( 10 );
    printf("\n done sleeping \n");
    pthread_exit ( &ret );
}
int main(void) 
{
    pthread_t hf;
    int b;
    int *retval = &b;
    int a = -1;
    a = pthread_create ( &hf, NULL, &threa, NULL );
    printf ( "\n a = %d \n ", a );
    a = pthread_detach (hf);
    if ( a != 0 )
        printf ( "\n %d %s\n", a, strerror (a ));
    printf ( "\n a = %d \n ", a );
    printf ("\n done\n");
    pthread_join ( hf, ( void ** ) &retval );
    sleep ( 10 );
    //a = pthread_detach ( hf );

    if ( a != 0 )
        printf ( "\n %d %s\n", a, strerror (a ));

    printf ( "\n b = %d\n ", *retval );
    return 0;
}

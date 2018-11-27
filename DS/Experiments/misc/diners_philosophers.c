/************
 * Diner's philosophers problem
 *************/

#include <stdio.h> 
#include <stdbool.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <semaphore.h> 
#include <errno.h> 
#include <time.h> 
#include <pthread.h> 

#define  PHILOSOPHERS 9                     /*number of philosophers*/ 
#define  SHARED 0                           /*shared between threads*/ 
#define  BINARY 1                           /*binary semaphore initial value*/ 

static pthread_t th[PHILOSOPHERS];          /*array of philosophers using threads*/ 
static sem_t sem_fork[PHILOSOPHERS];        /*array of semaphore for each fork*/ 
time_t philosophers_time[PHILOSOPHERS];
static time_t start;

/*semaphore cleanup i.e., destrying semaphores*/ 
bool clean_sem (int index){
    while (index-- >= 0){
        if (-1 == sem_destroy (sem_fork + index))
            perror ("semaphore destroy");
    }
    return true;
}

/*semaphore creation for each fork*/ 
bool create_forks (void){
    int index = 0;
    int status = 0;
    while (index < PHILOSOPHERS){
        status = sem_init ( (sem_fork + index), SHARED, BINARY); 
        if (-1 == status){
            (index > 0) ? clean_sem (index) : true;
            return false;
        }
        index++;
    }
    return true;
}

/*eat routine for a philosopher*/
bool eat (int index){
    struct timespec wait_time = {.tv_sec = 1};
    int status = 0;
    status = sem_timedwait ((sem_fork + index), &wait_time);
    if (-1 == status)
        return false;
    status = sem_timedwait (sem_fork + ((index + 1) % PHILOSOPHERS), &wait_time);
    if (-1 == status){
        status = sem_post (sem_fork + index);
        if (-1 == status)
            perror ("sem_post failed\n");
        return false;
    }
    wait_time.tv_sec = (index + 1);
    printf ("\nPhilosopher %d eating \n", index + 1); 
    nanosleep (&wait_time, NULL);
    printf ("Philosopher %d done eating after %f\n", index + 1, difftime (time(philosophers_time + index), start)); 
    status = sem_post (sem_fork + index);
    if (-1 == status)
        perror ("sem_post failed\n");
    status = sem_post (sem_fork + ((index + 1) % PHILOSOPHERS));
    if (-1 == status)
        perror ("sem_post failed\n");
    return true;
}

bool think (int index){
    printf ("\n I'm (Philosopher %d) thinking \n", index + 1); 
    struct timespec think_time = {.tv_sec = 1};
    nanosleep (&think_time, NULL);
    return true;
}

/*philosopher routine*/
void *philosopher_routine (void *philosopher_addr){
    bool done_eating = false;
    int index = 0;
    index = ((pthread_t *)philosopher_addr - th); // sizeof (pthread_t );
    think (index);
    printf ("Philosopher %d is hungry \n ", index + 1); 
    while (!done_eating){
        done_eating = eat (index);
    }
    return NULL;
}


int main (void) {

    int status = 0;
    int index = 0;

    status = create_forks ();
    if (-1 == status){
        perror ("semaphore creation failed\n");
        return 0;
    }
    time (&start);
    while (index < PHILOSOPHERS){
        pthread_create (th + index, NULL, philosopher_routine, (th + index));
        pthread_detach (th[index]);
        index++;
    }
   pthread_exit (NULL); 
    return 0;
}

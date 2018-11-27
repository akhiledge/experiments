/*******
 *tcp server program
 * *********/
#include "header_tcp.h" 

void mySignal (int signum)
{
    int ret_val;
    ret_val = close (soc_fd);
    if(-1 == ret_val)
        err (ret_val, "%s\n", strerror (ret_val));
    //unlink (soc_fd);
    exit (1);
}

void *client(void *arg){

    int acc_fd = *((int *)arg);
    int ret_val;
    char *myRdBuf = NULL;
    char *myWrBuf = NULL;
    char *ret_Buf = NULL;

    myRdBuf = malloc (sizeof (char) * BUF_SIZE);
    if(NULL == myRdBuf)
        warn ( "%s\n", strerror ( (int)myRdBuf));

    myWrBuf = malloc (sizeof (char) * BUF_SIZE);
    if(NULL == myWrBuf)
        warn ( "%s\n", strerror ( (int)myWrBuf));
    ret_Buf = myWrBuf;

    while (0 != strcasecmp (myRdBuf, "tata")){
        ret_val = (int) read (acc_fd, myRdBuf, BUF_SIZE);//read
        if(-1 == ret_val)
            warn ( "%s\n", strerror (ret_val));
        printf ("Recv:");
        ret_val = fputs (myRdBuf, stdout);
        if(EOF == ret_val)
            warn ( "%s\n", strerror (ret_val));


        ret_Buf = fgets (ret_Buf, BUF_SIZE, stdin);
        if(NULL == ret_Buf)
            warn ( "%s\n", strerror ((int)ret_Buf));

        ret_val = (int) write (acc_fd, ret_Buf, strlen (ret_Buf));
        if(-1 == ret_val)
            warn ( "%s\n", strerror (ret_val));
    }

    free (myRdBuf);
    myRdBuf = NULL;
    free (myWrBuf);
    myWrBuf = NULL;

    ret_val = close (acc_fd);
    if(-1 == ret_val)
        err (ret_val, "%s\n", strerror (ret_val));

    return NULL;
}

int main (int arg_cnt, char **cmdArg) 
{
    int ret_val; //@ret_val: to store the return value of a function
    //struct sockaddr_in *myAddr = NULL;
    struct sockaddr_in myAddr ;
    
    myAddr.sin_family = AF_INET;
    myAddr.sin_port = htons ( atoi(*(cmdArg + 1)));
    //    myAddr.sin_port = htons ( 50003);
    myAddr.sin_addr.s_addr = INADDR_ANY;
    //    myAddr.sin_addr.s_addr = inet_addr("0.0.0.0");
    signal (SIGINT, mySignal);
    ret_val = socket (AF_INET, SOCK_STREAM, 0 );
    if (-1 == ret_val)
        err (ret_val, "%s\n", strerror (ret_val));
    soc_fd = ret_val;
    ret_val = bind (soc_fd, (struct sockaddr *)(&myAddr), (socklen_t) (sizeof (myAddr)));
    if(-1 == ret_val)
        //    perror ("bind");
        err (ret_val, "bind %s\n", strerror (ret_val));

    perror ("bind");
    ret_val = listen (soc_fd, 2);
    if(-1 == ret_val){
        warn ( "%s\n", strerror (ret_val));
    }

    perror ("listen");


    while (1){
        socklen_t size_myAddr = sizeof (myAddr);
        ret_val = accept (soc_fd, (struct sockaddr *)(&myAddr), &size_myAddr);
        perror ("accept");
        if(-1 == ret_val){
            warn ( "%s\n", strerror (ret_val));
            break;
        }
        ret_val = pthread_create (&th, NULL, client, &ret_val);
        if(-1 == ret_val)
            err (ret_val, "%s\n", strerror (ret_val));

        ret_val = pthread_detach (th);
        if(-1 == ret_val)
            err (ret_val, "%s\n", strerror (ret_val));
    }

    ret_val = close (soc_fd);
    if(-1 == ret_val)
        err (ret_val, "%s\n", strerror (ret_val));

    return 0;
}


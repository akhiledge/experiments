/*******
 *tcp client program
 * *********/
#include "header_tcp.h" 

void mySignal (int signum)
{
    int ret_val;
    ret_val = close (soc_fd);
    if(-1 == ret_val)
        err (ret_val, "%s\n", strerror (ret_val));
    //unlink (soc_fd);
    printf (" tata\n"); 
    exit (1);
}


int main (int arg_cnt, char **cmdArg) 
{
    int ret_val; //@ret_val: to store the return value of a function
    struct sockaddr_in myAddr;
    char *myRdBuf = NULL;
    char *myWrBuf = NULL;
    char *ret_Buf = NULL;

    myAddr.sin_family = AF_INET;
//    myAddr.sin_port = htons (23456);
    myAddr.sin_port = htons (atoi(*(cmdArg + 1)));
//    myAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    myAddr.sin_addr.s_addr = inet_addr("172.16.5.28");//in client

    signal (SIGINT, mySignal);
    ret_val = socket (AF_INET, SOCK_STREAM, 0 );
    if (-1 == ret_val)
        err (ret_val, "%s\n", strerror (ret_val));
    soc_fd = ret_val;
    while (1){    
    socklen_t size_myAddr = sizeof (myAddr);
    ret_val = connect (soc_fd, (struct sockaddr *)(&myAddr), sizeof(myAddr));
    perror ("connect");
    if(-1 == ret_val){
        warn ( "%s\n", strerror (ret_val));
    }

    myRdBuf = malloc (sizeof (char) * BUF_SIZE);
    if(NULL == myRdBuf)
        warn ( "%s\n", strerror ( (int)myRdBuf));
    myWrBuf = malloc (sizeof (char) * BUF_SIZE);
    if(NULL == myWrBuf)
        warn ( "%s\n", strerror ( (int)myWrBuf));
    ret_Buf = myWrBuf;

    while (0 != strcasecmp (myRdBuf, "tata")){
        printf (" enter"); 
        ret_Buf = fgets (ret_Buf, BUF_SIZE, stdin);
        if(NULL == ret_Buf)
            warn ( "%s\n", strerror ((int)ret_Buf));

        ret_val = (int) write (soc_fd, ret_Buf, strlen (ret_Buf));
        if(-1 == ret_val)
            warn ( "%s\n", strerror (ret_val));

        ret_val = (int) read (soc_fd, myRdBuf, BUF_SIZE);//read
        if(-1 == ret_val)
            warn ( "%s\n", strerror (ret_val));

        ret_val = fputs (myRdBuf, stdout);
        if(EOF == ret_val)
            warn ( "%s\n", strerror (ret_val));

    }

        free (myRdBuf);
        myRdBuf = NULL;
        free (myWrBuf);
        myWrBuf = NULL;
    }
    ret_val = close (soc_fd);
    if(-1 == ret_val)
        err (ret_val, "%s\n", strerror (ret_val));

    return 0;
}


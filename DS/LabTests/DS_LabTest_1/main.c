/****
 *
 * main file for the CHENNAI_MAIL
 *
 * */ 

#include "train.h" 

int main (int arg_cnt, char **cmdArg) {
    
    station *origin = NULL;
    int status;
    FILE *fp = NULL;
    int (*ret_int[4])();
    char *option = NULL;
    char *source = NULL;
    char *dest = NULL;

    ret_int[1] = &distance_btw_stn;
    ret_int[2] = &display;
    ret_int[3] = &time_btw_stn;

    origin = malloc (sizeof (station));
    fp = fopen ("chennaimail.txt", "r");
    if (NULL == fp){
        err ( (int)fp, "%s\n", strerror ( (int)fp));
    }

    status = get_traininfo (fp, origin);
//    status = ret_int[0](fp, origin);
    if (-1 == status){
        err ( status, "%s\n", strerror (status));
    }

    option = malloc (sizeof (char) * BUF_SIZE);
    source = malloc (sizeof (char) * BUF_SIZE);
    dest = malloc (sizeof (char) * BUF_SIZE);
    while (1){
        display (origin); 
        printf ("\n Enter an option\n ");
        printf ("1.Distance between stations\n2.Display table\n"); 
        printf ("3.Time btm stations\n4.Exit\n\n ");
        switch (atoi (fgets (option, BUF_SIZE, stdin))){
            case 1:{
                       puts ("Enter source");
                       fgets (source, BUF_SIZE, stdin);
                       puts ("Enter destination");
                       fgets (dest, BUF_SIZE, stdin);
                       status = (ret_int[1])(source, dest, origin);
                       if (0 <= status)
                           printf (" Distance is %d\n", status); 
                       else
                           printf (" Please enter a valid station info\n"); 
                       break;
                   }
            case 2:{
                       display (origin);
                       break;
                   }
            case 3:{
                       puts ("Enter source");
                       fgets (source, BUF_SIZE, stdin);
                       puts ("Enter destination");
                       fgets (dest, BUF_SIZE, stdin);
                       status = (ret_int[3])(source, dest, origin);
                       if ( -1 == status)
                           printf (" Please enter a valid station info"); 
                       else
                           printf("Time is %2d:%2d\n", (status/60), (status%60));
                       break;

                   }
            case 4:{
                       break;
                   }
            default:{
                        printf (" Please enter a valid option"); 
                    }
        }
    }

    return 0;
}

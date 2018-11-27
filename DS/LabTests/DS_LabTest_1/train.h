/***
 *
 *Header file for train info
 *
 * */

#ifndef _TRAIN_H
#define _TRAIN_H

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <strings.h> 
#include <err.h> 

/*@BUF_SIZE: buffer size to store input */
#define BUF_SIZE 17

#define CODE_SIZE 5
#define NUM_BUF 4
#define DAY_TO_MIN 1440
#define HR_TO_MIN 60
/*@Time:  structure to store time*/
typedef struct {
    int hr;
    int min;
}Time;

/*@station: structure to store train information at a station*/
typedef struct station{
    char *code;
    char *stn_name;
    Time arrival;
    Time departure;
    Time halt;
    int dist;
    int day;
    struct station *next;
//}*origin;
};

int get_traininfo (station *origin, FILE *fp);//get information of the train
int display (station *origin);
int distance_btw_stn (station *origin, const char *source, const char *dest);
int time_btw_stn (station *origin, char *source, char *dest);
int time_frm_origin (station *origin, char *source, char *dest);
#if 0
int get_traininfo (FILE *fp, station *origin);//get information of the train
int display (station *origin);
int distance_btw_stn (const char *source, const char *dest, station *origin);
int time_btw_stn (char *source, char *dest, station *origin);
int time_frm_origin (char *source, char *dest, station *origin);
#endif

#endif /* _TRAIN_H*/ 

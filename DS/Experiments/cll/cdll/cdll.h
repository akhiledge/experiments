/*this is cdll.h*/ 
#ifndef _CDLL_H
#define _CDLL_H_
struct node{
    char *name;
    int id;
    struct dob{
        int day;
        int mon;
        int year;
    }date;
};
#endif

/*****
 * header file for tcp server and client
 * *****/
#ifndef _HEADER_TCP_H
#define _HEADER_TCP_H

#include <stdio.h> 
#include <sys/types.h>
#include <sys/socket.h>  
#include <err.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <signal.h> 
#include <linux/in.h> 
#include <pthread.h> 
#define BUF_SIZE 1024
#define SERVER_IP "127.0.0.1"
int soc_fd;///@soc_fd: socket fd
int connect_fd;///@acc_fd: accept fd
pthread_t th;
#endif


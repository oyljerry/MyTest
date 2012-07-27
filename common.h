#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <curl/curl.h>
#include <pthread.h>

pthread_cond_t g_Cond;
pthread_mutex_t g_Locker;

void* threadFunc(void* param);

struct THREADINFO{
	unsigned int uUserID;
	char szURL[261];
	char szFile[261];
};

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

void myqsort(int* a, int i, int j);

#endif

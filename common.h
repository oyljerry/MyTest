#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <curl/curl.h>

FILE* fp;

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

#endif

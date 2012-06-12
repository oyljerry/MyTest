/*
 * mythread.c
 *
 *  Created on: Jun 7, 2012
 *      Author: admin
 */

#include "common.h"
#include "logger.h"
#include <errno.h>
#include <string.h>

void* threadFunc(void* param)
{
	pthread_mutex_lock(&g_Locker);

	LOG_INFO("enter threadFunc()");

	struct THREADINFO *pInfo = (struct THREADINFO*)param;
	unsigned int uUserID = pInfo->uUserID;
	char szURL[261] = {0};
	strncpy(szURL, pInfo->szURL, 260);
	char szFile[261] = {0};
	strncpy(szFile, pInfo->szFile, 260);

	printf("--- thread user id %u start, URL = %s, file = %s,  pthread id = %lu\n",
			uUserID, szURL, szFile, pthread_self());
	//LOG_INFO("--- thread %u start, pthread id = %u", *pId, pthread_self());

	pthread_cond_signal(&g_Cond);
	pthread_mutex_unlock(&g_Locker);

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) {

		FILE* fp = fopen(szFile, "w+");
		if(!fp)
		{
			printf("fopen fail szFile = %s, error = %d\n", szFile, errno);
			return 0;
		}
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
		curl_easy_setopt(curl, CURLOPT_URL, szURL);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)fp);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
		res = curl_easy_perform(curl);

		/* always cleanup */
		curl_easy_cleanup(curl);
		fclose(fp);
	}



	return 0;
}


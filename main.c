
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "logger.h"



int main(void)
{
	//log4c_init();
	//log4c_category_t* mycat = log4c_category_get("mycat");
	LOG_INIT("mycat");
	LOG_INFO("enter main()");

	int a[] = {13, 10, 8, 5, 23, 11, 4};
	myqsort(a, 0, 6);

	int i = 0;
	for(; i < 6; i++)
		printf("%d ", a[i]);

	curl_global_init(CURL_GLOBAL_ALL);

	pthread_cond_init(&g_Cond, NULL);
	pthread_mutex_init(&g_Locker, NULL);

	pthread_t pthreadid[2];

	struct THREADINFO threadinfo1;
	threadinfo1.uUserID = 111;
	strncpy(threadinfo1.szURL, "http://www.baidu.com", 260);
	strncpy(threadinfo1.szFile, "www.baidu.com.log", 260);

	pthread_mutex_lock(&g_Locker);
	int nRet = pthread_create(&pthreadid[0], NULL, threadFunc, &threadinfo1);
	if(nRet == 0)
	{
		printf("create thread success, thread id = %lu\n", (unsigned long)pthreadid[0]);

		pthread_cond_wait(&g_Cond, &g_Locker);
		pthread_mutex_unlock(&g_Locker);

	}

	struct THREADINFO threadinfo2;
	threadinfo2.uUserID = 222;
	strncpy(threadinfo2.szURL, "http://www.google.com", 260);
	strncpy(threadinfo2.szFile, "www.google.com.log", 260);

	pthread_mutex_lock(&g_Locker);
	nRet = pthread_create(&pthreadid[1], NULL, threadFunc, &threadinfo2);
	if(nRet == 0)
	{
		printf("create thread success, thread id = %lu\n", (unsigned long)pthreadid[1]);

		pthread_cond_wait(&g_Cond, &g_Locker);
		pthread_mutex_unlock(&g_Locker);

	}

	pthread_join(pthreadid[0], NULL);
	pthread_join(pthreadid[1], NULL);

	curl_global_cleanup();

	LOG_UNINIT();
	return 0;
}

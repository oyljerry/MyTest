
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

	curl_global_init(CURL_GLOBAL_ALL);

	pthread_cond_init(&g_Cond, NULL);
	pthread_mutex_init(&g_Locker, NULL);

	pthread_t pthreadid[2];

	struct THREADINFO threadinfo1;
	threadinfo1.uUserID = 111;
	strncpy(threadinfo1.szURL, "http://www.baidu.com", 260);
	threadinfo1.fp = fopen("www.baidu.com.log", "w+");

	pthread_mutex_lock(&g_Locker);
	int nRet = pthread_create(&pthreadid[0], NULL, threadFunc, &threadinfo1);
	if(nRet == 0)
	{
		printf("create thread success, thread id = %lu\n", (unsigned long)pthreadid);

		pthread_cond_wait(&g_Cond, &g_Locker);
		pthread_mutex_unlock(&g_Locker);

	}

	struct THREADINFO threadinfo2;
	threadinfo2.uUserID = 222;
	strncpy(threadinfo2.szURL, "http://www.google.com", 260);
	threadinfo2.fp = fopen("www.google.com.log", "w+");

	pthread_mutex_lock(&g_Locker);
	nRet = pthread_create(&pthreadid[1], NULL, threadFunc, &threadinfo2);
	if(nRet == 0)
	{
		printf("create thread success, thread id = %lu\n", (unsigned long)pthreadid);

		pthread_cond_wait(&g_Cond, &g_Locker);
		pthread_mutex_unlock(&g_Locker);

	}

	pthread_join(pthreadid[0], NULL);
	pthread_join(pthreadid[1], NULL);

	curl_global_cleanup();

	LOG_UNINIT();
	return 0;
}

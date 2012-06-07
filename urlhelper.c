#include "common.h"
#include "logger.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	LOG_ERROR("enter write_data()");
	int nLen = fwrite(ptr, size, nmemb, (FILE*)fp);
	return nLen;
}

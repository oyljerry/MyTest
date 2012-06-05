#include "common.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{

	int nLen = fwrite(ptr, size, nmemb, (FILE*)fp);
	return nLen;
}

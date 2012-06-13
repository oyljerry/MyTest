/*logger.h*/

#ifndef _LOGGER_H
#define _LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <log4c.h>

log4c_category_t* mycat;

//static int LOGNUM = 0;
static char *format = " %s [%s(%d)]";

/*const log4c_location_info_t locinfo = LOG4C_LOCATION_INFO_INITIALIZER(NULL);\
		log4c_category_log_locinfo(mycat, &locinfo, LOG4C_PRIORITY_DEBUG, msg, ##args);\*/

#define LOG_INIT(category) \
	{\
		log4c_init();\
		mycat = log4c_category_get(category);\
	}
#define LOG_ERROR(msg, args...) \
	{\
		log_message(LOG4C_PRIORITY_ERROR, __FILE__, __LINE__, __FUNCTION__, msg, ##args);\
	}
#define LOG_INFO(msg, args...) \
	{\
		log_message(LOG4C_PRIORITY_INFO, __FILE__, __LINE__, __FUNCTION__, msg, ##args);\
	}
#define LOG_DEBUG(msg, args...) \
	{\
		log_message(LOG4C_PRIORITY_DEBUG, __FILE__, __LINE__, __FUNCTION__, msg, ##args);\
	}

#define LOG_UNINIT() \
	{\
		log4c_fini();\
	}

static void log_message(int type, char* file, int line, const char* func, const char* a_format, ...)
{
    char *file_info;
    char *new_format;
    size_t info_len;
    size_t new_format_len;
    va_list va;

    info_len = strlen(format) + 50;
    file_info = (char *) malloc(info_len);
    sprintf(file_info, format, /*++LOGNUM,*/ func, file, line);

    new_format_len = strlen(file_info) + strlen(a_format) + 2;
    new_format = (char *) malloc(new_format_len);
    sprintf(new_format, "%s %s", file_info, a_format);

    va_start(va, a_format);
    log4c_category_vlog(mycat, type, new_format, va);
    va_end(va);

    free(file_info);
    free(new_format);
}

#endif

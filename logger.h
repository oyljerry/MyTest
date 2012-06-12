/*logger.h*/

#ifndef _LOGGER_H
#define _LOGGER_H

#include <log4c.h>

log4c_category_t* mycat;

#define LOG_INIT(category) \
	{\
		log4c_init();\
		mycat = log4c_category_get(category);\
	}
#define LOG_ERROR(msg, args...) \
	{\
		const log4c_location_info_t locinfo = LOG4C_LOCATION_INFO_INITIALIZER(NULL);\
		log4c_category_log_locinfo(mycat, &locinfo, LOG4C_PRIORITY_ERROR, msg, ##args);\
	}
#define LOG_INFO(msg, args...) \
	{\
		const log4c_location_info_t locinfo = LOG4C_LOCATION_INFO_INITIALIZER(NULL);\
		log4c_category_log_locinfo(mycat, &locinfo, LOG4C_PRIORITY_INFO, msg, ##args);\
	}
#define LOG_DEBUG(msg, args...) \
	{\
		const log4c_location_info_t locinfo = LOG4C_LOCATION_INFO_INITIALIZER(NULL);\
		log4c_category_log_locinfo(mycat, &locinfo, LOG4C_PRIORITY_DEBUG, msg, ##args);\
	}

#define LOG_UNINIT() \
	{\
		log4c_fini();\
	}

#endif

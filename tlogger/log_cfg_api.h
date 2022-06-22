/*
 * log_cfg_api.h
 *
 * for log cfg api define
 *
 * Copyright (c) 2012-2022 Huawei Technologies Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef LOG_CFG_API_H
#define LOG_CFG_API_H

#include <linux/types.h>

#if ((defined(CONFIG_BBOX_MEM) || defined(CONFIG_RDR_MEM) || \
	defined(CONFIG_PAGES_MEM) || defined(CONFIG_TEELOG)))
int register_log_mem(uint64_t *addr, uint32_t *len);
int register_log_exception(void);
void report_log_system_error(void);
void report_log_system_panic(void);
int *map_log_mem(uint64_t mem_addr, uint32_t mem_len);
void unmap_log_mem(int *log_buffer);
void get_log_chown(uid_t *user, gid_t *group);
void unregister_log_exception(void);
void ta_crash_report_log(void);
#else
static inline int register_log_mem(const uint64_t *addr, const uint32_t *len)
{
	(void)addr;
	(void)len;
	return 0;
}

static inline int register_log_exception(void)
{
	return 0;
}

static inline void report_log_system_error(void)
{
}

static inline void report_log_system_panic(void)
{
}

static inline int *map_log_mem(uint64_t mem_addr, uint32_t mem_len)
{
	(void)mem_addr;
	(void)mem_len;
	return NULL;
}
static inline void unmap_log_mem(const int *log_buffer)
{
	(void)log_buffer;
}

static inline void unregister_log_exception(void)
{
}

static inline void ta_crash_report_log(void)
{
}
#endif
#endif

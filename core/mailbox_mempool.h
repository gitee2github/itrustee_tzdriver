/*
 * mailbox_mempool.h
 *
 * mailbox memory managing for sharing memory with TEE.
 *
 * Copyright (c) 2012-2021 Huawei Technologies Co., Ltd.
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
#ifndef MAILBOX_MEMPOOOL_H
#define MAILBOX_MEMPOOOL_H

#include <linux/kernel.h>
#include <linux/types.h>

#define MAILBOX_POOL_SIZE SZ_4M

/* alloc options */
#define MB_FLAG_ZERO 0x1 /* set 0 after alloc page */
#define GLOBAL_UUID_LEN 17 /* first char represent global cmd */

void *mailbox_alloc(size_t size, unsigned int flag);
void mailbox_free(const void *ptr);
int mailbox_mempool_init(void);
void mailbox_mempool_destroy(void);
struct mb_cmd_pack *mailbox_alloc_cmd_pack(void);
void *mailbox_copy_alloc(const void *src, size_t size);

#endif

/*
 * Copyright (C) 2010-2011 ARM Limited. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *       http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file ump_arch.h
 *
 * Header file for the arch dependent backend, which will do the communication with the UMP device driver.
 */

#ifndef _UNIFIED_MEMORY_PROVIDER_ARCH_H_
#define _UNIFIED_MEMORY_PROVIDER_ARCH_H_

#include <ump/ump.h>
#include <ump/ump_ref_drv.h>
#include "ump_internal.h"

#ifdef __cplusplus
extern "C" {
#endif



/** Open UMP interface. */
ump_result ump_arch_open(void);

/** Close UMP interface. */
void ump_arch_close(void);

/** Allocate UMP memory. */
ump_secure_id ump_arch_allocate(unsigned long * size, ump_alloc_constraints constraints);

/** Query size of specified UMP memory, in bytes. */
unsigned long ump_arch_size_get(ump_secure_id secure_id);

/** Release a reference from specified UMP memory. */
void ump_arch_reference_release(ump_secure_id secure_id);

/** Map specified UMP memory into CPU address space */
void* ump_arch_map(ump_secure_id secure_id, unsigned long size, ump_cache_enabled cache, unsigned long *cookie_out);

/** Unmap specified UMP memory from CPU adderss space */
void ump_arch_unmap(void* mapping, unsigned long size, unsigned long cookie);

/** Memory synchronization - cache flushing of mapped memory
 * @return Is_cached: 1==True 0==NonCached */
int ump_arch_msync(ump_secure_id secure_id, void* mapping, unsigned long cookie, void * address, unsigned long size,  ump_cpu_msync_op op);

#ifdef __cplusplus
}
#endif

#endif /* _UNIFIED_MEMORY_PROVIDER_ARCH_H_ */

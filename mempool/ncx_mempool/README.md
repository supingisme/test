ncx_mempool
======================

Description
===========

a nginx-based memory pool . <br/>
both share-memory and private-memory are supported. it is more efficient than malloc.<br/>
it is a very light weight and do not rely on any third-party library.

Examples
========

    1 #include "ncx_slab.h" 
    2 
    3 int main(int argc, char **argv)
    4 {
    5     char *p;                                                                                                               
    6     size_t  pool_size = 4096000;  //4M                                                                                     
    7     ncx_slab_stat_t stat;                                                                                                  
    8     u_char  *space;                                                                                                        
    9     space = (u_char *)malloc(pool_size);                                                                                   
    10                                                                                                                            
    11     ncx_slab_pool_t *sp;                                                                                                   
    12     sp = (ncx_slab_pool_t*) space;                                                                                         
    13                                                                                                                            
    14     sp->addr = space;                                                                                                      
    15     sp->min_shift = 3;                                                                                                     
    16     sp->end = space + pool_size;                                                                                           
    17                                                                                                                            
    18     /*                                                                                                                     
    19      * init                                                                                                                
    20      */                                                                                                                    
    21     ncx_slab_init(sp);                                                                                                     
    22                                                                                                                            
    23     /*                                                                                                                     
    24      * alloc                                                                                                               
    25      */                                                                                                                    
    26     p = ncx_slab_alloc(sp, 128);                                                                                           
    27                                                                                                                            
    28     /*                                                                                                                     
    29      *  memory usage api. 
    30      */                                                                                                                    
    31     ncx_slab_stat(sp, &stat);                                                                                              
    32                                                                                                                            
    33     /*                                                                                                                     
    34      * free                                                                                                                
    35      */                                                                                                                    
    36     ncx_slab_free(sp, p);                                                                                                  
    37                                                                                                                            
    38     free(space);                                                                                                           
    39                                                                                                                            
    40     return 0;
    41} 
   
API
===
**ncx_slab_init(ncx_slab_pool_t *pool)** <br/>
**Description**: ???????????????????????????

**ncx_slab_alloc(ncx_slab_pool_t *pool, size_t size)**<br/>
**Description**: ????????????

**ncx_slab_free(ncx_slab_pool_t *pool, void *p)** <br/>
**Description**: ????????????

**ncx_slab_stat(ncx_slab_pool_t *pool, ncx_slab_stat_t *stat)**<br/>
**Description**: ???????????????????????????

Customization
=============
??????example???????????????????????????????????????????????????ncx_mempool???????????????????????????????????????????????????????????? <br/>
??????????????????????????????????????????????????????????????? or ????????????; 

ncx_lock.h ??????????????????????????????????????????: <br/>
1.????????????????????????????????????pthread_spin_lock <br/>
2.????????????????????????????????????nginx???ngx_shmtx.c??????spin lock <br/>
3.????????????????????????????????????????????????..

ncx_log.h ?????????????????????????????????????????????.

ncx_slab.c.orz ??? ncx_slab.c??????????????????????????????.

Author
======
dcshi(?????????) <dcshi@qq.com>

Copyright and License
=====================
This module is licensed under the BSD license.
Copyright (C) 2013, by dcshi(?????????). <dcshi@qq.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and 
      the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, 
OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/* Copyright (C) 2007-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef	_SYS_EVENTFD_H
# error "Never use <bits/eventfd.h> directly; include <sys/eventfd.h> instead."
#endif

/* Flags for eventfd.  */
enum
  {
    EFD_SEMAPHORE = 00000001,
#define EFD_SEMAPHORE EFD_SEMAPHORE
    EFD_CLOEXEC = 02000000,
#define EFD_CLOEXEC EFD_CLOEXEC
    EFD_NONBLOCK = 00004000
#define EFD_NONBLOCK EFD_NONBLOCK
  };

//EFD_CLOEXEC (since Linux 2.6.27)
//    Set the close-on-exec (FD_CLOEXEC) flag on the new file descriptor.  See the  description  of  the
//    O_CLOEXEC flag in open(2) for reasons why this may be useful.
//
//EFD_NONBLOCK (since Linux 2.6.27)
//    Set the O_NONBLOCK file status flag on the new open file description.  Using this flag saves extra
//    calls to fcntl(2) to achieve the same result.
//
//EFD_SEMAPHORE (since Linux 2.6.30)
//    Provide semaphore-like semantics for reads from the new file descriptor.  See below.


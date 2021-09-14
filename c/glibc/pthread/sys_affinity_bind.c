int sys_affinity_bind(int coreNum)
{
    cpu_set_t cpuset;
    int i, rc;

    /* set main thread affinity mask to CPU1 */

     CPU_ZERO(&cpuset);
     CPU_SET(coreNum, &cpuset);

     rc = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
     if (rc)
     {
         perror("pthread_setaffinity_np failed");
         print_err("pthread_setaffinity_np failed: %d", rc);
     }

     /* check the actual affinity mask assigned to the thread */

     CPU_ZERO(&cpuset);

     rc = pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

     if (rc)
     {
         perror("pthread_getaffinity_np failed");
         print_err("pthread_getaffinity_np failed: %d", rc);
     }

     print_dbg("set sys affinity: ");
     for (i = 0; i < CPU_SETSIZE; i++)
         if (CPU_ISSET(i, &cpuset))
             print_dbg("    CPU %d\n", i);

     if (!CPU_ISSET(coreNum, &cpuset))
     {
         print_err("affinity failed");
     }

     /**
	 *       A new thread created by pthread_create(3) inherits a copy of its
	 *                 creator's CPU affinity mask. */

    return rc;
}




#include <sys/sysinfo.h>

//returns information on overall system statistics
int sysinfo(struct sysinfo *info);



SYSCALL_DEFINE1(sysinfo, struct sysinfo __user *, info)
{
	struct sysinfo val;

	do_sysinfo(&val);

	if (copy_to_user(info, &val, sizeof(struct sysinfo)))
		return -EFAULT;

	return 0;
}



#ifdef CONFIG_COMPAT
struct compat_sysinfo {
	s32 uptime;
	u32 loads[3];
	u32 totalram;
	u32 freeram;
	u32 sharedram;
	u32 bufferram;
	u32 totalswap;
	u32 freeswap;
	u16 procs;
	u16 pad;
	u32 totalhigh;
	u32 freehigh;
	u32 mem_unit;
	char _f[20-2*sizeof(u32)-sizeof(int)];
};

COMPAT_SYSCALL_DEFINE1(sysinfo, struct compat_sysinfo __user *, info)
{
	struct sysinfo s;

	do_sysinfo(&s);

	/* Check to see if any memory value is too large for 32-bit and scale
	 *  down if needed
	 */
	if (upper_32_bits(s.totalram) || upper_32_bits(s.totalswap)) {
		int bitcount = 0;

		while (s.mem_unit < PAGE_SIZE) {
			s.mem_unit <<= 1;
			bitcount++;
		}

		s.totalram >>= bitcount;
		s.freeram >>= bitcount;
		s.sharedram >>= bitcount;
		s.bufferram >>= bitcount;
		s.totalswap >>= bitcount;
		s.freeswap >>= bitcount;
		s.totalhigh >>= bitcount;
		s.freehigh >>= bitcount;
	}

	if (!access_ok(info, sizeof(struct compat_sysinfo)) ||
	    __put_user(s.uptime, &info->uptime) ||
	    __put_user(s.loads[0], &info->loads[0]) ||
	    __put_user(s.loads[1], &info->loads[1]) ||
	    __put_user(s.loads[2], &info->loads[2]) ||
	    __put_user(s.totalram, &info->totalram) ||
	    __put_user(s.freeram, &info->freeram) ||
	    __put_user(s.sharedram, &info->sharedram) ||
	    __put_user(s.bufferram, &info->bufferram) ||
	    __put_user(s.totalswap, &info->totalswap) ||
	    __put_user(s.freeswap, &info->freeswap) ||
	    __put_user(s.procs, &info->procs) ||
	    __put_user(s.totalhigh, &info->totalhigh) ||
	    __put_user(s.freehigh, &info->freehigh) ||
	    __put_user(s.mem_unit, &info->mem_unit))
		return -EFAULT;

	return 0;
}
#endif /* CONFIG_COMPAT */


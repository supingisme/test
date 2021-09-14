#include <sys/syscall.h>

//delete_module - unload a kernel module
int delete_module(const char *name, int flags);

//flags == O_NONBLOCK
//      The call returns immediately, with an error.
//
//flags == (O_NONBLOCK | O_TRUNC)
//      The module is unloaded immediately, regardless of whether it has a nonzero reference count.
//
//(flags & O_NONBLOCK) == 0
//      If flags does not specify O_NONBLOCK, the following steps occur:
//
//      *  The module is marked so that no new references are permitted.
//
//      *  If the module's reference count is nonzero, the caller  is  placed  in  an  uninterruptible
//         sleep  state  (TASK_UNINTERRUPTIBLE)  until the reference count is zero, at which point the
//         call unblocks.
//
//      *  The module is unloaded in the usual way.


SYSCALL_DEFINE2(delete_module, const char __user *, name_user,
		unsigned int, flags)
{
	struct module *mod;
	char name[MODULE_NAME_LEN];
	int ret, forced = 0;

	if (!capable(CAP_SYS_MODULE) || modules_disabled)
		return -EPERM;

	if (strncpy_from_user(name, name_user, MODULE_NAME_LEN-1) < 0)
		return -EFAULT;
	name[MODULE_NAME_LEN-1] = '\0';

	audit_log_kern_module(name);

	if (mutex_lock_interruptible(&module_mutex) != 0)
		return -EINTR;

	mod = find_module(name);
	if (!mod) {
		ret = -ENOENT;
		goto out;
	}

	if (!list_empty(&mod->source_list)) {
		/* Other modules depend on us: get rid of them first. */
		ret = -EWOULDBLOCK;
		goto out;
	}

	/* Doing init or already dying? */
	if (mod->state != MODULE_STATE_LIVE) {
		/* FIXME: if (force), slam module count damn the torpedoes */
		pr_debug("%s already dying\n", mod->name);
		ret = -EBUSY;
		goto out;
	}

	/* If it has an init func, it must have an exit func to unload */
	if (mod->init && !mod->exit) {
		forced = try_force_unload(flags);
		if (!forced) {
			/* This module can't be removed */
			ret = -EBUSY;
			goto out;
		}
	}

	/* Stop the machine so refcounts can't move and disable module. */
	ret = try_stop_module(mod, flags, &forced);
	if (ret != 0)
		goto out;

	mutex_unlock(&module_mutex);
	/* Final destruction now no one is using it. */
	if (mod->exit != NULL)
		mod->exit();
	blocking_notifier_call_chain(&module_notify_list,
				     MODULE_STATE_GOING, mod);
	klp_module_going(mod);
	ftrace_release_mod(mod);

	async_synchronize_full();

	/* Store the name of the last unloaded module for diagnostic purposes */
	strlcpy(last_unloaded_module, mod->name, sizeof(last_unloaded_module));

	free_module(mod);
	/* someone could wait for the module in add_unformed_module() */
	wake_up_all(&module_wq);
	return 0;
out:
	mutex_unlock(&module_mutex);
	return ret;
}


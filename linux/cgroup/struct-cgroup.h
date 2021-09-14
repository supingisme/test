
struct cgroup {
	/* self css with NULL ->ss, points back to this cgroup */
	struct cgroup_subsys_state self;

	unsigned long flags;		/* "unsigned long" so bitops work */

	/*
	 * The depth this cgroup is at.  The root is at depth zero and each
	 * step down the hierarchy increments the level.  This along with
	 * ancestor_ids[] can determine whether a given cgroup is a
	 * descendant of another without traversing the hierarchy.
	 */
	int level;

	/* Maximum allowed descent tree depth */
	int max_depth;

	/*
	 * Keep track of total numbers of visible and dying descent cgroups.
	 * Dying cgroups are cgroups which were deleted by a user,
	 * but are still existing because someone else is holding a reference.
	 * max_descendants is a maximum allowed number of descent cgroups.
	 *
	 * nr_descendants and nr_dying_descendants are protected
	 * by cgroup_mutex and css_set_lock. It's fine to read them holding
	 * any of cgroup_mutex and css_set_lock; for writing both locks
	 * should be held.
	 */
	int nr_descendants;
	int nr_dying_descendants;
	int max_descendants;

	/*
	 * Each non-empty css_set associated with this cgroup contributes
	 * one to nr_populated_csets.  The counter is zero iff this cgroup
	 * doesn't have any tasks.
	 *
	 * All children which have non-zero nr_populated_csets and/or
	 * nr_populated_children of their own contribute one to either
	 * nr_populated_domain_children or nr_populated_threaded_children
	 * depending on their type.  Each counter is zero iff all cgroups
	 * of the type in the subtree proper don't have any tasks.
	 */
	int nr_populated_csets;
	int nr_populated_domain_children;
	int nr_populated_threaded_children;

	int nr_threaded_children;	/* # of live threaded child cgroups */

	struct kernfs_node *kn;		/* cgroup kernfs entry */
	struct cgroup_file procs_file;	/* handle for "cgroup.procs" */
	struct cgroup_file events_file;	/* handle for "cgroup.events" */

	/*
	 * The bitmask of subsystems enabled on the child cgroups.
	 * ->subtree_control is the one configured through
	 * "cgroup.subtree_control" while ->child_ss_mask is the effective
	 * one which may have more subsystems enabled.  Controller knobs
	 * are made available iff it's enabled in ->subtree_control.
	 */
	u16 subtree_control;
	u16 subtree_ss_mask;
	u16 old_subtree_control;
	u16 old_subtree_ss_mask;

	/* Private pointers for each registered subsystem */
	struct cgroup_subsys_state __rcu *subsys[CGROUP_SUBSYS_COUNT];

	struct cgroup_root *root;

	/*
	 * List of cgrp_cset_links pointing at css_sets with tasks in this
	 * cgroup.  Protected by css_set_lock.
	 */
	struct list_head cset_links;

	/*
	 * On the default hierarchy, a css_set for a cgroup with some
	 * susbsys disabled will point to css's which are associated with
	 * the closest ancestor which has the subsys enabled.  The
	 * following lists all css_sets which point to this cgroup's css
	 * for the given subsystem.
	 */
	struct list_head e_csets[CGROUP_SUBSYS_COUNT];

	/*
	 * If !threaded, self.  If threaded, it points to the nearest
	 * domain ancestor.  Inside a threaded subtree, cgroups are exempt
	 * from process granularity and no-internal-task constraint.
	 * Domain level resource consumptions which aren't tied to a
	 * specific task are charged to the dom_cgrp.
	 */
	struct cgroup *dom_cgrp;
	struct cgroup *old_dom_cgrp;		/* used while enabling threaded */

	/* per-cpu recursive resource statistics */
	struct cgroup_rstat_cpu __percpu *rstat_cpu;
	struct list_head rstat_css_list;

	/* cgroup basic resource statistics */
	struct cgroup_base_stat last_bstat;
	struct cgroup_base_stat bstat;
	struct prev_cputime prev_cputime;	/* for printing out cputime */

	/*
	 * list of pidlists, up to two for each namespace (one for procs, one
	 * for tasks); created on demand.
	 */
	struct list_head pidlists;
	struct mutex pidlist_mutex;

	/* used to wait for offlining of csses */
	wait_queue_head_t offline_waitq;

	/* used to schedule release agent */
	struct work_struct release_agent_work;

	/* used to track pressure stalls */
	struct psi_group psi;

	/* used to store eBPF programs */
	struct cgroup_bpf bpf;

	/* If there is block congestion on this cgroup. */
	atomic_t congestion_count;

	/* Used to store internal freezer state */
	struct cgroup_freezer_state freezer;

	/* ids of the ancestors at each level including self */
	u64 ancestor_ids[];
};


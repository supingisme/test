/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//责任链模式
//责任链模式是很实用的一种实际方法。举个例子来说，我们平常在公司里面难免不了报
//销流程。但是，我们知道公司里面每一级的领导的报批额度是不一样的。比如说，科长的额
//度是1000 元，部长是10000 元，总经理是10 万元。
//那么这个时候，我们应该怎么设计呢？其实可以这么理解。比如说，有人来找领导报销
//费用了，那么领导可以自己先看看自己能不能报。如果费用可以顺利报下来当然最好，可是
//万一报不下来呢？那就只能请示领导的领导了。

typedef struct _Leader
{
	struct _Leader* next;
	int account;
	int (*request)(strcut _Leader* pLeader, int num);
}Leader;
void set_next_leader(const struct _Leader* pLeader, struct _Leader* next)
{
	assert(NULL != pLeader && NULL != next);
	pLeader->next = next;
	return;
}

//此时，如果有一个员工过来报销费用，那么应该怎么做呢？假设此时的Leader 是经理，
//报销额度是10 万元。所以此时，我们可以看看报销的费用是不是小于10 万元？少于这个数
//就OK，反之就得上报自己的领导了。

int request_for_manager(struct _Leader* pLeader, int num)
{
	assert(NULL != pLeader && 0 != num);
	if(num < 100000)
		return 1;
	else if(pLeader->next)
		return pLeader->next->request(pLeader->next, num);
	else
		return 0;
}

/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//命令模式
//命令模式的目的主要是为了把命令者和执行者分开。老规矩，举个范例吧。假设李老板
//是一家公司的头儿，他现在让他的秘书王小姐去送一封信。王小姐当然不会自己亲自把信送
//到目的地，她会把信交给邮局来完成整个投递的全过程。现在，我们就对投递者、命令、发
//令者分别作出定义。
//首先定义post 的相关数据。
//

typedef struct _Post
{
	void (*do)(struct _Post* pPost);
}Post;

//Post 完成了实际的投递工作，那么命令呢？
void post_exe(struct _Command* pCommand)
{
	assert(NULL != pCommand);
	(Post*)(pCommand->pData)->do((Post*)(pCommand->pData));
	return;
}

//我们看到了Post、Command 的操作，那么剩下的就是boss 的定义了

typedef struct _Boss
{
	Command* pCommand;
	void (*call)(struct _Boss* pBoss);
}Boss;

void boss_call(struct _Boss* pBoss)
{
	assert(NULL != pBoss);
	pBoss->pCommand->exe(pBoss->pCommand);
	return;
}



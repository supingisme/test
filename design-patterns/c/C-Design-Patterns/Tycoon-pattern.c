/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//亨元模式
//享元模式看上去有点玄乎，但是其实也没有那么复杂。我们还是用示例说话。比如说，
//大家在使用电脑的使用应该少不了使用WORD 软件。使用WORD 呢，那就少不了设置模板。
//什么模板呢，比如说标题的模板，正文的模板等等。这些模板呢，又包括很多的内容。哪些
//方面呢，比如说字体、标号、字距、行距、大小等等。
//上面的Font 表示了各种Font 的模板形式。所以，下面的方法就是定制一个FontFactory
//的结构。

typedef struct _FontFactory
{
	Font** ppFont;
	int number;
	int size;
	Font* GetFont(struct _FontFactory* pFontFactory, int type, int sequence, int gap, int
			lineDistance);
}FontFactory;

//这里的GetFont 即使对当前的Font 进行判断，如果Font 存在，那么返回；否则创建一
//个新的Font 模式。

Font* GetFont(struct _FontFactory* pFontFactory, int type, int sequence, int gap, int
		lineDistance)
{
	int index;
	Font* pFont;
	Font* ppFont;
	if(NULL == pFontFactory)
		return NULL;
	for(index = 0; index < pFontFactory->number; index++)
	{
		if(type != pFontFactory->ppFont[index]->type)
			continue;
		if(sequence != pFontFactory->ppFont[index]->sequence)
			continue;
		if(gap != pFontFactory->ppFont[index]->gap)
			continue;
		if(lineDistance != pFontFactory->ppFont[index]->lineDistance)
			continue;
		return pFontFactory->ppFont[index];
	}
	pFont = (Font*)malloc(sizeof(Font));
}


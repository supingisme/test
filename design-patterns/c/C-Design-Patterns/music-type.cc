/* Comment Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:13:49 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:11:44 CST. */
//举个例子来说，现在让你写一个音乐播放器，但是要支持的文件格式很多，什么ogg，
//wav，mp3 啊，统统要支持。这时候，你会怎么编写呢？如果用C++语言，你可能会这
//么写。
class music_file
{
	HANDLE hFile;
	public:
	void music_file() {}
	virtual ~music_file() {}
	virtual void read_file() {}
	virtual void play() {}
	virtual void stop() {}
	virtual void back() {}
	virtual void front() {}
	virtual void up() {}
	virtual void down() {}
};

//果用C 语言能够完成相同的抽象操作
typedef struct _music_file
{
	HANDLE hFile;
	void (*read_file)(struct _music_file* pMusicFile);
	void (*play)(struct _music_file* pMusicFile);
	void (*stop)(struct _music_file* pMusicFile);
	void (*back)(struct _music_file* pMusicFile);
	void (*front)(struct _music_file* pMusicFile);
	void (*down)(struct _music_file* pMusicFile);
	void (*up)(struct _music_file* pMusicFile);
}music_file;

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class String{
public:
	typedef char* iterator;			//string的迭代器本质就是一个指针
	typedef const char* const_iterator;	//const迭代器

	const_iterator begin() const{
		return _str;
	}

	const_iterator end() const{
		return _str + _size;
	}

	iterator begin(){
		return _str;
	}

	iterator end(){
		return _str + _size;
	}

	//构造函数
	String(const char* str = "")
		:_str(nullptr)
		, _capacity(0)
	{
		_size = strlen(str);
		Reserve(_size);
		strcpy(_str, str);
	}

	// 拷贝构造
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp); // tmp.Swap(*this);
	}

	// 赋值
	String& operator=(String s){
		Swap(s);
		return *this;
	}

	// s1.Swap(s2)方法，便于交换，效率优于swap(s1,s2);免去了2步拷贝构造
	void Swap(String& s){
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	//析构函数
	~String(){
		if (_str){
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	}

	//通用Insert接口
	void Insert(size_t pos, char ch) {
		assert(pos <= _size);

		if (_size == _capacity) {
			Reserve(_capacity * 2);
		}

		for (size_t i = _size; i >= pos; --i) {		//从'\0'开始挪动数据
			_str[i + 1] = _str[i];
		}
		_str[pos] = ch;
		_size++;
	}

	void Insert(size_t pos, const char* str) {
		assert(pos <= _size);

		size_t len = strlen(str);
		if (_size + len > _capacity) {
			Reserve(_size + len);
		}
		for (size_t i = _size; i >= pos; --i) {
			_str[i + len] = _str[i];
		}
		strncpy(_str + pos, str, len);
		_size += len;
	}

	//pushback方法
	void PushBack(char ch){
		//1. 现代方法
		Insert(_size, ch);

		//2. 经典方法
		/*
			if (_size == _capacity)
			{
			Reserve(_capacity * 2);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		*/
	}

	//追加 append方法
	void Append(const char* str){
		//1. 现代方法
		Insert(_size, str);
		
		//2. 经典方法
		/*
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				Reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		*/
	}


	//查找：返回数据下标

	//1. 查找字符接口
	size_t Find(char ch, size_t pos = 0) {
		for (size_t i = pos; i < _size; ++i){
			if (_str[i] == ch){
				return i;
			}
		}
		return npos;	//没找到
	}

	//2. 查找字符串接口
	size_t Find(const char* str, size_t pos = 0) {
		const char* ret = strstr(_str + pos, str);
		if (ret == nullptr)
			return npos;
		else
			return ret - _str;	//无论是否给定下标pos，返回的都是相对于首部的偏移量
	}

	//擦除数据接口
	void Erase(size_t pos = 0, size_t len = npos) {
		if (pos + len >= _size){
			_size = pos;
			_str[_size] = '\0';
		}
		else{
			size_t start = pos + len;
			strcpy(_str + pos, _str + start);
			_size -= len;
		}
	}

	// operator+= 操作符重载 ->字符
	String& operator+=(char ch){
		PushBack(ch);
		return *this;
	}

	// operator+= 操作符重载 ->字符串
	String& operator+=(const char* str){
		Append(str);
		return *this;
	}

	bool operator<(const String& s)const {
		size_t i = 0;
		size_t j = 0;
		while (i < _size && j < s._size){
			if (_str[i] < s[j]){
				return true;
			}
			else if (_str[i] > s[j]){
				return false;
			}
			else{
				++i;
				++j;
			}
		}
		if (j < s._size){	//左值字符串长度小于右值
			return true;
		}
		else{				//左值字符串长度大于右值
			return false;
		}
	}
	bool operator<=(const String& s)const {
		return *this < s || *this == s;
	}
	bool operator>(const String& s)const {
		return !(*this <= s);
	}
	bool operator>=(const String& s)const {
		return !(*this < s);
	}
	bool operator==(const String& s)const {
		size_t i = 0;
		size_t j = 0;
		while (i < _size && j < s._size){
			if (_str[i] != s[j]){
				return false;
			}
			else{
				++i;
				++j;
			}
		}

		if (i == _size && j == s._size){
			return true;
		}
		else{
			return false;
		}
	}
	bool operator!=(const String& s)const {
		return !(*this == s);
	}


	//operator+运算符重载 -> 字符
	String operator+(char ch) const{
		String tmp(*this);
		tmp.PushBack(ch);
		return tmp;
	}

	//operator+运算符重载 -> 字符串
	String& operator+(const char* str){
		String tmp(*this);
		tmp.Append(str);
		return tmp;
	}

	//operator[]运算符重载
	char& operator[](size_t pos){
		assert(pos < _size);	//使用断言

		return _str[pos];
	}

	//operator[]运算符重载 const
	const char& operator[](size_t pos) const{
		assert(pos < _size);

		return _str[pos];
	}

	//c_str接口
	char* c_str() const {
		return _str;
	}

	//size()接口
	size_t Size() const{	
		return _size;
	}

	//capacity()接口
	size_t Capacity() const{
		return _capacity;
	}

	//reserve()扩容
	void Reserve(size_t n){
		if (n == 0 || n > _capacity){
			//size_t newsize = (n + 7) & ( ~7);		//8倍数算法
			size_t newsize = n;
			if (n % 8 != 0)
				newsize = (n / 8 + 1) * 8;
			else
				newsize = n + 8;

			char* newstr = new char[newsize];
			if (_str)
				strcpy(newstr, _str);
			delete[] _str;
			_str = newstr;
			_capacity = newsize - 1;
		}
	}

	//resize()扩容
	void Resize(size_t n, char ch = '\0'){
		if (n <= _size){
			_size = n;
			_str[_size] = '\0';
		}
		else{
			Reserve(n);

			for (size_t i = _size; i < n; ++i){
				_str[i] = ch;
				++_size;
			}
			_str[_size] = '\0';
		}
	}

private:
	char*  _str;
	size_t _size;
	size_t _capacity;

	static size_t npos;
};

size_t String::npos = -1;	//静态成员在类外定义



# Copyright (C) Rong Tao @Sylincom Beijing, 2020年 01月 19日 星期日 17:20:03 CST. 
# 列举出所有牌型为牛牛的情况
# author:tanteng
import itertools,sys

#初始化数据
cards = list(itertools.combinations([1,2,3,4,5,6,7,8,9,10,11,12,13],5))
print(len(cards))
card_name = {1:'A',2:2,3:3,4:4,5:5,6:6,7:7,8:8,9:9,10:10,11:'J',12:'Q',13:'K'}
Count = 0

#判断牌型是否为牛牛
def is_niuniu(card=None):
	sums = 0
	card_copy = list(map(check_card,list(card)))
	sums = sum(card_copy)

	if sums%10 == 0:#五张牌相加是10的倍数
		new_card = list(itertools.permutations(card,3))#从五张牌取3张进行排列
		for new_c in new_card:
			new_c = list(new_c)
			new_c = list(map(check_card,new_c))
			summ = sum(new_c)
			if (summ%10 == 0):#如果有任意三张牌是10的倍数
				#print(summ)
				print(list(map(show_card, card)))
				global Count
				Count = Count+1
				break

#显示对应的牌的名称
def show_card(card):
	return card_name[card];

#将11,12,13替换成10
def check_card(card):
	if card>10:
		return 10
	else:
		return card
#if __name__ == '__main__'：这句估计很多和我一样的初学者都是不求甚解。
#这里作一下解释：
#
#1：__name__是一个变量。前后加了下划线是因为这是系统定义的名字。普通变量不要使用此方式命名变量。
#2：Python有很多模块，而这些模块是可以独立运行的！这点不像C++和C的头文件。
#3：import的时候是要执行所import的模块的。
#4：__name__就是标识模块的名字的一个系统变量。这里分两种情况：假如当前模块是主模块（也就是调用其他模块的模块），
#    那么此模块名字就是 __main__ ，通过if判断这样就可以执行“__main__:”后面的主函数内容；假如此模块是被import的，
#    则此模块名字为文件名字（不加后面的.py），通过if判断这样就会跳过“__main__:”后面的内容。
#
#通过上面方式，python就可以分清楚哪些是主函数，进入主函数执行；并且可以调用其他模块的各个函数等等。
if __name__ == '__main__':
	for card in cards:
		is_niuniu(card)

	print(Count)
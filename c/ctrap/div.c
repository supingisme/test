int fn1(int x, unsigned int factor) {
	return x / factor;
}
int fn2(int x, int factor) {
	return x / factor;
}
int main(void) {
	int x=-20,y=10,res;

	res = fn1(x,y);
	printf("y=%d\n",res);

	res = fn1(-x,y);
	printf("y=%d\n",res);

	res = fn1(-x,y);
	printf("y=%d\n",res);

	return 0;
}

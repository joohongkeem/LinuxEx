#include<stdio.h>

extern __inline int square(int x){
	return x * x;
}


double add(int x, int y){
	return (double)(square(x) + square(y));
}

int main(void){
	int x = 2;
	int y = 3;
	double result;

	result = add(x, y);
	printf("%lf\n", result);
	return 0;
}

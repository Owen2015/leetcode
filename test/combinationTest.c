#include "combinationUtil.h"

void main(int argc,char* argv[]){
	int n=100;
	int m=3;
	int combination=combinationSize(n,m);
	long permutation=permutationSize(n,m);
	long p2=permutationSize(m,m);
	printf("p(m,m) :%d \n",p2);
	printf("permutationsize: %d, combinationSize: %d \n",permutation,combination);
	printf("factorial n: %d, factorial(m): %d \n ", factorialIterate(n),factorialIterate(m));
}

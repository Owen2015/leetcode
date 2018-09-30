
#include "../app/arrayFunction.h"

void main(int argc,char* argv[]){
	int nums[]={-1,0,1,2,-1,-4};
	int size=6;
	//removeDuplicates(nums,&size);
	quicksort(nums,size);
	int i;
	printf("size :%d \n",size);
	for(i=0;i<size;i++)
		printf("%d ",nums[i]);
	printf(" \n work is done \n");
}

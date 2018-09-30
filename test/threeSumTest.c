
#include "combinationUtil.h"
#include "arrayFunction.h"
void main(int argc, char* argv){
	//int nums[]={-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//	int nums[]={-1,0,1,2,-1,-4};
	int nums[]={-4,-8,7,13,10,1,-14,-13,0,8,6,-13,-5,-4,-12,2,-11,7,-5,0,-9,-14,-8,-9,2,-7,-13,-3,13,9,-14,-6,8,1,14,-5,-13,8,-10,-5,1,11,-11,3,14,-8,-10,-12,6,-8,-5,13,-15,2,11,-5,10,6,-1,1,0,0,2,-7,8,-6,3,3,-13,8,5,-5,-3,9,5,-4,-14,11,-8,7,10,-6,-3,11,12,-14,-9,-1,7,5,-15,14,12,-5,-8,-2,4,2,-14,-2,-12,6,8,0,0,-2,3,-7,-14,2,7,12,12,12,0,9,13,-2,-15,-3,10,-14,-4,7,-12,3,-10};
	int numsSize=127;
	int returnSize=0;
	int **result;
	int i,j;
	result=threeSum(nums,numsSize,&returnSize);
	
	printf("resultSize : %d \n",returnSize);
	for(i=0;i<returnSize;i++){
		for(j=0;j<3;j++){
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	printf("work is done");
}

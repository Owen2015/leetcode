#include "arrayFunction.h"
#include "mathutil.h"



int** threeSum2(int* nums, int numsSize, int* returnSize) {
    if(numsSize<=2) return 0;
    int i;
    int l=0;
	l=combinationSize(numsSize,3);
	printf("numSize: %d, l: %d\n",numsSize,l);
   // int** result;
    //result=(int**)malloc(sizeof(int*)*l);
    //for(i=0;i<l;i++){
     //   result[i]=(int*)malloc(sizeof(int)*3);
    //}
    int index[l][3];
    int v[3];
    int cnt=0;
    int *cntp=&cnt;
    *returnSize=0;
    int num=0;
   int** p;
	p=(int**)malloc(sizeof(int*)*l);
	for(i=0;i<l;i++)
		p[i]=(int*)malloc(sizeof(int)*3);
    combinations2(v,1,numsSize,1,3,&index[0][0],cntp);
//	result[0][0]=0;
//	printf("result [0][0]: %d",result[0][0]);
    for(i=0;i<l;i++){
        if((nums[index[i][0]-1]+nums[index[i][1]-1]+nums[index[i][2]-1])==0){
            p[num][0]=nums[index[i][0]-1];
            p[num][1]=nums[index[i][1]-1];
            p[num][2]=nums[index[i][2]-1];
	insertSort(p[num],3);
            num=num+1;
        }
    }
	removeDuplicateArrays(p,&num);
    *returnSize=num;
    return p;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
        int size=combinationSize(numsSize,3);
        int **result=(int**)malloc(sizeof(int*)*size);
        int l;
        for(l=0;l<size;l++) result[l]=(int*)malloc(sizeof(int)*3);
        int cnt=0;
        if(numsSize<=2)return result;
        insertSort(nums,numsSize);
        int i,j,k;
        for(k=0;k<numsSize;++k){
                if(nums[k]>0) break;
                if(k>0&&nums[k]==nums[k-1]) continue;
                int target=0-nums[k];
                i=k+1;
                j=numsSize-1;
                while(i<j){
                        if(nums[i]+nums[j]==target){
                                result[cnt][0]=nums[k];
                                result[cnt][1]=nums[i];
                                result[cnt][2]=nums[j];
				cnt++;
                                while(i<j&&nums[i]==nums[i+1]) ++i;
                                while(i<j&&nums[j]==nums[j-1])--j;
                                ++i;--j;
                        } else if(nums[i]+nums[j]<target) ++i;
                        else --j;
                }
        }
    *returnSize=cnt;
    return result;
}

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int s[matrixRowSize+matrixColSize];
    
    int i,j;
    for(i=0;i<matrixRowSize+matrixColSize;i++)
        s[i]=0;
    
    for(i=0;i<matrixRowSize;i++){
        for(j=0;j<matrixColSize;j++){
            if(matrix[i][j]==0){
                s[i]=1;
                s[matrixRowSize+j]=1;
            }
        }
    }
    for(i=0;i<matrixRowSize+matrixColSize;i++){
        if(i<matrixRowSize&&s[i]==1){
            for(j=0;j<matrixColSize;j++)
                matrix[i][j]=0;
        }else if(i>=matrixRowSize&&s[i]==1){
            for(j=0;j<matrixRowSize;j++)
                matrix[j][i-matrixRowSize]=0;
        }
    }
}

char*** groupAnagrams(char** strs, int strsSize,int** columnSizes,int* returnSize){
	int alpha[26]={0};
	
}

int increasingTriplet(int* nums, int numsSize){

}

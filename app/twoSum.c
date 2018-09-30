int* twoSum(int* nums,int numsSize,int target){

	int result[2];
	result[0]=-1;
	result[1]=-1;
	int i,j;
	for(i=0;i<numsSize;i++){
		for(j=i;j<numsSize;j++){
			if((nums[i]+nums[j])==target){
				result[0]=i;
				result[1]=j;
			}
		}
	}
	return result;
}	

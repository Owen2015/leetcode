int climbStairs(int n){
	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	return climbStairs(n-1)+climbStairs(n-2);
}

int maxSubArray(int* nums, int numsSize) {
    int max=INT_MIN;
    int temp=0;
    int i=0;
    int j=0;
    for(i=0;i<numsSize;i++){ 
        temp=0;
        for(j=i;j<numsSize;j++){
            temp=temp+nums[j];
            if(temp>max) max=temp;
        }
    }
    return max;
}

int robUtil(int* nums, int numsSize,int i) {
    if(i+2>=numsSize) {
        return nums[i];
    } else if(i+3>=numsSize){
        return nums[i+2]+nums[i];
    }    
    int temp1=robUtil(nums,numsSize,i+2);
    int temp2=robUtil(nums,numsSize,i+3);

    if (temp1>=temp2){
        return temp1+nums[i];
    } else {
        return temp2+nums[i];
    }
}

int rob(int* nums, int numsSize) {
    int maxOdd=0;
    int maxMean=0;
    int i;
    if (numsSize<=0) return 0;
    
    maxOdd=robUtil(nums,numsSize,0);
    maxMean=robUtil(nums,numsSize,1);
    if(maxOdd>maxMean) return maxOdd;
    else return maxMean;

}


int robUtil2(int* nums, int numsSize,int i,int* arr) {

    if(i+2>=numsSize) {
       arr[i]=nums[i];
        return nums[i];
    } else if(i+3>=numsSize){
        arr[i]=nums[i+2]+nums[i];
        return nums[i+2]+nums[i];
    }    
    if(arr[i+2]==0)
        arr[i+2]=robUtil2(nums,numsSize,i+2,arr);
    if(arr[i+3]==0)
        arr[i+3]=robUtil2(nums,numsSize,i+3,arr);
    if (arr[i+2]>=arr[i+3]){
        arr[i]=arr[i+2]+nums[i];
        return arr[i+2]+nums[i];
    } else {
        arr[i]=arr[i+3]+nums[i];
        return arr[i+3]+nums[i];
    }
}

int rob2(int* nums, int numsSize) {
    int maxOdd=0;
    int maxMean=0;
    int i;
    int arr[6000]={0};
    if (numsSize<=0) return 0;
    if(nums[0]==0&&nums[numsSize-1]==0&&nums[1]==0)
        return 0;
    maxOdd=robUtil2(nums,numsSize,0,arr);
    for(i=0;i<numsSize;i++){
        arr[i]=0;
    }
    maxMean=robUtil2(nums,numsSize,1,arr);
    if(maxOdd>maxMean) return maxOdd;
    else return maxMean;
}

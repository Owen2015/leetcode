/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/
int climbStairs(int n) {
        if (n == 1 || n == 0)
            return 1;
        n = n - 1;
        int result = 0;
        int zero = 1;
        int first = 1;
        while (n > 0) {
            result = zero + first;
            zero = first;
            first = result;
            n--;
        }
        return result;
}
////
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
int maxSubArray(int* nums, int numsSize) {
      if (numsSize <= 0) return 0;

    int result = nums[0];
    
    int now = result;
    
    for(int i = 1 ; i < numsSize; i++){
    	
    	if (now + nums[i] < nums[i]){
    			now = nums[i];
			}else{
				now = now + nums[i];
			}
    
			
    	if (result < now) result = now;
    	if (result < nums[i]) result = nums[i];
    	
	}
	
	
	
	return result;
}

///
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/
inline int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int rob(int* nums, int numsSize) {
    if(numsSize==0)return 0;
    
    int dp[numsSize][2];
    dp[0][0]=0;
    dp[0][1]=nums[0];
    
    for(int i=1;i<numsSize;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=dp[i-1][0]+nums[i];
    }
    
    return max(dp[numsSize-1][0],dp[numsSize-1][1]);
}

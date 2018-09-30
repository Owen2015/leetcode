//#include "arrayFunction.h"
//#include "twoSum.h"
//#include "stringUtil.h"
//#include "linkListUtil.h"
#include "queueUtil.h"
#define random(x) (rand()%x)
//void moveZeroes(int * nums,int numsSize);
struct ListNode {
	int val;
	struct ListNode *next;
};

int main(int argc, char* args[]){

	printf("hello\n");
	//int a[10]={0,0,1,1,1,2,2,3,3,4};
//	int a[argc-1];
	char* command=args[1];
	printf("command is %s: \n",command);
	// input string to array
	/*
	for(i=2;i<argc;i++){
		a[i-2]=atoi(args[i]);
		printf("input args: %s,%d \n",args[i],a[i-2]);
	}*/
//	int result=removeDuplicates(a,argc);
//	rotate(a,argc-1,k);
	//int i=0;
	//int result;
	//int result;
//	result=containDuplicate(a,argc-1);
	/*switch(command){
	case 'moveZeroes':
		moveZeroes(a,argc-2);
		break;
	}
	if(args[1]=='moveZeroes'){
	printf("moveZeroes is running...");
	moveZeroes(a,argc-2);
	}*/
//	int* resultA;
//	printf("test \n %s \n",args[2]);
//	char* resultS=reverseString(args[2]);
	//printf("result is %s: ",resultS);
	//resultA=twoSum(a,argc-2,9);
	//printf("index is : %d, and %d \n",resultA[0],resultA[1]);
	/*
	for(i=0;i<argc-2;i++){
		printf(" %d \n",a[i]);
	}*/

//	result=containDuplicate(a,argc-1);
//	printf("result is  %d \n",result); 
	
//	int result=firstUniqChar(args[2]);
	//int result=isAnagram(args[2],args[3]);
	//int result=isPalindrome(args[2]);
	//int result=strStr(args[2],args[3]);
/*	 struct ListNode list[2];
	struct ListNode first=list[0];
	struct ListNode second=list[1];
	first.val=1;
	first.next=&list[1];
	second.val=2;
	second.next=0;*/
	//int result=isPalindrome(&first);	
/*	
	struct TreeNode nodes[5];
	nodes[0].val=3;
	nodes[1].val=9;
	nodes[2].val=20;
	nodes[3].val=15;
	nodes[4].val=7;
	nodes[0].left=&nodes[1];
	nodes[0].right=&nodes[2];
	nodes[2].left=nodes[3];
	nodes[2].right=nodes[4];
	int* columnSizes[3];
	int returnSize=3;
*/
	srand((int)time(0));
	printf("random value %d \n",random(100));
//	int** result=levelOrder(&nodes[0],columnSize,&returnSize);
	printf("work is done");
//	printf("test int **, a[0][0]:%d, a[1][2]: %d",(*b)[0],(*b)[1]);	
//	printf("result is %d \n",result);	
	//printAscii();
}

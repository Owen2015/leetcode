#include "linkListUtil.h"
struct ListNode { int val; struct ListNode *next;
};

void main(int argc, char* argv[]){
	struct ListNode arr[5];
	int i;
	for(i=0;i<5;i++)
		arr[i].val=i+1;
	for(i=0;i<4;i++)
		arr[i].next=&arr[i+1];
	arr[4].next=0;
	struct ListNode* result=oddEvenList(&arr[0]);
	
	while(result!=0){
		printf("result.val: %d, result.next: %d \n",result->val,result->next);
		result=result->next;
	}
	printf("work is done");

}

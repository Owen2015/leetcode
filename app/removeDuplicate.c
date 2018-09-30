#include <stdio.h>
#include <stdbool.h>
//#include "arrayFunction.c"
int removeDuplicates(int* nums, int numsSize) {
    int cnt=0;
    int i=0,j=0;
	int tempSize=numsSize;
    for( i=0;i<numsSize-1;i++){
        for(j=i+1;j<tempSize;j++){
            if(nums[i]==nums[j]){
                numsSize=numsSize-1;
                cnt=i+1;
            }
            if(cnt){
                if(j<(tempSize-1)&&nums[i]!=nums[j+1]){
                    nums[cnt++]=nums[j+1];
                }
            }
        }
//	printf(" numSize: %d,tempSize %d, iterate %d : %d %d %d %d %d %d %d %d %d %d \n",numsSize,tempSize,i,nums[0],nums[1],nums[2],nums[3],nums[4],nums[5],nums[6],nums[7],nums[8],nums[9]);
        cnt=0;
    }
    return numsSize;
}

int maxProfit(int* price, int priceSize){
	int sum=0;
	int i;
	for(i=0;i<priceSize-1;i++){
		if(price[i]<price[i+1]){
			sum+=price[i+1]-price[i];
		}
	}
	return sum;
}

void rotate(int* nums,int numsSize,int k){
	int i;
	for(i=0;i<k;i++){
		rotateClockwise(nums,numsSize);
	}
}
void rotateClockwise(int* nums,int numsSize){
	int temp=nums[numsSize-1];
	int i;
	for(i=numsSize-1;i>0;i--){
		nums[i]=nums[i-1];
	}
	nums[0]=temp;
}
//int containDuplicate(int* nums, int numsSize){
//	return 0;
//}

typedef struct intNode{
	int data;
	struct intNode *next;
	struct intNode *previous;
}intNode;

void insertBefore(intNode *list, intNode *data){
	intNode *previous;
	if(list->previous){
		previous=list->previous;
		previous->next=data;
	}
	data->previous=list->previous;
	data->next=list;
	list->previous=data;		
}
void insertAfter(intNode *list, intNode *node){
	intNode *next;
	if(list->next){
		next=list->next;
		next->previous=node;
	}
	node->next=list->next;
	node->previous=list;
	list->next=node;
}

intNode * createIntNode(){
	intNode *new=(intNode*)malloc(sizeof(intNode));
	return new;
}

intNode * createIntNodes(int nodeSize){
//	intNode  list[]= malloc(nodeSize*sizeof(intNode));
//	intNode list[nodeSize];
//	return list;
//	return list;
}

int containDuplicate(int* nums,int numsSize){
//bool containDuplicate(int * nums, int numsSize){
	int i;
	intNode * list=createIntNode();
//	intNode * lists=createIntNodes(numsSize);
	intNode lists[numsSize];
	list->data=nums[0];
	list->next=0;
	list->previous=0;
	intNode * temp;
	intNode * root;
	root=list;
	for(i=1;i<numsSize;i++){
//	printf("iterate : %d , nums: %d, list->data: %d \n",i,nums[i],list->data);
		while(list){
			if(nums[i]<list->data){
			//	if(!list->previous){
				temp=&lists[i];
				//temp=createIntNode();
				temp->data=nums[i];	
				insertBefore(list,temp);
				if(!list->previous)
					root=temp;
				break;
			} else if(nums[i]>list->data&&!list->next){
				//temp=lists[i];
				temp=createIntNode();
				temp->data=nums[i];
				insertAfter(list,temp);
				//printf("inside large case. temp->data：%d ，list-> data :%d \n",temp->data,list->data);
				break;
			} else if(nums[i]==list->data) {
			//printf("other case. nums[i]: %d, list->data: %d, root->data :%d . \n",nums[i],list->data, root->data);
			return 1;
			//return true;
			}
		list=list->next;
		}
	list=root;
	}
	return 0;
//	return false;
}			

void moveZeroes(int * nums, int numsSize){
        int cnt=0;
        int i;
        for(i=0;i<numsSize;i++){
                if(nums[i]!=0){
                       // swap(nums,cnt,i);
			nums[cnt]=nums[i];
                        cnt=cnt+1;
                }
        }
	for(i=cnt;i<numsSize;i++){
		nums[i]=0;
	}
}
void swap(int * nums,int i,int j){
       // int temp;
        //temp=nums[i];
        nums[i]=nums[j];
       // nums[j]=temp;
}		
int main(int argc, char* args[]){
	printf("hello\n");
	//int a[10]={0,0,1,1,1,2,2,3,3,4};
	int a[argc-1];
	int i=0;
	int k=3;
	for(i=0;i<argc-1;i++){
		a[i]=atoi(args[i+1]);
		printf("input args: %s,%d \n",args[i+1],a[i]);
	}
//	int result=removeDuplicates(a,argc);
//	rotate(a,argc-1,k);
	//int i=0;
	//int result;
	int result;
//	result=containDuplicate(a,argc-1);
	moveZeroes(a,argc-1);
	for(i=0;i<argc-1;i++){
		printf(" %d \n",a[i]);
	}

//	result=containDuplicate(a,argc-1);
//	printf("result is  %d \n",result); 
}

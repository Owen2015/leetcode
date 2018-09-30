struct ListNode { int val; struct ListNode *next;
};
/*
struct ListNode* reverseList(struct ListNode* head){
 if (head == NULL || head->next == NULL) return head;
	struct ListNode* previous=head;
	struct ListNode* next=head->next;
	struct ListNode* temp=next;
	head->next=0;
	while(*next){
		temp=next->next;
		next->next=previous;
		previous=next;
		next=temp;
	}
	return previous;
}

struct ListNode* reverseListBest(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* first = head; //总是指向新链表的首部。
    struct ListNode* now = head;  //指向当前遍历到的反转前的链表的首节点；
    struct ListNode* next = head; //指针指向 now 节点的下一个节点
    
    first = NULL;
    
    do {
        
        next = now->next;
        now->next = first;
        first = now;
        now = next;
    } while (next != NULL);
    
    return first;
}	

struct ListNode* mergeTwoLists(struct ListNode* l1,struct ListNode* l2){
	struct ListNode* head;
	struct ListNode* p;
//	while(*l1||*l2){
		if(*l1&&!*l2){
			head=l1;
			return head;	
		}
		if(!*l1&&*l2){
			head=l2;
			return head;
		}

		if(*l1&&*l2){
			head=l1;
			if(l1->val>l2->val){
				head=l2;	
				l2=l2->next;
			}else{
				l1=l1->next;
			}
		}
//	}
	p=head;
	while(*l1||*l2){
		if(*l1&&*l2){
			p->next=l1;
			if(l1->val>l2->val){
				p-next=l2;	
				l2=l2->next;
				p=p->next;
			}else{
				l1=l1->next;
				p=p->next;
			}
		}
		if(*l1&&!*l2){
			p-next=l1;
			return head;	
		}
		if(!*l1&&*l2){
			p-next=l2;
			return head;
		}
	}
	return head;
}
	
struct ListNode* mergeTwoListsBest(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* next = result;
    
    if (l1 == NULL && l2 == NULL) return NULL;
    
    if (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            result->val = l1->val;
            l1 = l1->next;
        }
        else {
            result->val = l2->val;
            l2 = l2->next;
        }
    }
    else {
        if (l1 != NULL) {
            result->val = l1->val;
            l1 = l1->next;
        }
        else {
            result->val = l2->val;
            l2 = l2->next;
        }
    }
    

    next = result;
    
    while (l1 != NULL && l2 != NULL) {
        next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        next = next->next;
        if (l1->val < l2->val) {
            next->val = l1->val;
            l1 = l1->next;
        }
        else {
            next->val = l2->val;
            l2 = l2->next;
        }
    }
    
    while (l1 != NULL) {
        next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        next = next->next;
        next->val = l1->val;
        l1 = l1->next;
    }
    
    while (l2 != NULL) {
        next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        next = next->next;
        next->val = l2->val;
        l2 = l2->next;
    }
    
    next->next = NULL;
    return result;
}

int isPalindrome( struct ListNode* head) {
    if(head==0) return 1;
    int size=0;
    while(head!=0){
        size++;
        head=head->next;
    }

    int a[size];
    int i=0;
    while(head==0){
        a[i]=head->val;
        i++;
	head=head->next;
    }
    for(i=0;i<size/2;i++){
        if(a[i]!=a[size-i-1]){
            return 0;
        }
    }
    return 1;
}

bool isPalindromeBest(struct ListNode* head) {
    int* arr = (int*)malloc(sizeof(int)*100000);
	int i = 0;
	struct ListNode* curr = head;
	while (curr)
	{
		arr[i++] = curr->val;
		curr = curr->next;
		
	}
	for (int m = 0, n = i - 1; m < n; m++, n--)
	{
		if (arr[m] != arr[n])
			return false;
	}
	return true;

}

bool hasCycle(struct ListNode *head) {
    struct ListNode * slow=head;
    struct ListNode* fast=head;
    if(head==NULL ||head->next==NULL) return false;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast!=NULL){    
            fast=fast->next;
            if(slow==fast) return true;
        }
    }
    return false;
        
}
*/
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* head2=head->next;
    struct ListNode* run=head->next;
    struct ListNode* head1=head;
    while(head->next!=0){
        run=head->next;
        if(run->next==0) break;
        head->next=run->next;
        head=head->next;
        run->next=head->next;
	printf("head: %d ,head->val: %d, head->next: %d \n",head,head->val,head->next);
    }
    head->next=head2;
    return head1;
}


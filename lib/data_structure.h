struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct ListNode {
	void * val;
	struct ListNode *next;
}
/*
struct Queue {
	struct TreeNode *head;
	struct TreeNode *tail;
}*/

struct LinkListNode {
        void * data;
        struct LinkListNode *next;
}*head,*tail;

void enqueue(struct LinkListNode* tail, struct LinkListNode* node){
        if(tail!=NULL){
                tail->next=node;
                tail=node;
        }
}

struct LinkListNode* dequeue(struct LinkListNode* head){
        struct LinkListNode* result;
        if(head!=NULL){
                result=head;
                head=head->next;
        }
        return result;
}
 
int size(struct LinkListNode* head){
    int size=0;
    while(head!=NULL){
        head=head->next;
        size++;
    }
    return size;
}

int isEmpty(struct LinkListNode* head){
    if(head!=NULL){
        return 0;
    }else{
        return 1;
    }
}

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct LinkListNode {
        void * data;
        struct LinkListNode *next;
}*head,*tail;

void enqueue(struct LinkListNode* tail, struct LinkListNode* node){
        if(tail!=0){
                tail->next=node;
                tail=node;
        }
}

struct LinkListNode* dequeue(struct LinkListNode* head){
        struct LinkListNode* result;
        if(head!=0){
                result=head;
                head=head->next;
        }
        return result;
}
 
int size(struct LinkListNode* head){
    int size=0;
    while(head!=0){
        head=head->next;
        size++;
    }
    return size;
}

int isEmpty(struct LinkListNode* head){
    if(head!=0){
        return 0;
    }else{
        return 1;
    }
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    
    struct LinkListNode* node;
    struct LinkListNode head1;
    head=&head1;
    head->data=root;
    tail=head;
    int levelSize=0;
    int levelNums=0;
    struct TreeNode* treeNode;
    struct TreeNode* left;
    struct TreeNode* right;
    while(head!=0){
        levelSize=size(head);
        int levelData[levelSize];
        columnSizes[levelNums++]=levelData;
        int cnt=0;
	printf("iterate: %d",levelNums);
        while(levelSize>0){
            node=dequeue(head);
            treeNode=node->data;
            levelData[cnt]=treeNode->val;
            cnt++;
            if(treeNode->left!=0){
                left=treeNode->left;
                struct LinkListNode newNode;
                newNode.data=left;
                enqueue(tail,&newNode);
                
            }
            if(treeNode->right!=0){
                right=treeNode->right;
                struct LinkListNode newNode;
                newNode.data=right;
                enqueue(tail,&newNode);
            }
         levelSize--;   
        }
    }
          return columnSizes;
}

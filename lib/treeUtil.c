struct TreeNode {
	int val;
	s
	struct TreeNode *right;
}
int maxDepth(struct TreeNode* root){
	if(root==NULL) return 0;
	else return maxDepthRecursive(root,0);
}
int maxDepthRecursive(struct TreeNode* root, int cnt){
	cnt++;
	int left=cnt;
	int right=cnt;
	if(root->left!=NULL){
		left=maxDepthRecursive(root->left,cnt);
	}
	if(root->right!=NULL){
		right=maxDepthRecursive(root->right,cnt);
	}
	return left>right?left:right;
}

int maxDepthBest(struct TreeNode* root) {
    int max,l,r;
    if(!root) return 0;
    //max = l = r = 0;
    l = maxDepth(root->left);
    r = maxDepth(root->right);
    max = l>r?l:r;
    return max+1;
 }

int isValidBST(struct TreeNode* root){	
        if(root==NULL) return 1;
        struct TreeNode* left_p;
        struct TreeNode* right_p;
        int mid=root->val;
        int right,left,state,state_l,state_r,valid_l,valid_r,state_temp;
        if(root->left!=NULL) {
                left_p=root->left;
                left=left_p->val;
                if(left<mid) valid_l=1;
                else valid_l=0;
        }else{
                valid_l=1;
        }
        if(root->right!=NULL) {
                right_p=root->right;
                right=right_p->val;
                if(mid<right) valid_r=1;
                else valid_r=0;
        }else {
                valid_r=1;
        }
        state=valid_l<valid_r?valid_l:valid_r;
        state_l=isValidBST(root->left);
        state_r=isValidBST(root->right);
        state_temp=state<state_l?state:state_l;
        return state_temp<state_r?state_temp:state_r;
}
int isValidBSTT(struct TreeNode* root, int val,int flag){
	if(root==NULL) return 1;
	struct TreeNode* left_p;
	struct TreeNode* right_p;
	int mid=root->val;
	int right,left,state,state_l,state_r,valid_l,valid_r,valid_all,state_temp;
        if(root->left!=NULL) {
                left_p=root->left;
                left=left_p->val;
		if(flag==0){
               		 if(left<mid&&left<val) valid_l=1;
                	else valid_l=0;
		}else{
		        if(left<mid&&left>val) valid_l=1;
                        else valid_l=0;
		}
        }else{
                valid_l=1;
        }
        if(root->right!=NULL) {
                right_p=root->right;
                right=right_p->val;
		if(flag==0){
               		 if(mid<right&&right<val) valid_r=1;
                	else valid_r=0;
		}else{
			 if(mid<right&&right>val) valid_r=1;
                        else valid_r=0;
		}
        }else {
                valid_r=1;
        }
        state=valid_l<valid_r?valid_l:valid_r;
        state_l=isValidBSTT(root->left,root->val,0);
        state_r=isValidBSTT(root->right,root->val,1);
        state_temp=state<state_l?state:state_l;
        return state_temp<state_r?state_temp:state_r;
}

static struct node *prev = NULL;

bool isBST(struct node* root)
{
    // traverse the tree in inorder fashion and keep track of prev node
        if (root)
        {
          if (!isBST(root->left))
              return false;
    
                                       // Allows only distinct valued nodes
          if (prev != NULL && root->data <= prev->data)
               return false;
  
          prev = root;

           return isBST(root->right);
           }
    
         return true;
  }

int maxValue(struct TreeNode* root){
	while(root->right!=NULL){
		root=root->right;
	}	
	return root->val;
}

int minValue(struct TreeNode* root){
	while(root->left!=NULL){
		root=root->left;
	}
	return root->val;
}

int** levelOrder(struct TreeNode* root, int** columnSizes,int* returnSize){
    
    struct ListNode node;
    struct ListNode head1;
    head=&head1;
    head->data=root;
    tail=head;
    int levelSize=0;
    int levelNums=0;
    struct TreeNode* treeNode,left,right;
    while((head!=NULL){
        levelSize=size(head);
        int levelData[levelSize];
        columnSizes[levelNums++]=levelData;
        
        while(levelSize>0){
            node=dequeue(tail);
            treeNode=node->data;
            if(treeNode->left!=NULL){
                left=treeNode->left;
                struct ListNode newNode;
                newNode.data=left;
                enqueue(head,&newNode);
            }
            if(treeNode->right!=NULL){
                right=treeNode->right;
                struct ListNode newNode;
                newNode.data=right;
                enqueue(head,&newNode);
            }
         levelSize--;   
        }
    }    
}


/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     struct TreeNode *left;
 *      *     struct TreeNode *right;
 *       * };
 *        */
/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result=(int*)malloc(sizeof(int));;
    int cnt=0;
    traversalUtil(root,&cnt,result);
    *returnSize=cnt;
    return result;
}

void traversalUtil(struct TreeNode* root, int* returnSize,int* result){
    if(root!=0){
        traversalUtil(root->left,returnSize,result);
        result=(int*)realloc(result,sizeof(int)*(*returnSize+1));
        result[*returnSize]=root->val;
         *returnSize=*returnSize+1;
        traversalUtil(root->right,returnSize,result);
    }
}



/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     struct TreeNode *left;
 *      *     struct TreeNode *right;
 *       * };
 *        */
int getInorderIndex(int* inorder,int inorderSize,int val){
    int i=0;
    for(i=0;i<inorderSize;i++){
        if(inorder[i]==val)
            return i;
    }
    return i;
}

struct TreeNode* buildTreeUtil(int* preorder,int preL,int preR,int* inorder,int inL,int inR,int inorderSize){
    if(preL>preR||inL>inR)
            return 0;
    struct TreeNode* root=malloc(sizeof(struct TreeNode));
        root->val=preorder[preL];
    int index=getInorderIndex(inorder,inorderSize,root->val);
    root->left=buildTreeUtil(preorder,preL+1,index-inL+preL,inorder,inL,index-1,inorderSize);
    root->right=buildTreeUtil(preorder,preL+index-inL+1,preR,inorder,index+1,inR,inorderSize);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorder==0||inorder==0) return 0;
    if(preorderSize==0||inorderSize==0) return 0;
    return buildTreeUtil(preorder,0,preorderSize-1,inorder,0,inorderSize-1,inorderSize);
}



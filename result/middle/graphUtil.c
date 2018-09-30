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
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
	if (preorderSize != 0)
	{
		/*建立根节点*/
		struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		if (!root)
		{
			return NULL;
		}
		root->val = *preorder;
		if (preorderSize == 1)
		{
            root->left = NULL;
			root->right = NULL;
			return root;
		}
		/*计算左子数节点个数*/
		int i = 0;
		for (i = 0; i < preorderSize - 1; i++)
		{
			if (inorder[i] == preorder[0])
			{
				break;
			}
		}
		root->left = buildTree(preorder + 1, i, inorder, i);
		root->right = buildTree(preorder + 1 + i, preorderSize - i - 1, inorder + 1 + i, inorderSize - i - 1);
		return root;
	}
	else
	{
		return NULL;
	}
}


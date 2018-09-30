
bool isTree(struct TreeNode *node,int min,int max)
{
	 if (node == NULL) return true;
    if (node->val < min || node->val > max) return false;
    if (node->left != NULL && node->val == INT_MIN) return false;
    if (node->right != NULL && node->val == INT_MAX) return false;
    return isTree(node->left, min, node->val - 1) && isTree(node->right, node->val + 1, max);
}

bool isValidBST(struct TreeNode* root) {
	if (!root)
		return true;
    if(root->left==NULL && root->right ==NULL)
        return true;
	return isTree(root, INT_MIN, INT_MAX);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int result;
void BST1(struct TreeNode*root, int *k)
{
    static int counter = 0;
    if(root == NULL)
    {
        return;
    }
    else
    {
        BST1(root->left,k);
        (*k)--;
        if(*k == 0)
        {
            result = root->val;
            return;
        }
        BST1(root->right,k);  
    }
}
int cmp(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}
int kthSmallest(struct TreeNode *root, int k) 
{
   BST1(root,&k);
   return result;
}

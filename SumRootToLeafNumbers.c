/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 void SumSolution(struct TreeNode* r, int *FinalResult, int temp)
 {
    temp = (10*temp) + r->val;
    if((r->left == NULL) && (r->right == NULL))     // leaf is found 
    {
        *FinalResult += temp;    // sum of all branches, which we reached to its leaf    
    }
    if(r->left != NULL)
    {
        SumSolution(r->left, FinalResult, temp);
    }
    if(r->right != NULL)
    {
        SumSolution(r->right, FinalResult, temp);  
    }
 }  
int sumNumbers(struct TreeNode* root) 
{
    int ans = 0;
    SumSolution(root,&ans,0);
    return ans;
}
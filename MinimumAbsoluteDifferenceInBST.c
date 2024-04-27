
  struct TreeNode 
  {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
  };
 
 int InOrder(struct TreeNode* root, int *min, int *PreVal)
 {

        if(root->left != NULL)
        {
            InOrder(root->left, min, PreVal); 
        }
        if(*min > abs(*PreVal - root->val))
        {
            *min =  abs(*PreVal - root->val);
        }
        *PreVal = root->val;
        if(root->right != NULL)
        {
            InOrder(root->right, min, PreVal);
        }
        return *min;
 }
int getMinimumDifference(struct TreeNode* root) 
{
    int PreviousValue = 100001;
    int Min = 100001;
    int result = InOrder(root, &Min, &PreviousValue);
    return result;
}
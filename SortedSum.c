#include <stdio.h>
#include <stdlib.h>

long int Order = 1;

#define size 10

typedef struct Node{
    long long int value;
    struct Node *left;
    struct Node *right;
}node;

static node * root = NULL;


node * Insert(node *, int);
void PreOrder(node *);
void BST(long long int );
long long int Inorder(node *);
//////////////////////////////////////////////////////////// main ///////////////////////////////////////////////
int main(void)
{
    long long int arr[size] = {726610,5429,998092,203911, 48773, 897342 , 163057, 930001, 83522, 945114};
    int i = 0;
    long long int ans = 0;
    for(i = 0; i < size; i++)
    {
        BST(arr[i]);
        ans += Inorder(root);

        Order = 1;// reset value 
    }
    printf("ans  = %lld", ans);
    return 0;
}
////////////////////////////////////////////////////////////// definations ///////////////////////////////
void BST(long long int item)
{
    root = Insert(root, item);
}

node * Insert(node * r, int item)
{
    if(r == NULL)
    {
        node * newnode = (node*)malloc(sizeof(node));
        newnode->value = item;
        newnode->left = NULL;
        newnode->right = NULL;
        r = newnode;
    }
    else 
    {
        if(item < r->value)
        {
            r->left = Insert(r->left, item);
        }
        else
        {
            r->right = Insert(r->right, item);
        }
    }
    return r;
}

long long int Inorder(node * r)
{
    long long int res1 = 0;
    long long int res2 = 0;
    long long int res3 = 0;
    long long int Sum_Result = 0;

    if(r == NULL)
    {
        return 0;
    }
    else
    {
        res1 = Inorder(r->left); 
        res2 = Order * r->value;
        Order++;
        res3 = Inorder(r->right);
        Sum_Result = res1 + res2 + res3;

    }
    return Sum_Result;
}



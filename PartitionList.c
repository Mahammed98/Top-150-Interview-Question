/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
    Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    You should preserve the original relative order of the nodes in each of the two partitions.

    Example 1:
    Input: head = [1,4,3,2,5,2], x = 3
    Output: [1,2,2,4,3,5]

    Example 2:
    Input: head = [2,1], x = 2
    Output: [1,2]
    
    Constraints:
    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200
*/
struct ListNode* partition(struct ListNode* head, int x) 
{
    int GreaterX[200] = {0};
    int SmallerX[200] = {0};
    int TopG = -1;
    int TopS = -1;
    struct ListNode* ptr = head;
    struct ListNode* result = NULL;
    struct ListNode* PtrResult = NULL;
    while(ptr != NULL)
    {
        if(ptr->val < x)
        {
            SmallerX[++TopS] = ptr->val;
        }
        else
        {
            GreaterX[++TopG] = ptr->val;
        }
        ptr = ptr->next;
    }
    for(int i = 0; i <= TopS; i++)
    {
        if(result == NULL)
        {
            result = (struct ListNode*)malloc(sizeof(struct ListNode));
            PtrResult = result;
        }
        else
        {
            PtrResult->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            PtrResult = PtrResult->next;
        }
        PtrResult->val = SmallerX[i];
        PtrResult->next = NULL;
    }
    for(int i = 0; i <= TopG; i++)
    {
        if(result == NULL)
        {
            result = (struct ListNode*)malloc(sizeof(struct ListNode));
            PtrResult = result;
        }
        else
        {
            PtrResult->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            PtrResult = PtrResult->next;
        }
        PtrResult->val = GreaterX[i];
        PtrResult->next = NULL;
    }
    return result;
}
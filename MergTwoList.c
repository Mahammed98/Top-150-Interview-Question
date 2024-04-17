/*
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists into one sorted list. 
    The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
 
Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.


*/
struct ListNode {
    int val;
    struct ListNode *next;
 };
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    struct ListNode *Head = NULL;
    struct ListNode *Ptr1 = list1;      // for travers for list1
    struct ListNode *Ptr2 = list2;      // for travers for list2 
    struct ListNode *Temp = NULL;       // for travers for result List

    while(Ptr1 != NULL || Ptr2 != NULL)
    {
        if(!Head) // first node is created 
        {
            Head = (struct ListNode*)malloc(sizeof(struct ListNode));
            Temp = Head;
            Temp->next = NULL;
        }
        if(Ptr1 != NULL && Ptr2 == NULL)
        {
            Temp->val = Ptr1->val;
            Ptr1 = Ptr1->next;
            if(Ptr1)    // if another value is existing , we need to add new node
            {
                Temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                Temp = Temp->next;
                Temp->next = NULL;
            }
            
        }
        else if(Ptr2 != NULL && Ptr1 == NULL)
        {
            Temp->val = Ptr2->val;
            Ptr2 = Ptr2->next;
            if(Ptr2)     //if another value is existing , we need to add new node
            {
                Temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                Temp = Temp->next;
                Temp->next = NULL;
            }
        }
        else
        {
            if(Ptr1->val == Ptr2->val)
            {
                Temp->val = Ptr1->val;
                Temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                Temp = Temp->next;
                Temp->val = Ptr2->val;
                Ptr2 = Ptr2->next;
                Ptr1 = Ptr1->next;
            }
            else if(Ptr1->val < Ptr2->val)
            {
                Temp->val = Ptr1->val;
                Ptr1 = Ptr1->next;
            }
            else
            {
                Temp->val = Ptr2->val;
                Ptr2 = Ptr2->next;

            }
            if(Ptr1 != NULL || Ptr2 != NULL)  // if one of them not equal null
            {                                 // so we need to creat a new node
                Temp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                Temp = Temp->next;
            }
            Temp->next = NULL;
        }
    }
    return Head;
}
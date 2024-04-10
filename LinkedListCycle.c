/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /*
    we will use the value as a indicator 
    each value in linked list, we come in we gonna add 100001 or -100001 to it
    which (100000) is the maximum value you can reach it, and add 1 to it 
    so we check the values in linked list, if the value is added 100001 to it or not
    if yes, so there is a cycle in linked list

*/
bool hasCycle(struct ListNode *head) 
{
    struct ListNode *ptr = head;
    bool flag = 0;
    while(ptr != NULL)
    {
        if((ptr->val < -100000) || ptr->val > 100000)
        {
            flag = 1;
            break;
        }
        else
        {
            if(ptr->val < 0)
            {
                ptr->val -= 100001;
            }
            else
            {
                ptr->val += 100001;
            }
        }
        ptr = ptr->next;
    }
    return flag;
}
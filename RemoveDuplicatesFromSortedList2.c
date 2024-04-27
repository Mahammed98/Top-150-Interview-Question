/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode* PtrCurr = head; // for traversing a head node(input node )
    struct ListNode* PtrResult;     // for traversing a result node
    struct ListNode* HeadResult = NULL;
    int PreValue = -101;   // for storing cuurent value if it equals to next value 

    if(head == NULL)     // no node exist
    {
        return NULL;
    }
    else if (head->next == NULL)      // if one node exist
    {
        HeadResult = (struct ListNode*)malloc(sizeof(struct ListNode));
        PtrResult = HeadResult;
        PtrResult->val = PtrCurr->val;
        PtrResult->next = NULL;     

    }
    else 
    {
        while(PtrCurr != NULL)
        {
            if(PtrCurr->next != NULL)
            {
                if((PtrCurr->val != PtrCurr->next->val) && (PtrCurr->val != PreValue))
                {
                    if(!HeadResult)   // first time creating new list
                    {
                        HeadResult = (struct ListNode*)malloc(sizeof(struct ListNode));
                        PtrResult = HeadResult;
                    }
                    else 
                    {
                        PtrResult->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                        PtrResult = PtrResult->next; 
                    }
                    PtrResult->val = PtrCurr->val;     
                    PtrResult->next = NULL; 
                }
                else
                {
                    PreValue = PtrCurr->val;   // store value which equal to next value 
                }
            }
            else if(PtrCurr->val != PreValue)
            {
                if(!HeadResult)   // first time creating new list
                {
                    HeadResult = (struct ListNode*)malloc(sizeof(struct ListNode));
                    PtrResult = HeadResult;
                }
                else 
                {
                    PtrResult->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                    PtrResult = PtrResult->next; 
                }
                PtrResult->val = PtrCurr->val;     
                PtrResult->next = NULL;      

            }
            PtrCurr = PtrCurr->next;
        }
    }
    
    return HeadResult;
}


struct ListNode {
     int val;
    struct ListNode *next;
 };
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) 
{
    int counter = 1;
    struct ListNode *rptr = head;
    struct ListNode *lptr = head; 
    int *StoreArr = (int*)malloc(sizeof(int) * (right - left + 1));
    int ArrItr = 0;
    /*
        this loop for storing valus from left position to right into StorArr
        and also, to make lptr and rptr point to left and right position
    */
    while(counter <= right)
    {
        if(counter < left)
        {
            lptr = lptr->next;
        }
        else if(counter >= left)
        {
            StoreArr[ArrItr++] = rptr->val;
        }

        if(counter < right)
        {
            rptr = rptr->next;
        }
        counter++;
    }
    /*
        after ending the first loop, we have a valus from left and right positions
        so, the last element in the array which is in right position, and first
        element is in left positon
        finaly, we use this loop to change val for linked lists from l to r
        by using lptr which pointed in left position 
    */
    while(ArrItr != 0)
    {
        lptr->val = StoreArr[--ArrItr];
        lptr = lptr->next;
    }

    free(StoreArr);
    return head;
}
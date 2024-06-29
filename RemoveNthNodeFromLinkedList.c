struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    if (head == NULL || n <= 0) 
    {
        return head;
    }
    struct ListNode* ptr = head;
    struct ListNode* Temp = head;
    struct ListNode* NextNode = NULL;
    int counter = 0;
    int i = 1;
    /*
        first calculate number of nodes
    */
    while(ptr != NULL)
    {
        ptr = ptr->next;
        counter++;
    }

    if(n == counter) // delete the head
    {
        head = head->next;
        free(Temp);
    }
    else
    {
        while(i < (counter-n))
        {
            Temp = Temp->next;
            i++;
        }
        NextNode = Temp->next;
        Temp->next = Temp->next->next;
        free(NextNode);
    }
    return head;
}
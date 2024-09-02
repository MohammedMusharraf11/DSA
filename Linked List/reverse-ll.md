## Reversing a Linked List:
```
ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next ==NULL){
            return head;
        }
        ListNode * prev = NULL;
        ListNode * front = NULL;
        ListNode* temp = head;

        while(temp!=NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
        
    }
```

## Reversing a Doubly Linked List:
```
ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next ==NULL){
            return head;
        }
    ListNode * prev = NULL;
    ListNode * temp = head;
    while(temp!=NULL){
        prev = temp->back;
        temp->back = temp->next;
        temp->next = prev;
    }

    return prev->back;
}
```

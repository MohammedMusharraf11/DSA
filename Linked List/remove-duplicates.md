## Optimized Solution:
```
ListNode* deleteDuplicates(ListNode* head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * temp = head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val == temp->next->val){
                ListNode * duplicate = temp->next;
                temp->next = duplicate->next;
                delete duplicate;
            }else{
                temp = temp->next;
            }
        }

        return head;
```

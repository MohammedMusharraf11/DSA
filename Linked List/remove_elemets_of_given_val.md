## Problem:
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

## Optimized Solution:
  ```
ListNode* removeElements(ListNode* head, int val) {
        // if(head==NULL || head->next==NULL){
        //     if(head->val==val){
        //         return NULL;
        //     }
        //     return head;
        // }

        ListNode * dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode * temp = dummyNode;

       

        while(temp->next!=NULL){
            if(temp->next->val==val){
                temp->next = temp->next->next; 
            }
            else{
                temp = temp->next;
            }
        }
        return dummyNode->next;
    }
```

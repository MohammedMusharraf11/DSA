## Problem:
You are given a Singly Linked List of integers. You have to return true if the linked list is palindrome, else return false.



A Linked List is a palindrome if it reads the same from left to right and from right to left.



Example:
The lists (1 -> 2 -> 1), (3 -> 4 -> 4-> 3), and (1) are palindromes, while the lists (1 -> 2 -> 3) and (3 -> 4) are not.

## Optimzied Solution:

```
Node * reverse(Node * head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node * newHead = reverse(head->next);
    Node * front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(Node *head)
{
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node * slow = head;
    Node * fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node * newHead = reverse(slow->next);
    Node * first = head;
    Node * second = newHead;

    while(second->next!=NULL){
        if(first->data!=second->data){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;


}
```
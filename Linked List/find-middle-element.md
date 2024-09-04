## Problem Statement:

Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.

## Brute Force:

```
temp = head;
count =0;

while(temp!=NULL){
    count++;
    temp = temp->next;
}

midNode = (count/2) + 1 ;
temp = head
while(temp!=NULL){
    midNode--;
    if(midNode==0){
        break;
    }
    temp = temp->next;
}

return temp;
```

## Brute Force:

``` Node * slow = head;
    Node * fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // Write your code here
    return slow;
```
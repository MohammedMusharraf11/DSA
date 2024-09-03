## Problem Statement:
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

Note:

The given linked lists may or may not be null.
For example:

If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL

## BruteForce:

Iterate both the lists and store the elements of both the list in a array and then apply a sorting operation. Now make a new linked list and insert the elements of LL and return head

## Optimized Code:
```
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)

{

Node<int> * t1 = first;
Node<int> * t2 = second;
Node<int> * dummyNode = new Node<int>(-1);
Node<int> * temp = dummyNode;

while(t1!=nullptr && t2!=nullptr){
    if(t1->data < t2->data){
        temp->next = t1;
        temp = t1;
        t1 = t1->next;
    } else{
        temp->next = t2;
        temp = t2;
        t2 = t2->next;
    }

   
}



if(t1) temp->next = t1;
else  temp->next = t2;

return dummyNode->next;
}

```
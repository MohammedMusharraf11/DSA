# Hashing Overview

Hashing is a technique used in data structures to efficiently store and retrieve data. It is particularly useful for enabling quick access to information based on its key.
The most popular use for hashing is the implementation of `hash tables`

![image](https://github.com/user-attachments/assets/f8d5b85a-1679-4a7d-b8c5-23333a83036f)

## Collision in Hashing
A collision occurs when two or more keys produce the same hash value, meaning they are mapped to the same index in the hash table.

## Collision Resolution Techniques
There are two primary methods to handle collisions in hashing:

- Open Addressing (Closed Hashing)
- Separate Chaining (Open Hashing)

![image](https://github.com/user-attachments/assets/80697bc3-efd0-4ac2-aa1d-0c5123062ca0)

```sql
Start
  |
  |----> Compute hash for key
  |
  |----> Is the slot occupied?
            |
            |----> No: Insert the key in the slot
            |
            |----> Yes: Handle Collision
                        |
                        |----> Is the method "Open Addressing"?
                                |
                                |----> Yes: Choose Probing Method
                                        |
                                        |----> Linear Probing
                                        |----> Quadratic Probing
                                        |----> Double Hashing
                                |
                                |----> No: Separate Chaining
                                        |
                                        |----> Insert key in linked list
            |
            |----> Is Load Factor > Threshold?
                        |
                        |----> Yes: Rehash the table (resize and rehash keys)
```

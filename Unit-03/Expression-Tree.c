#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10

typedef struct treeNode {
    int utype; // 1 = Operand, 2 = Operator
    union {
        char operator;
        float operand;
    } u;
    struct treeNode *left;
    struct treeNode *right;
} NODE;

static int top = -1;

// Push a node onto the stack
void push(NODE *Exptree, NODE *stack[]) {
    if (top < MAX - 1) {
        stack[++top] = Exptree;
    } else {
        printf("Stack is full\n");
    }
}

// Pop a node from the stack
NODE *pop(NODE *stack[]) {
    if (top == -1) {
        printf("Stack is empty\n");
        return NULL;
    }
    return stack[top--];
}

// Create an expression tree from a postfix expression
NODE *createExpTree(char postfix[]) {
    NODE *stack[MAX];
    NODE *temp;
    
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            temp = (NODE *)malloc(sizeof(NODE));
            temp->utype = 1; // Operand
            temp->u.operand = postfix[i] - '0'; // Convert char to float
            temp->left = NULL;
            temp->right = NULL;
            push(temp, stack);
        } else {
            temp = (NODE *)malloc(sizeof(NODE));
            temp->utype = 2; // Operator
            temp->u.operator = postfix[i]; // Correct field for operator
            temp->right = pop(stack);
            temp->left = pop(stack);

            if (temp->left == NULL || temp->right == NULL) {
                printf("Invalid postfix expression\n");
                free(temp);
                return NULL;
            }

            push(temp, stack);
        }
        i++;
    }
    return pop(stack);
}

// Calculate the result of applying an operator
float calculate(float x, char op, float y) {
    float result;
    switch (op) {
        case '+': result = x + y; break;
        case '-': result = x - y; break;
        case '*': result = x * y; break;
        case '/': 
            if (y == 0) {
                printf("Division by zero\n");
                exit(1);
            }
            result = x / y;
            break;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
    return result;
}

// Evaluate the expression tree
float evaluate(NODE *root) {
    if (root->utype == 1) {
        return root->u.operand;
    }
    float leftValue = evaluate(root->left);
    float rightValue = evaluate(root->right);
    return calculate(leftValue, root->u.operator, rightValue);
}

// Print the infix expression (inorder traversal)
void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        if (root->utype == 1) {
            printf("%g ", root->u.operand); // Cleaner output for floats
        } else {
            printf("%c ", root->u.operator);
        }
        inorder(root->right);
    }
}

// Free the memory of the tree
void freeTree(NODE *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char postfix[] = "23*5+";
    NODE *root = createExpTree(postfix);

    if (root == NULL) {
        printf("Failed to create expression tree\n");
        return 1;
    }

    printf("Infix expression is: ");
    inorder(root);
    printf("\n");

    printf("Result is: %g\n", evaluate(root));

    freeTree(root); // Clean up memory
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to push an element onto the stack
void push(char *s, int *t, char x) {
    ++*t;
    s[*t] = x;
}

// Function to pop an element from the stack
char pop(char *s, int *t) {
    char x = s[*t];
    --*t;
    return x;
}

// Function to peek at the top element of the stack
char peep(char *s, int t) {
    return s[t];
}

// Function to return input precedence of operators and parentheses
int input_prec(char ch) {
    switch (ch) {
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '(': return 7;
        case ')': return 0;
        default: return 5;  // Input for operands
    }
}

// Function to return stack precedence of operators and parentheses
int stack_prec(char ch) {
    switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '(': return 0;
        case '#': return -1;
        default: return 6;
    }
}

// Function to reverse the string and swap parentheses
void reverse_string(char *a, char *b) {
    int i = strlen(a) - 1;
    int j = 0;
    while (i >= 0) {
        if (a[i] == ')')
            b[j++] = '(';
        else if (a[i] == '(')
            b[j++] = ')';
        else
            b[j++] = a[i];
        i--;
    }
    b[j] = '\0';
}

// Function to convert infix to postfix
void convert_postfix(char *infix, char *postfix) {
    char s[100];  // Stack
    int top = -1;
    int i = 0, j = 0;
    char ch;

    // Push initial stack value
    push(s, &top, '#');

    // Scan through the infix expression
    while (infix[i] != '\0') {
        ch = infix[i];

        // Pop operators with higher precedence from the stack
        while (input_prec(ch) < stack_prec(peep(s, top))) {
            postfix[j++] = pop(s, &top);
        }

        // If input precedence is higher, push the operator to the stack
        if (input_prec(ch) > stack_prec(peep(s, top))) {
            push(s, &top, ch);
        } else {
            // Handle cases like matching parentheses
            pop(s, &top);
        }
        i++;
    }

    // Pop remaining operators in the stack
    while (peep(s, top) != '#') {
        postfix[j++] = pop(s, &top);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Main function to handle infix to prefix conversion
int main() {
    char infix[100], reverse[100], postfix[100], prefix[100];

    // Input infix expression from the user
    printf("\nEnter a valid Infix expression:\n");
    scanf("%s", infix);

    // Step 1: Reverse the infix expression
    reverse_string(infix, reverse);
    printf("\nThe Reversed String: %s\n", reverse);

    // Step 2: Convert the reversed infix expression to postfix
    convert_postfix(reverse, postfix);
    printf("\nPostfix equivalent of Reversed String: %s\n", postfix);

    // Step 3: Reverse the postfix expression to get the prefix expression
    reverse_string(postfix, prefix);
    printf("\nPREFIX EXPRESSION: %s\n", prefix);

    return 0;
}

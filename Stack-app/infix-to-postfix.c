// Conversion of Infix to Prefix:
// Take Input prefix string
// Reverse the prefix string
// Now convert the reversed prefix string to POSTFIX
// Finally reverse POSTFIX to get ---> Prefix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basic stack operations:

void push(char *s, int *t, char x){
    ++*t;
    s[*t] =x;
}

char pop(char *s , int *t){
    char x = s[*t];
    --*t;
    return x;
}

char peep(char *s, int t){
    return s[t];
}

//  Input precedence

int input_prec(char ch){
    switch (ch)
    {
    case '+': case '-': return 2;
    case '*': case '/': return 4;
    case '(' : return 7;
    case ')' : return 0;
    default: return 5;     // --> Input operands
    }
}

int stack_prec(char ch){
    switch (ch)
    {
    case '+': case '-' : return 1;
    case '/': case '*' : return 3;
    case '(' : return 0;
    case '#' : return -1;
    default: return 6;
    }
}



void reverse_string(char *a, char *b){
    int i = strlen(a) - 1;
    int j = 0;
    // Reverse the string while also swapping parentheses
    while(i>=0){

        if (a[i]==')')
            b[j++] = '(';
        
        else if (a[i]=='(')
            b[j++] = ')';
        
        else
            b[j++] = a[i];
        
        i--;
    }
    b[j] = '\0';
}

void convert_postfix(char * infix , char * postfix){
    char s[100];
    int top = -1;
    int i=0, j=0;
    char ch;

    push(s,&top,'#');

    while(infix[i]!='\0'){
        ch = infix[i];
        while(input_prec(ch) < stack_prec(peep(s,top))){
            postfix[++j] = pop(s,&top);
        }

        if(input_prec(ch) > stack_prec(peep(s,top))){
            push(s,&top,ch);
        }
        else{
            pop(s,&top);
        }
        i++;

    }
    while (peep(s,top)!='#'){
        postfix[++j] = pop(s,&top);
    }
    
    postfix[j] = '\0';
}




int main() {
   char infix[100], reverse[100] , postfix[100], prefix[100];
   printf("\nEnter a valid Infix expression:\n");
   scanf("%s",infix);
   
   reverse_string(infix, reverse);
   printf("\nThe Reversed String: %s\n",reverse);

   convert_postfix(reverse, postfix);
   printf("\nPostfix equivalent of Reversed String: %s\n",postfix);

   reverse_string(postfix, prefix);
   printf("\nPREFIX EXPRESSION: %s\n", prefix);

   
    return 0;
}























#include <stdio.h>
#include <string.h>

void push(char *s , int *t, char x){
    ++*t;
    s[*t] = x;
}

char pop(char *s, int *t){
    return s[(*t)--]; // Here parenthesis is important
}

char peep(char *s , int t){
    return s[t];
}

int input_prec(char ch){
    switch (ch)
    {
    case ')' :              return 0;
    case '+': case '-' :    return 1;
    case '*': case '/' :    return 3;
    case '(':               return 7;
    default:                return 5;

    }
}
int stack_prec(char ch){
    switch (ch)
    {
    case '#':               return -1;
    case '(':               return 0;
    case '+': case '-' :    return 2;
    case '*': case '/' :    return 4;
    default:                return 6;

    }
}



void convert_postfix(char *infix , char *postfix){
    char s[10];
    int i , j;
    i =0 , j= 0;
    int top = -1;
    char ch;
    push(s,&top,'#');
    while (infix[i]!='\0'){
        ch = infix[i];

        while (input_prec(ch) < stack_prec(peep(s,top)))
        {
            postfix[j++] = pop(s,&top);
        }

        if(input_prec(ch) > stack_prec(peep(s,top))){
            push(s,&top,ch);
        }
        else{
            pop(s,&top);
        }
        i++;
    }

    while (peep(s,top)!='#')
    {
        postfix[j++] = pop(s,&top);
    }
    
    postfix[j] = '\0';
    
}





int main(){
char infix[10], postfix[10];
    printf("\nEnter valid Infix Expression\n");
    scanf("%s", infix);
    
    convert_postfix(infix, postfix);  // Call the conversion function
    printf("\nThe postfix equivalent = %s\n", postfix);
    return 0;
}
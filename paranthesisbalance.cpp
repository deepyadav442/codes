#include <stdio.h>
#include <stdlib.h>
typedef struct stack stack;
struct stack {
    char brace ;
    stack * next ;
} *top = NULL ;

void push ( char val )
{
    stack * ptr = (stack *) malloc(sizeof(stack)) ;
    ptr -> brace = val ;
    ptr -> next = top ;
    top = ptr ;
}

char pop ()
{
    stack * ptr ;
    char ch ;
    ptr = top ;
    ch = top -> brace ;
    top = top -> next ;
    free (ptr) ;
    return ch ;
}

char close(char ch)
{
    if(ch==']')
        return '[' ;
    if(ch=='}')
        return '{' ;
    if(ch==')')
        return '(' ;
    return ' ' ;
}
int check_order (char * str)
{
    int i , len = 0 ;
    for(i=0;str[i]!='\0';i++)
        len++ ;
    if(len&1)  // if string length is odd
        return 0 ;
    for(i=0;i<len;i++)
    {
        if(str[i]=='[' || str[i]=='{' || str[i]=='(')
            push(str[i]);
        else {
            if(pop() != close(str[i]))
                return 0 ;
        }
    }
    return 1 ;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    char str[100] ;
    //printf("Enter the string expression: ");
    scanf("%s",str);
    //printf("The expression you entered is: %s .\n",str);
    if( check_order(str) )
        printf("YES\n");
    else printf("NO\n");
    }return 0;
}

#include<stdio.h>
#include<ctype.h>
#include<string.h>
int stack[20];
int top = -1;
void push(int x)
{
    top=top+1;
    stack[top] = x;
}
int pop()
{
    return stack[top--];
}
int main(){
    char exp[20];  
    int len, n1, n2, n3, num, i;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    len= strlen(exp);
    for(i=0;i<len;i++)    
    {
        if(isdigit(exp[i]))
        {
            num = exp[i] - 48;
            push(num);
        }
        else
        {
            n2 = pop();
            n1 = pop();
  switch(exp[i])
            {
            case '+':   n3 = n1+ n2;break;
            
            case '-':   n3 = n1 - n2;break;
            
            case '*': n3 = n1 * n2;break;
            
            case '/':   n3 = n1 / n2;break; 
            }
            push(n3);
        }    
    }
    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
    return 0;
}
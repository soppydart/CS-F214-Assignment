/** @file infixToPrefix.c
 *  @brief Contains definition for infix to prefix conversion
 *  @author Saksham Attri
 *  @bug No known bugs.
 */

/* -- Includes -- */

/* libc includes */

#include<stdio.h> 
#include<string.h> /* for using the strlen() and strcpy() functions */ 
#include<limits.h> 
#include<stdlib.h>

int top = -1;

// checking if the stack is full
int isFull(int lenInfix) {
    if(top == lenInfix - 1) return 1;
    else return 0;
} 

// checking if the stack is empty
int isEmpty() {
    if(top == -1) return 1;
    else return 0; 
}

// push function which inserts value in the stack and increments top
void push(char item,int lenInfix,char * stack) {
    if (isFull(lenInfix)) return; 
	top++;
	stack[top] = item;
}

// pop function which removes an item from the stack and decrements top 
int pop(char * stack) { 
    if (isEmpty()) return INT_MIN; 
        
    // decrements top and returns what has been popped      
    return stack[top--]; 
} 

// peek function to return the top of the stack 
int peek(char * stack){ 
    if (isEmpty()) return INT_MIN; 
    return stack[top]; 
} 

// a function to check if the given character is a propositional atom 
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
} 

// priority function to compare priority. It returns a larger value for a higher priority operator   
int priority(char ch) 
{ 
    switch(ch) {
		case '+':
		return 3;
		break;

		case '*':    
		return 4;
		break;

		case '~':        
		return 5;
		break;

        case '>':
        return 2;
        break;

		case '(':       
		case ')':
		return 1;
		break;
	}
    return -1; 
}

// getPostfix function to convert an infix expression to a postfix expression
int getPostfix(char* expression, char * stack, int lenInfix) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        // we check whether the scanned character is an operand or not and add this to the output
        if (checkIfOperand(expression[i])) expression[++j] = expression[i]; 

        // we push '(' to the stack if we scan it
        else if (expression[i] == '(') push(expression[i],lenInfix,stack); 

        // if the scanned character is ')', we need to pop from the stack till '(' is encountered in the stack 
        else if (expression[i] == ')') 
        { 
            while (!isEmpty(stack) && peek(stack) != '(') expression[++j] = pop(stack);
            
            if (!isEmpty(stack) && peek(stack) != '(')return -1; // invalid expression              
            else pop(stack); 
        } 
        else // if the scanned character is an operator
        { 
            while (!isEmpty(stack) && priority(expression[i]) <= priority(peek(stack))) expression[++j] = pop(stack); 
            push(expression[i],lenInfix,stack); 
        } 

    } 

    // Once all inital expression characters are traversed
    // adding all left elements from stack to exp
    while (!isEmpty(stack)) 
        expression[++j] = pop(stack); 

    expression[++j] = '\0'; 
    
}

// a function to reverse a string
void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}

// a function to swap brackets
void brackets(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}

// the function to convert the infix expression into a prefix expression

/** @brief Definition of infixToPrefix() function
 *
 *  Put profiled data here
 */
int infixToPrefix(char *exp, char * stack, char * prefix, int lenInfix)
{

    int size = strlen(exp);

    // reverse string
    reverse(exp);
    // swap brackets
    brackets(exp);
    // get the postfix expression 
    getPostfix(exp,stack,lenInfix);
    // reverse the string again to get the prefix expression
    reverse(exp);
    strcpy(prefix,exp);
    return strlen(exp);
}

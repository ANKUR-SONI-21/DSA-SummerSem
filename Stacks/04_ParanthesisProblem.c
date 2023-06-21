#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

void push(struct Stack *ptr, char data)
{
    if (isFull(ptr))
        printf("Stack Overflow!");
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = data;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Underflow!");
        return 0;
    }
    else
    {
        //! initioalizing a pointer to the top most element is mandatory
        //! but freeing up space can be beneficial
        char *p = &ptr->arr[ptr->top];
        char val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        free(p);
        return val;
    }
}

int peek(struct Stack *ptr, int index)
{
    if (ptr->top - index + 1 < 0)
    {
        printf("Not a valid position");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - index + 1];
    }
}

int stackTop(struct Stack *ptr)
{
    return ptr->arr[ptr->top];
}
//! paranthesis function
int paranthesisMatch(char *exp)
{
    struct Stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
                printf("this expression is not balanced");
            }
            else
            {
                pop(s);
            }
        }
    }
    if (isEmpty(s))
    {
        //! balanced
        return 1;
    }
    else
    {
        //! not balanced
        return 0;
    }
}

//! multiple paranthesis Problem
int multipleParanthesismatch(char *exp)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if ((stackTop(s) == '(' && exp[i] == ')') || (stackTop(s) == '{' && exp[i] == '}') || (stackTop(s) == '[' && exp[i] == ']'))
            {
                pop(s);
            }
            else
            {
                return 0;
                //! unbalanced!
            }
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    else
    {
        //! unbalanced!
        return 0;
    }
}

int main()
{
    char *exp = "(8*)()[}";
    // check if stack is empty
    if (multipleParanthesismatch(exp))
    {
        printf("Paranthesis is Matching!");
    }
    else
    {
        printf("The paranthesis is not matching!");
    }
}
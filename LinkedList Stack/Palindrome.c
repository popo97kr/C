#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char stack[50];
int top = -1;

void push(char c)
{
	stack[++top] = c;
}

char pop()
{
	return(stack[top--]);
}

bool palincheck()
{
	char str[50];
	int len;
	int x;
	int i;

	printf("Enter string : ");
	gets(str);

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if(str[i]>='A' && str[i]<='Z')
			str[i]-=('A'-'a');
	}

	for (i = 0; i < len; i++)
	{
		push(str[i]);
	}

	for (i = 0; i < len; i++)
	{
		if (str[i] == pop())
			x++;
	}

	if (x == len)
		return true;
	else
		return false;
}

bool parencheck()
{
	char str[50];
	int i;
	
	printf("Enter equation : ");
	gets(str);

	int len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if(str[i]=='(')
			push(str[i]);
	}

	for (i = 0; i < len; i++)
	{
		if (str[i] == ')')
			pop();
	}

	if (top==-1)
		return true;
	else
		return false;
}

void main()
{
	printf((palincheck() == true)?"it is a palindrome\n":"it is not a palindrome\n");
	top = -1;
	printf((parencheck() == true)?"it has the right pair of parenthesis\n":"it does not have the right pair of parenthesis\n");
}


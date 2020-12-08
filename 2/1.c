#include <stdio.h>
#include "Stack.h"

int main()
{
	struct Stack* head = newStack();
	head = listOfStrings("input.txt");
	deleteStack(&head);
	return 0;
}
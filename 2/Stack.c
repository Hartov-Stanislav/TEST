#include "Stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 3

typedef struct Stack
{
	char* str;
	struct Stack* next;
};

struct Stack* newStack()
{
	struct Stack* head = NULL;
	return head;
}

struct Stack* addElement(struct Stack* head, char* str)
{
	struct Stack* newElement = malloc(sizeof(struct Stack));
	if (newElement == NULL)
	{
		return 0;
	}
	newElement->next = head;
	newElement->str = str;
	head = newElement;
	return head;
}

bool isEmpty(struct Stack* head)
{
	return head == NULL;
}

char* deleteTop(struct Stack** head)
{
	if (*head == NULL)
	{
		return NULL;
	}
	struct Stack* oldElement = *head;
	*head = oldElement->next;
	free(oldElement);
}

void deleteStack(struct Stack** head)
{
	while (*head != NULL)
	{
		deleteTop(head);
	}
}

struct Stack* stringInStack(struct Stack* head, const char* strNew)
{
	struct Stack* headNew = head;
	while (headNew != NULL)
	{
		int temp = 0;
		for (int i = 0; i < MAX; i++)
		{
			if (headNew->str[i] != strNew[i])
			{
				temp++;
			}
			if (temp != 0) break;
		}
		if(temp == 0)
		{
			return head;
		}
		headNew = headNew->next;
	}
	return addElement(head, strNew);
}

struct Stack* listOfStrings(const char* filename)
{
	FILE* input = fopen(filename, "r");
	if (input == NULL)
	{
		printf("Cannot open file.\n");
		return NULL;
	}
	struct Stack* head = newStack();
	while (!feof(input)) {
		char* buffer = malloc(sizeof(char) * MAX);
		const int readBytes = fscanf(input, "%s", buffer);
		if (readBytes < 0) {
			break;
		}
		head = stringInStack(head, buffer);
	}
	fclose(input);
	return head;
}
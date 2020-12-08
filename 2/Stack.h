#pragma once
#include <stdbool.h>

typedef struct Stack;

struct Stack* addElement(struct Stack* head, char* str);

bool isEmpty(struct Stack* head);

char* deleteTop(struct Stack** head);

void deleteStack(struct Stack** head);

struct Stack* newStack();

struct Stack* stringInStack(struct Stack* head, const char* strNew);

struct Stack* listOfStrings(const char* filename);
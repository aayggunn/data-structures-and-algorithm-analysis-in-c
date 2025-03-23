#include <stdio.h>
#include <stdlib.h>

struct stackNode{
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void PrintStack(StackNodePtr currentPtr);
void instructions(void);

int main(void) {
	
	StackNodePtr stackPtr = NULL;
	int choice;
	int value;
	
	instructions();
	printf("?");
	scanf("%d", &choice);
	
	while(choice != 3){
		switch(choice){
			
			case 1:
				printf("Enter a integer: ");
				scanf("%d", &value);
				push(&stackPtr, value);
				PrintStack(stackPtr);
				break;
				
			case 2:
				if(!isEmpty(stackPtr)){
					printf("The popped value is %d.\n", pop(&stackPtr));
				}
				PrintStack(stackPtr);
				break;
				
			default:
				printf("Invalid choice!\n\n");
				instructions();
				break;
		}
		printf("?");
		scanf("%d", &choice);
	}
	printf("End of run.\n");
	return 0;
}

void instructions(void){
	printf("1 to push a value on the stack.\n");
	printf("2 to pop a value off the stack.\n");
	printf("3 to end program.\n");
}

void push(StackNodePtr *topPtr, int info){
	StackNodePtr newPtr;
	newPtr = malloc(sizeof(StackNode));
	if(newPtr != NULL){
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else{
		printf("%d not inserted. No memory available.\n", info);
	}
}

int pop(StackNodePtr *topPtr){
	StackNodePtr tempPtr;
	int popValue;
	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}

void PrintStack(StackNodePtr currentPtr){
	if(currentPtr == NULL){
		printf("Stack is empty.\n");
	}
	else{
		printf("The stack is: \n");
		while(currentPtr != NULL){
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}

int isEmpty(StackNodePtr topPtr){
	return topPtr == NULL;
}

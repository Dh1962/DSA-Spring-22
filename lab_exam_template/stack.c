#include "stack.h"

#include <stdlib.h>

struct StackNode* getStackNode(int data)
{
  struct StackNode* ret = (struct StackNode*) malloc(sizeof(struct StackNode));
  ret->data = data;
  ret->next = NULL;
  return ret;
}

int pushStack(struct Stack *stack, struct StackNode* node)
{
  if(stack == NULL)
    return 0;
  if(node == NULL)
    return 0;
  node->next = stack->top;
  stack->top = node;
  stack->size++;
  return 1;
}

int popStack(struct Stack* stack)
{
  if(stack == NULL)
    return 0;
  if(stack->top == NULL)
    return 0;
  struct StackNode* ret = stack->top;
  stack->top = stack->top->next;
  stack->size--;
  free(ret);
  return 1;
}

struct StackNode* topStack(struct Stack* stack)
{
  if(stack == NULL)
    return NULL;
  return stack->top;
}

int isStackEmpty(struct Stack *stack)
{
  if(stack->size == 0)
    return 1;
  return 0;
}

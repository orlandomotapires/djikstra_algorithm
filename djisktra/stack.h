#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;     /* position of the top element */
    int capacity; /* capacity of the stack */
    float *elements; /* pointer to the array for stack elements */
};

void create_stack(struct Stack *s, int capacity) {
    s->top = -1; /* initialize top to -1 (empty stack) */
    s->capacity = capacity; /* set the stack's capacity */
    s->elements = (float*) malloc(capacity * sizeof(float)); /* allocate memory for the stack elements */
}

int is_empty(struct Stack *s) {
    if (s->top == -1)
        return 1; /* true, the stack is empty */
    else
        return 0; /* false, the stack is not empty */
}

int is_full(struct Stack *s) {
    if (s->top == s->capacity - 1)
        return 1; /* true, the stack is full */
    else
        return 0; /* false, the stack is not full */
}

void push(struct Stack *s, float value) {
    s->top++; /* increment top to prepare for the push */
    s->elements[s->top] = value; /* store the value at the top position */
}

float pop(struct Stack *s) {
    float temp = s->elements[s->top]; /* retrieve the top element */
    s->top--; /* decrement top to simulate popping */
    return temp;
}

float peek(struct Stack *s) {
    return s->elements[s->top]; /* return the top element without popping it */
}

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int* data;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));
    
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*) malloc(capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! \n");
        return;
    }

    stack->data[++stack->top] = value;
    printf("Pushed %d\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to print the stack in a side-by-side table format
void printStackTable(struct Stack* stack, int step) {
    printf("Step %d:\n", step);
    printf("Index\t\n");
    for (int i = 0; i < stack->capacity; i++) {
        if (i <= stack->top) {
            printf("%d\t", stack->data[i]);  // Print the elements in the stack
        } else {
            printf("-\t");  // Print a placeholder for empty slots
        }
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the Size of Stack you want to create : ");
    scanf("%d",&size);
    struct Stack* stack = createStack(size);

    int num;
    int step = 1;  // Variable to track the current step number

    printStackTable(stack, step);
    printf("Enter the number to be pushed (or 0 to stop): ");
    scanf("%d", &num);
    
    // Push operations
    while (num != 0) {
        push(stack, num);
        printStackTable(stack, step);  // Display the stack after each push
        step++;  // Increment step for each operation
        printf("Enter the number to be pushed (or 0 to stop): ");
        scanf("%d", &num);
    }

    // Display the stack after all push operations
    printf("\nFinal stack after all push operations:\n");
    printStackTable(stack, step);

    // Pop operations
    int popchoice;
    printf("Enter any number to POP(0 to exit):\n");
    scanf("%d", &popchoice);

    while (popchoice != 0)
    {
        printf("\nPopping elements:\n");
        step++;  // Increment step for pop operation
        printf("Popped: %d\n", pop(stack));
        printStackTable(stack, step);  // Display the stack after pop
        printf("Enter any number(0 to exit):\n");
        scanf("%d", &popchoice);
    }
    
    printf("The resulting Stack is :");
    printStackTable(stack, step);

    // Free memory
    free(stack->data);
    free(stack);

    return 0;
}

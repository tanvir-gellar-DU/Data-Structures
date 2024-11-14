#include <stdio.h>

#define MAX_SIZE 5 // Define a maximum queue size

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to add an element to the queue (enqueue)
void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if (isEmpty()) {
        front = 0; // Initialize front for the first element
    }

    rear = (rear + 1) % MAX_SIZE; // Wrap rear around using modulo
    queue[rear] = data;
    printf("Enqueued element: %d\n", data);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }

    int item = queue[front];
    
    if (front == rear) {
        // Queue becomes empty after dequeue
        front = rear = -1;
    } else {
        // Move front to the next position in circular manner
        front = (front + 1) % MAX_SIZE;
    }

    printf("Dequeued element: %d\n", item);
    return item;
}

// Function to display the elements of the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(34);
    enqueue(23);
    enqueue(50);

    displayQueue();  // Output: Queue elements: 10 20 34 23 50

    dequeue();        // Output: Dequeued element: 10
    dequeue();        // Output: Dequeued element: 20

    displayQueue();  // Output: Queue elements: 34 23 50

    enqueue(60);     // Enqueue element after wrapping around
    enqueue(70);     // Enqueue one more to test the circular behavior

    displayQueue();  // Output: Queue elements: 34 23 50 60 70

    return 0;
}

#include <stdio.h>

#define MAX_SIZE 5 // Define a maximum queue size

int queue[MAX_SIZE];
int front = -1;
int rear = -1;


int isEmpty() {
    return front == -1;
}

// Function to check if queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}


void enqueue(int data) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if (isEmpty()) {
        front = 0; 
    }

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
    printf("Enqueued element: %d\n", data);
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }

    int item = queue[front];
    
    if (front == rear) {

        front = rear = -1;
    } else {
     
        front = (front + 1) % MAX_SIZE;
    }

    printf("Dequeued element: %d\n", item);
    return item;
}


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

    displayQueue();  

    dequeue();      
    dequeue();       

    displayQueue();  

    enqueue(60);    
    enqueue(70);    

    displayQueue(); 

    return 0;
}

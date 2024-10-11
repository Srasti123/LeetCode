#include<iostream>
using namespace std;
#include <iostream>
using namespace std;

#define SIZE 5  
class CircularQueue {
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    
    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty()) {
            front = 0; 
        }

        rear = (rear + 1) % SIZE;  
        queue[rear] = value;
        cout << value << " enqueued to the queue\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % SIZE) {
            cout << queue[i] << " ";
        }
        cout << queue[rear] << endl;  // Print the last element (at rear)
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);  
    q.display();

    return 0;
}


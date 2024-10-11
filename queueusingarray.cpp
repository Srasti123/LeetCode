#include<iostream>
using namespace std;

class Queue {
    int front, rear, capacity;
    int* queue;
    
public:
    Queue(int size) {
        capacity = size;
        queue = new int[capacity];
        front = -1;
        rear = -1;
    }
    
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) {  // If queue is empty
            front = 0;
        }
        
        rear = (rear + 1) % capacity;
        queue[rear] = data;
        cout << "Enqueued: " << data << endl;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Dequeued: " << queue[front] << endl;
        if (front == rear) {  // If queue has only one element
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
    
   
    
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;
    
    Queue q(size);
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element: " << q.peek() << endl;
    
    q.dequeue();
    q.dequeue();
    
    q.enqueue(40);
    
    cout << "Front element: " << q.peek() << endl;
    
    q.dequeue();
    q.dequeue();
    
    if (q.isEmpty()) {
        cout << "Queue is empty now!" << endl;
    }
    
    return 0;
}

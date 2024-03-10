#include <iostream>
using namespace std;

class ShiftQueue {
private:
    int* arr;
    int size;
    int front;
    int rear;
    static int counter;

public:
    static int GetCounter() {
        return counter;
    }

    ShiftQueue() {
        counter++;
        front = -1;
        rear = -1;
        size = 5;
        arr = new int[size];
        cout << "ShiftQueue Constructor\n";
    }

    ShiftQueue(int _size) {
        counter++;
        front = -1;
        rear = -1;
        size = _size;
        arr = new int[size];
        cout << "ShiftQueue Constructor\n";
    }

    ~ShiftQueue() {
        counter--;
        for (int i = 0; i < size; i++) {
            arr[i] = -1;
        }
        delete[] arr;
        cout << "ShiftQueue Destructor" << endl;
    }

    void Enqueue(int value) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (IsEmpty()) {
            front = 0;
        }

        rear++;
        arr[rear] = value;
    }

    int Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int dequeuedValue = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            // Shift remaining elements to the left
            for (int i = front; i < rear; i++) {
                arr[i] = arr[i + 1];
            }
            rear--;
        }

        return dequeuedValue;
    }

    bool IsFull() {
        return rear == size - 1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    void PrintQueue() {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int ShiftQueue::counter = 0;

int main() {
    ShiftQueue sq1, sq2(10), sq3;

    sq2.Enqueue(10);
    sq2.Enqueue(20);
    sq2.Enqueue(30);
    sq2.Enqueue(40);
    sq2.Enqueue(50);

    sq2.PrintQueue();

    sq2.Dequeue();

    sq2.PrintQueue();

    cout << ShiftQueue::GetCounter() << endl;

    return 0;
}

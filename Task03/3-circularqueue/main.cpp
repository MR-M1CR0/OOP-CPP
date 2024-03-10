#include <iostream>
using namespace std;

class CircularQueue
{
private:
  int *arr;
  int size;
  int front;
  int rear;
  int itemCount;

public:
  CircularQueue(int _size)
  {
    size = _size;
    front = -1;
    rear = -1;
    itemCount = 0;
    arr = new int[size];
  }

  ~CircularQueue()
  {
    delete[] arr;
  }

  void Enqueue(int value)
  {
    if (IsFull())
    {
      cout << "Queue is full. Cannot enqueue." << endl;
      return;
    }

    if (IsEmpty())
    {
      front = 0;
    }

    rear = (rear + 1) % size;
    arr[rear] = value;
    itemCount++;
  }

  int Dequeue()
  {
    if (IsEmpty())
    {
      cout << "Queue is empty. Cannot dequeue." << endl;
      return -1; // Assuming -1 as an error value
    }

    int dequeuedValue = arr[front];

    if (front == rear)
    {
      // Last element in the queue
      front = -1;
      rear = -1;
    }
    else
    {
      front = (front + 1) % size;
    }

    itemCount--;

    return dequeuedValue;
  }

  bool IsFull()
  {
    return (rear + 1) % size == front;
  }

  bool IsEmpty()
  {
    return front == -1;
  }

  void PrintQueue()
  {
    if (IsEmpty())
    {
      cout << "Queue is empty." << endl;
      return;
    }

    int current = front;
    do
    {
      cout << arr[current] << " ";
      current = (current + 1) % size;
    } while (current != (rear + 1) % size);

    cout << endl;
  }
};

int main()
{
  CircularQueue cq(5);

  cq.Enqueue(10);
  cq.Enqueue(20);
  cq.Enqueue(30);
  cq.Enqueue(40);
  cq.Enqueue(5);

  cq.PrintQueue(); // 10 20 30 40

  cq.Dequeue();
  cq.Dequeue();

  cq.Enqueue(50);
  cq.Enqueue(60);

  cq.PrintQueue(); // 30 40 50 60

  return 0;
}

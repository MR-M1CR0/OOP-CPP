#include <iostream>

using namespace std;

class Stack
{
    int* arr;
    int size;
    int tos;
    static int counter;

public:
    static int GetCounter()
    {
        return counter;
    }

    Stack()
    {
        counter++;
        tos = 0;
        size = 5;
        arr = new int[size];
        cout << "Stack Constructor\n";
    }

    Stack(int _size)
    {
        counter++;
        tos = 0;
        this->size = _size;
        arr = new int[size];
        cout << "Stack Constructor\n";
    }

    ~Stack()
    {
        counter--;
        for(int i = 0; i < size; i++)
        {
            arr[i] = -1;
        }

        delete[] arr;
        cout << "Stack Destructor\n";
    }

    void Push(int value)
    {
        if(!IsFull())
        {
            arr[tos] = value;
            tos++;
        }
        else
        {
            cout << "Full!\n";
        }
    }

    int Pop()
    {
        int RetVal = -1111;
        if(!IsEmpty())
        {
            tos--;
            RetVal = arr[tos];
        }
        else
        {
            cout << "Empty!\n";
        }
        return RetVal;
    }

    int IsFull()
    {
        return tos == size;
    }

    int IsEmpty()
    {
        return tos == 0;
    }

    friend void PrintStack(Stack prm);
};

void PrintStack(Stack prm)
{
    for(int i = 0; i < prm.tos; i++)
        cout << prm.arr[i] << endl;
}

int Stack::counter = 0;

int main()
{
    Stack s1,s2(10),s3;

    s2.Push(10);
    s2.Push(20);
    s2.Push(30);
    s2.Push(40);
    s2.Push(50);

    s2.Pop();

    PrintStack(s2);

    cout<<Stack::GetCounter() << endl;

    PrintStack(s2);
    return 0;
}

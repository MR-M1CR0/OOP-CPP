#include <iostream>
#include <map>

using namespace std;

class Stack
{
private:
  int *arr;
  int size;
  int tos;

public:
  Stack()
  {
    tos = 0;
    size = 5;
    arr = new int[size];
  }

  Stack(int _size)
  {
    tos = 0;
    size = _size;
    arr = new int[size];
  }

  // Copy constructor
//  Stack(const Stack &oldObj)
//  {
//    this->tos = oldObj.tos;
//    this->size = oldObj.size;
//    this->arr = new int[size];
//    for (int i = 0; i < tos; i++)
//    {
//      this->arr[i] = oldObj.arr[i];
//    }
//  }

  // Assignment operator
  Stack &operator=(const Stack &rhs)
  {
    if (this != &rhs)
    {
      // Release existing resources
      delete[] arr;

      this->tos = rhs.tos;
      this->size = rhs.size;
      this->arr = new int[size];
      for (int i = 0; i < tos; i++)
      {
        this->arr[i] = rhs.arr[i];
      }
    }
    return *this;
  }

  ~Stack()
  {
    delete[] arr;
  }

  // Stack Functions
  void Push(int value)
  {
    if (!IsFull())
    {
      arr[tos] = value;
      tos++;
    }
    else
    {
      cout << "FULL !!!" << endl;
    }
  }

  int Pop()
  {
    int retVal = -1234;
    if (!IsEmpty())
    {
      tos--;
      retVal = arr[tos];
    }
    else
    {
      cout << "EMPTY !!!";
    }
    return retVal;
  }

  int IsFull() { return tos == size; }
  int IsEmpty() { return tos == 0; }

  // Reverse the stack
  Stack Reverse() const
  {
    Stack reversedStack(size);
    for (int i = tos - 1; i >= 0; i--)
    {
      reversedStack.Push(arr[i]);
    }
    return reversedStack;
  }

  int operator==(const Stack &other) const
  {
    if (this->tos != other.tos)
    {
      return 0;
    }

    // Create a copy of the other stack to mark elements as found
    Stack otherCopy = other;

    // Check each element in the current stack
    for (int i = 0; i < tos; i++)
    {
      int foundInOther = 0;

      // Check if the current element exists in the other stack
      for (int j = 0; j < otherCopy.tos; j++)
      {
        if (arr[i] == otherCopy.arr[j])
        {
          foundInOther = 1;
          // Mark the element as found in the other stack
          otherCopy.arr[j] = -1; // Assuming -1 is not a valid element in your stack
          break;
        }
      }

      // If the current element is not found in the other stack, return 0
      if (!foundInOther)
      {
        return 0;
      }
    }

    // If all elements are found in the other stack, return 1
    return 1;
  }

  // Overloading + operator to concatenate two stacks
  Stack operator+(const Stack &other) const
  {
    Stack resultStack(this->size + other.size);
    for (int i = 0; i < this->tos; i++)
    {
      resultStack.Push(this->arr[i]);
    }
    for (int i = 0; i < other.tos; i++)
    {
      resultStack.Push(other.arr[i]);
    }
    return resultStack;
  }

  // For learning purpose
  friend void PrintStack(const Stack &param);
};

// Standalone function to View Stack without any change
void PrintStack(const Stack &param)
{
  for (int i = 0; i < param.tos; i++)
  {
    cout << param.arr[i] << endl;
  }
}

int main()
{
  Stack s1, s2(10), s3, s10(10), s20;
  s2.Push(10);
  s2.Push(20);
  s2.Push(30);
  s2.Push(40);
  s2.Push(50);

//  s3 = s2.Reverse();
//  cout << s3.Pop() << endl;
//  cout << s2.Pop() << endl;

  Stack s4 = s2;
  cout << (s4 == s2 ? "Copied Stack is equal to Original Stack\n" : "Copied Stack is not equal to Original Stack\n");

  // Using the assignment operator
//  s1 = s2;
//  cout << (s1 == s2 ? "Assigned Stack is equal to Original Stack\n" : "Assigned Stack is not equal to Original Stack\n");
//
//  // Using the + operator to concatenate two stacks
//  Stack s5 = s1 + s2;
//  cout << "Concatenated Stack:\n";
//  PrintStack(s5);
//
//  s3 = s2.Reverse();
//  cout << (s3 == s2 ? "Yes they equal\n" : "No Not equal\n") << endl;
//
//  s10.Push(10);
//  s10.Push(20);
//  s10.Push(30);
//  s10.Push(20);
//  s10.Push(40);
//
//  s20.Push(20);
//  s20.Push(30);
//  s20.Push(40);
//  s20.Push(10);
//  s20.Push(20); //
//
//  cout << (s10 == s20 ? "Yes they equal\n" : "No Not equal\n") << endl;
  return 0;
}

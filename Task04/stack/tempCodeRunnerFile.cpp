Stack s1, s2(10), s3, s10(10), s20;
  s2.Push(10);
  s2.Push(20);
  s2.Push(30);
  s2.Push(40);
  s2.Push(50);

  s3 = s2.Reverse();
  cout << s3.Pop() << endl;
  cout << s2.Pop() << endl;

  Stack s4 = s2;
  cout << (s4 == s2 ? "Copied Stack is equal to Original Stack\n" : "Copied Stack is not equal to Original Stack\n");

  // Using the assignment operator
  s1 = s2;
  cout << (s1 == s2 ? "Assigned Stack is equal to Original Stack\n" : "Assigned Stack is not equal to Original Stack\n");

  // Using the + operator to concatenate two stacks
  Stack s5 = s1 + s2;
  cout << "Concatenated Stack:\n";
  PrintStack(s5);

  s3 = s2.Reverse();
  cout << (s3 == s2 ? "Yes they equal\n" : "No Not equal\n") << endl;

  s10.Push(10);
  s10.Push(20);
  s10.Push(30);
  s10.Push(20);
  s10.Push(40);

  s20.Push(20);
  s20.Push(30);
  s20.Push(40);
  s20.Push(10);
  s20.Push(20); //

  cout << (s10 == s20 ? "Yes they equal\n" : "No Not equal\n") << endl;
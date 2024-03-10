#include <iostream>

using namespace std;

// Public
class Parent {
    int a;  // private variable, not accessible in Child and SubChild
protected:
    int b;  // protected variable, accessible in Child and SubChild
public:
    int c;  // public variable, accessible in Child and SubChild
};

class Child : public Parent {
    int d;  // private variable, not accessible in SubChild
protected:
    int e;  // protected variable, accessible in SubChild
public:
    int f;  // public variable, accessible in SubChild
};

class SubChild : public Child {
    int g;  // private variable, not accessible in derived classes
protected:
    int h;  // protected variable, accessible in derived classes
public:
    int i;  // public variable, accessible in derived classes
};

// Protected
class Parent2 {
    int a;  // private variable, not accessible in Child2 and SubChild2
protected:
    int b;  // protected variable, accessible in Child2 and SubChild2
public:
    int c;  // public variable, accessible in Child2 and SubChild2
};

class Child2 : protected Parent2 {
    int d;  // private variable, not accessible in SubChild2
protected:
    int e;  // protected variable, accessible in SubChild2
public:
    int f;  // public variable, accessible in SubChild2
};

class SubChild2 : protected Child2 {
    int g;  // private variable, not accessible in derived classes
protected:
    int h;  // protected variable, accessible in derived classes
public:
    int i;  // public variable, accessible in derived classes
};

// Private
class Parent3 {
    int a;  // private variable, not accessible in Child3 and SubChild3
protected:
    int b;  // protected variable, not accessible in Child3 and SubChild3
public:
    int c;  // public variable, not accessible in Child3 and SubChild3
};

class Child3 : private Parent3 {
    int d;  // private variable, not accessible in SubChild3
protected:
    int e;  // protected variable, not accessible in SubChild3
public:
    int f;  // public variable, not accessible in SubChild3
};

class SubChild3 : private Child3 {
    int g;  // private variable, not accessible in derived classes
protected:
    int h;  // protected variable, not accessible in derived classes
public:
    int i;  // public variable, not accessible in derived classes
};

int main() {

    return 0;
}

#include <iostream>

using namespace std;

class Complex
{
    int real, img;

    public:
        void setReal(int _real){real = _real;}
        void setImg(int _img){img = _img;}
        int getReal(){return real;}
        int getImg(){return img;}

        Complex()
        {
            real = img = 0;
        }

        Complex(int _r, int _i)
        {
            real = _r;
            img = _i;
        }

        ~Complex()
        {
           //cout << "Destructor\n";
        }
        // Copy Constructor
        Complex(const Complex& old)
        {
            real = old.real;
            img = old.img;
        }

        void print()
        {
            cout << real << "+" << img << "i\n";
        }
        // C1 + C2
        Complex operator+ (Complex& right)
        {
            Complex retVal;
            retVal.real = this->real + right.real;
            retVal.img = this->img + right.img;
            return retVal;
        }
        // C1 += C2
        Complex operator+= (Complex right)
        {
            real += right.real;
            img += right.img;
           return *this;
        }
        // ++C1
        Complex operator++ ()
        {
            real++;
            img++;
           return *this;
        }
        // C1++
        Complex operator++ (int Dummy)
        {
            Complex retVal(this->real, this->img);
            real++;
            img++;
            return retVal;
        }
        // C1 + 10
        Complex operator+ (int _num)
        {
            Complex retVal(real + _num, img);
            return retVal;
        }
        // C1 > C2
        int operator> (Complex right)
        {
            return this->real > right.real && img > right.img;
        }
        // (int)C1
        operator int()
        {
            return this->real;
        }
        // C1 = C2
        Complex operator= (Complex right)
        {
            this->real = right.real;
            this->img = right.img;
            return *this;
        }
};

// 10 + C1
Complex operator+ (int _num, Complex right)
{
    Complex retVal;
    retVal.setReal(right.getReal() + _num);
    retVal.setImg(right.getImg());
    return retVal;
}

int main()
{
    // Create instances of Complex
    Complex c1(3, 4), c2(5, 6), c3;

    // Test various operations
    cout << "Initial values:\n";
    c1.print();
    c2.print();
    cout << "==============================\n";

    cout << "Addition (c1 + c2):\n";
    c3 = c1 + c2;
    c3.print();
    cout << "==============================\n";

    cout << "In-place addition (c1 += c2):\n";
    c1 += c2;
    c1.print();
    cout << "==============================\n";

    cout << "Prefix increment (++c1):\n";
    ++c1;
    c1.print();
    cout << "==============================\n";

    cout << "Postfix increment (c1++):\n";
    c3 = c1++;
    c1.print();
    c3.print();
    cout << "==============================\n";

    cout << "Addition with integer (c1 + 10):\n";
    c3 = c1 + 10;
    c3.print();
    cout << "==============================\n";

    cout << "Comparison (c1 > c2):\n";
    if (c1 > c2)
        cout << "c1 is greater than c2\n";
    else
        cout << "c1 is not greater than c2\n";
    cout << "==============================\n";

    cout << "Type casting (int)c1:\n";
    int x = static_cast<int>(c1);
    cout << "Value of x: " << x << "\n";
    cout << "==============================\n";

    cout << "Assignment (c3 = c2):\n";
    c3 = c2;
    c3.print();
    cout << "==============================\n";

    cout << "Standalone addition (10 + c1):\n";
    c3 = 10 + c1;
    c3.print();
    cout << "==============================\n";

    return 0;
}


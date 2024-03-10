#include <iostream>

using namespace std;

class Complex
{
    int real, img;

    public:
        void SetReal(int _real)
        {
            (*this).real = _real;
        }

        int GetReal()
        {
            return this->real;
        }

        void SetImg(int _img)
        {
            img = _img;
        }

        int GetImg()
        {
            return img;
        }

        Complex()
        {
            cout << "First Constructor (Default)\n";
        }

        Complex(int _real, int _img)
        {
            real=_real;
            img=_img;
            cout << "Second Constructor\n";
        }

        Complex(int _num)
        {
            real=_num;
            img=_num;
            cout << "Third Constructor\n";
        }

        ~Complex()
        {
            cout << "Destructor Called\n";
        }

        void Print()
        {
            cout << real << "+" << img << "i\n";
        }

        Complex Add(Complex right)
        {
            Complex temp;
            temp.real = real + right.real;
            temp.img = img + right.img;
            return temp;
        }

        void Initiate()
        {
            (*this).real = 0;
            this->img = 0;
        }

        void Initiate(int _real, int _img)
        {
            real = _real;
            img = _img;
        }
};

Complex AddStandAlone(Complex left, Complex right)
{
    Complex temp;
    temp.SetReal(left.GetReal() + right.GetReal());
    temp.SetImg(left.GetImg() + right.GetImg());
    return temp;
}

int main()
{
    Complex test00(100, 100),test0(5), test1, test2, test3, test4, test5;

    test1.SetReal(3);
    test1.SetImg(4);
    test2.SetReal(5);
    test2.SetImg(6);
    test3 = AddStandAlone(test1, test2);
    test4.Initiate();
    test5.Initiate(20, 30);
    test00.Print();
    test0.Print();
    test1.Print();
    test2.Print();
    test3.Print();
    test4.Print();
    test5.Print();
    return 0;
}
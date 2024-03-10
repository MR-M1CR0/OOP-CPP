#include <iostream>

using namespace std;

class Complex
{
    int real;
    int img;

    public:
        void SetReal(int _real)
        {
            real = _real;
        }

        int GetReal() const
        {
            return real;
        }

        void SetImg(int _img)
        {
            img = _img;
        }

        int GetImg() const
        {
            return img;
        }

        void Print()
        {
            if(img < 0)
                cout << real << img << "i\n";
            else
                cout << real << "+" << img << "i\n";
        }

        Complex Add(const Complex& right)
        {
            Complex temp;
            temp.real = real + right.real;
            temp.img = img + right.img;
            return temp;

        }
};

Complex AddStandAlone(const Complex& left, const Complex& right)
{
    Complex temp;
    temp.SetReal(left.GetReal() + right.GetReal());
    temp.SetImg(left.GetImg() + right.GetImg());
    return temp;
}

int main()
{
    Complex test1,test2, test3, test4;

    test1.SetReal(3);
    test1.SetImg(4);

    test2.SetReal(5);
    test2.SetImg(-2);

    test3 = test1.Add(test2);

    test4 = AddStandAlone(test1, test3);

    test1.Print();
    test2.Print();
    test3.Print();
    test4.Print();

    return 0;
}

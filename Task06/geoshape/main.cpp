#include <iostream>

using namespace std;

class Geoshape
{
protected:
    double dim1;
    double dim2;

public:
    void SetDim1(double _dim1)
    {
        dim1 = _dim1;
    }

    double GetDim1()
    {
        return dim1;
    }

    void SetDim2(double _dim2)
    {
        dim2 = _dim2;
    }

    double GetDim2()
    {
        return dim2;
    }

    Geoshape()
    {
        dim1 = dim2 = 0;
        cout << "GeoShape Default Constructor\n";
    }

    Geoshape(double _dim1, double _dim2)
    {
        dim1 = _dim1;
        dim2 = _dim2;
        cout << "GeoShape Copy Constructor\n";
    }

    ~Geoshape()
    {
        cout << "GeoShape Destructor\n";
    }
};

class Rect:public Geoshape
{
public:
    Rect()
    {
        cout << "Rectangle Default Constructor\n";
    }

    Rect(double _d1, double _d2)
    {
        dim1 = _d1;
        dim2 = _d2;
        cout << "Rectangle Copy Constructor\n";
    }

    ~Rect()
    {
        cout << "Rectangle Destructor\n";
    }

    double CArea()
    {
        return dim1 * dim2;
    }
};

class Square:public Rect
{
public:
    Square()
    {
        cout << "Square Default Constructor\n";
    }

    Square(double _dim)
    {
        dim1 = dim2 = _dim;
        cout << "Square Copy Constructor\n";
    }

    ~Square()
    {
        cout << "Square Destructor\n";
    }

    double CArea()
    {
        return dim1 * dim2;
    }
};

class Circle:public Geoshape
{
    public:
    Circle()
    {
        cout << "Circle Default Constructor\n";
    }

    Circle(double _radius):Geoshape(_radius,_radius)
    {
        cout << "Circle Copy Constructor\n";
    }

    ~Circle()
    {
        cout << "Circle Destructor\n";
    }

    double CArea()
    {
        return 3.14 * dim1* dim2;
    }
};

class Tri:public Geoshape
{
    public:
    Tri()
    {
        cout << "Triangle Default Constructor\n";
    }

    Tri(double _base,double _height)
    :Geoshape(_height,_base)
    {
        cout << "Triangle Copy Constructor\n";
    }

    ~Tri()
    {
        cout << "Triangle Destructor\n";
    }

    double CArea()
    {
        return 0.5 * dim1 *dim2;
    }
};

int main()
{
    Rect r1(10, 15);
    Square s1(10);
    Circle c1(10);
    Tri t1(10, 15);
    cout << "\n" << r1.CArea() << endl;
    cout << "\n" << s1.CArea() << endl;
    cout << "\n" << c1.CArea() << endl;
    cout << "\n" << t1.CArea() << endl << endl;
    return 0;
}

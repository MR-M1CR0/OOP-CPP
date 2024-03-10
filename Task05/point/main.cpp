#include <iostream>

using namespace std;

class Point2D
{
    int x, y;

public:
    void setX(int _x)
    {
        x = _x;
    }

    void setY(int _y)
    {
        y = _y;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    Point2D()
    {
        x = y = 0;
    }

    Point2D(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    Point2D(int _num)
    {
        x = y = _num;
    }

    ~Point2D()
    {
        cout << "Destructor 2D\n";
    }

    Point2D(const Point2D& old)
    {
        x = old.x;
        y = old.y;
    }

    void print()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class Point3D
{
    int x;
    int y;
    int z;

public:
    void setX(int _x)
    {
        x = _x;
    }

    void setY(int _y)
    {
        y = _y;
    }

    void setZ(int _z)
    {
        z = _z;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getZ()
    {
        return z;
    }

    Point3D()
    {
        x = y = z = 0;
    }

    Point3D(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    Point3D(int _num)
    {
        x = y = z = _num;
    }

    ~Point3D()
    {
        cout << "Destructor 3D\n";
    }

    Point3D(const Point3D& old)
    {
        x = old.x;
        y = old.y;
        z = old.z;
    }

    operator Point2D()
    {
        Point2D retVal(x, y);
        return retVal;
    }

    void print()
    {
        cout << "(" << x << "," << y << "," << z << ")" << endl;
    }
};

int main()
{
    Point2D p2d(3, 4);
    p2d.print();  //(3,4)

    Point3D p3d(1, 2, 3);
    p3d.print(); //(1,2,3)

    // Implicit casting
    Point2D tmpPnt = p3d;
    tmpPnt.print(); //(1,2)
    return 0;
}

#include <iostream>
using namespace std;

class Shape {
protected:
    int color;

public:
    void SetColor(int _color) { color = _color; }
    int GetColor() { return color; }
    Shape() { color = 0; }
    Shape(int _color) { color = _color; }
    ~Shape() {}
    Shape(const Shape &old) { color = old.color; }
    virtual void Draw() = 0;
};

class Point {
    int x;
    int y;

public:
    void SetX(int _x) { this->x = _x; }
    void SetY(int _y) { y = _y; }
    int GetX() { return x; }
    int GetY() { return y; }
    Point() {
        x = y = 0;
        cout << "\npoint def ctor\n";
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
        cout << "\npoint 2p ctor\n";
    }
    ~Point() { cout << "\nPoint dest\n"; }
    Point(const Point &old) { x = old.x; y = old.y; cout << "\ncpy ctr\n"; }
};

class Line : public Shape {
private:
    Point start;
    Point end;

public:
    void SetStart(Point _start) { start = _start; }
    Point GetStart() { return start; }
    void SetEnd(Point _end) { end = _end; }
    Point GetEnd() { return end; }
    Line() { cout << "\nLine def ctor\n"; }
    Line(int x1, int y1, int x2, int y2, int _color) : Shape(_color) {
        start.SetX(x1);
        start.SetY(y1);
        end.SetX(x2);
        end.SetY(y2);
        cout << "\nLine 5p ctor\n";
    }
    Line(Point _start, Point _end, int _color) {
        start = _start;
        end = _end;
        color = _color;
    }
    ~Line() { cout << "\nLine dest\n"; }
    Line(const Line &old) {
        start = old.start;
        end = old.end;
        color = old.color;
        cout << "\nline cpy ctor\n";
    }
    void Draw() {
        cout << "Line\n";
        cout << "Start" << start.GetX() << "," << start.GetY();
        cout << "End" << end.GetX() << "," << end.GetY();
        cout << "color" << color;
    }
};

class Rect : public Shape {
private:
    Point ul;
    Point lr;

public:
    void SetUL(Point _ul) { ul = _ul; }
    Point GetUL() { return ul; }
    void SetLR(Point _lr) { lr = _lr; }
    Point GetLR() { return lr; }
    Rect() { cout << "\nRect def ctor\n"; }
    Rect(int x1, int y1, int x2, int y2, int _color)
        : ul(x1, y1), lr(x2, y2), Shape(_color) {
        cout << "\nrect 5p ctor\n";
    }
    ~Rect() { cout << "\nrect dest\n"; }
    Rect(const Rect &old) {
        ul = old.ul;
        lr = old.lr;
        color = old.color;
        cout << "\nRect cpy ctor\n";
    }
    void Draw() {
        cout << "Rectangle\n";
        cout << "UL" << ul.GetX() << "," << ul.GetY();
        cout << "LR" << lr.GetX() << "," << lr.GetY();
        cout << "color" << color;
    }
};

class Circle : public Shape {
private:
    Point center;
    int radius;

public:
    void SetCenter(Point _center) { center = _center; }
    Point GetCenter() { return center; }
    void SetRadius(int _radius) { radius = _radius; }
    int GetRadius() { return radius; }
    Circle() {
        radius = 0;
        cout << "\ncircle def ctor\n";
    }
    Circle(int x, int y, int _radius, int _color)
        : center(x, y), radius(_radius), Shape(_color) {
        cout << "\nCircle 4p ctor\n";
    }
    ~Circle() {}
    Circle(const Circle &old) {
        this->center = old.center;
        radius = old.radius;
        color = old.color;
        cout << "\nCircle cpy ctor\n";
    }
    void Draw() {
        cout << "Circle\n";
        cout << "Center" << center.GetX() << "," << center.GetY();
        cout << "radius" << radius;
        cout << "color" << color;
    }
};


class Tri : public Shape {
private:
    Point p1;
    Point p2;
    Point p3;

public:
    Tri() {
        cout << "\nTri def ctor\n";
    }

    Tri(const Point &_p1, const Point &_p2, const Point &_p3, int _color)
        : p1(_p1), p2(_p2), p3(_p3), Shape(_color) {
        cout << "\nTri 4p ctor\n";
    }

    ~Tri() {
        cout << "\nTri dest\n";
    }

    Tri(const Tri &old) {
        p1 = old.p1;
        p2 = old.p2;
        p3 = old.p3;
        color = old.color;
        cout << "\nTri cpy ctor\n";
    }

    void Draw() {
        cout << "Triangle\n";
        cout << "Point 1: (" << p1.GetX() << ", " << p1.GetY() << ")\n";
        cout << "Point 2: (" << p2.GetX() << ", " << p2.GetY() << ")\n";
        cout << "Point 3: (" << p3.GetX() << ", " << p3.GetY() << ")\n";
        cout << "Color: " << color << "\n";
    }
};

class Picture {
private:
    Shape **sPtr;
    int sSize;

public:
    Picture() {
        sPtr = NULL;
        sSize = 0;
    }
    void SetShapes(Shape **_sPtr, int _sSize) {
        sPtr = _sPtr;
        sSize = _sSize;
    }
    void DoIt() {
        for (int i = 0; i < sSize; i++) {
            sPtr[i]->Draw();
        }
    }
};

int main() {
    Shape *sPtr = new Rect(1, 2, 3, 4, 5);
    sPtr->Draw();

    Line larr[2] = {Line(1, 2, 3, 4, 5), Line(3, 4, 5, 6, 7)};
    Rect rarr[2] = {Rect(), Rect()};
    Circle c1(1, 2, 3, 4);

    Shape *sPtrArr[5] = {larr, &larr[1], rarr, &rarr[1], &c1};

    Picture p1;

    p1.SetShapes(sPtrArr, 5);

    p1.DoIt();

    p1.SetShapes(NULL, 0);

    delete sPtr;
    return 0;
}

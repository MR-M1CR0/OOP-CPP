#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point() {
        x = 0;
        y = 0;
        std::cout << "Point default Constructor\n";
    }

    Point(int _x, int _y) {
        x = _x;
        y = _y;
        cout << "Point 2p ctor\n";
    }

    ~Point() {
        cout << "Point dest\n";
    }

    Point(const Point &old) {
        x = old.x;
        y = old.y;
        cout << "Point cpy ctor\n";
    }

    void Display() const {
        cout << "Point: (" << x << ", " << y << ")\n";
    }

    int GetX() const {
        return x;
    }

    int GetY() const {
        return y;
    }
};

class Line {
private:
    Point start;
    Point end;
    int color;

public:
    Line() {
        color = 0;
        cout << "Line def ctor\n";
    }

    Line(int x1, int y1, int x2, int y2, int _color) {
        start = Point(x1, y1);
        end = Point(x2, y2);
        color = _color;
        cout << "Line 5p ctor\n";
    }

    Line(const Point &_start, const Point &_end, int _color) {
        start = _start;
        end = _end;
        color = _color;
        cout << "Line 3p ctor\n";
    }

    ~Line() {
        cout << "Line dest\n";
    }

    Line(const Line &old) {
        start = old.start;
        end = old.end;
        color = old.color;
        cout << "Line cpy ctor\n";
    }

    void DrawLine() const {
        cout << "Line\n";
        cout << "Start: (" << start.GetX() << ", " << start.GetY() << ")\n";
        cout << "End: (" << end.GetX() << ", " << end.GetY() << ")\n";
        cout << "Color: " << color << "\n";
    }
};

class Rect {
private:
    Point ul;
    Point lr;
    int color;

public:
    Rect() {
        color = 0;
        cout << "Rect def ctor\n";
    }

    Rect(int x1, int y1, int x2, int y2, int _color) {
        ul = Point(x1, y1);
        lr = Point(x2, y2);
        color = _color;
        cout << "Rect 5p ctor\n";
    }

    ~Rect() {
        cout << "Rect dest\n";
    }

    Rect(const Rect &old) {
        ul = old.ul;
        lr = old.lr;
        color = old.color;
        cout << "Rect cpy ctor\n";
    }

    void DrawRect() const {
        cout << "Rectangle\n";
        cout << "UL: (" << ul.GetX() << ", " << ul.GetY() << ")\n";
        cout << "LR: (" << lr.GetX() << ", " << lr.GetY() << ")\n";
        cout << "Color: " << color << "\n";
    }
};

class Circle {
private:
    Point center;
    int radius;
    int color;

public:
    Circle() {
        radius = 0;
        color = 0;
        cout << "Circle def ctor\n";
    }

    Circle(int x, int y, int _radius, int _color) {
        center = Point(x, y);
        radius = _radius;
        color = _color;
        cout << "Circle 4p ctor\n";
    }

    ~Circle() {
        cout << "Circle dest\n";
    }

    Circle(const Circle &old) {
        center = old.center;
        radius = old.radius;
        color = old.color;
        cout << "Circle cpy ctor\n";
    }

    void DrawCircle() const {
        cout << "Circle\n";
        cout << "Center: (" << center.GetX() << ", " << center.GetY() << ")\n";
        cout << "Radius: " << radius << "\n";
        cout << "Color: " << color << "\n";
    }
};

class Tri {
private:
    Point p1;
    Point p2;
    Point p3;
    int color;

public:
    Tri() {
        color = 0;
        cout << "Tri def ctor\n";
    }

    Tri(const Point &_p1, const Point &_p2, const Point &_p3, int _color) {
        p1 = _p1;
        p2 = _p2;
        p3 = _p3;
        color = _color;
        cout << "Tri 4p ctor\n";
    }

    ~Tri() {
        cout << "Tri dest\n";
    }

    Tri(const Tri &old) {
        p1 = old.p1;
        p2 = old.p2;
        p3 = old.p3;
        color = old.color;
        cout << "Tri cpy ctor\n";
    }

    void DrawTri() const {
        cout << "Triangle\n";
        cout << "Point 1: (" << p1.GetX() << ", " << p1.GetY() << ")\n";
        cout << "Point 2: (" << p2.GetX() << ", " << p2.GetY() << ")\n";
        cout << "Point 3: (" << p3.GetX() << ", " << p3.GetY() << ")\n";
        cout << "Color: " << color << "\n";
    }
};

int main() {
    Point point(1, 2);
    Point point1(1, 2);
    Point point2(3, 4);
    Point point3(5, 6);
    Line line1(1, 2, 3, 4, 5);
    Line line2(point, Point(3, 4), 6);
    Rect rect(1, 2, 3, 4, 7);
    Circle circle(1, 2, 5, 8);
    Tri triangle(point1, point2, point3, 9);

    point.Display();
    line1.DrawLine();
    line2.DrawLine();
    rect.DrawRect();
    circle.DrawCircle();
    triangle.DrawTri();

    return 0;
}

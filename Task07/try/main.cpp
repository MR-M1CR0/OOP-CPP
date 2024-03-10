#include<iostream>
using namespace std;

//Early / Static Binding
class Base {
protected:
    int x;

public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    Base(){x=0;}
    Base(int _x){x=_x;}
    ~Base(){}

    void Show() {
        cout << "I'm BASE ...";
    }
};

class Derived : public Base {
protected:
    int y;

public:
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    Derived(){x=y=0;}
    Derived(int _x,int _y):Base(_x){y=_y;}
    ~Derived(){}

    void Show() {
        cout << "I'm Derived ...";
    }
};

class Derived2:public Derived
{
    protected:
    int z;
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived2(){z=0;x=0;y=0;}
    Derived2(int _x,int _y,int _z):Derived(_x,_y){z=_z;}
    ~Derived2(){}

    void Show()
    {
        cout<<"I'm Derived TWO";
    }
};

//Late / Dynamic Binding
class BaseV2 {
protected:
    int x;

public:
    void SetX(int _x){x=_x;}
    int GetX(){return x;}
    BaseV2(){x=0;}
    BaseV2(int _x){x=_x;}
    ~BaseV2(){}

    virtual void Show() {
        cout << "I'm BASE ...";
    }
};

class DerivedV2 : public BaseV2 {
protected:
    int y;

public:
    void SetY(int _y){y=_y;}
    int GetY(){return y;}
    DerivedV2(){x=y=0;}
    DerivedV2(int _x,int _y):BaseV2(_x){y=_y;}
    ~DerivedV2(){}

    void Show() {
        cout << "I'm Derived ...";
    }
};

class Derived2V2:public DerivedV2
{
    protected:
    int z;
    void SetZ(int _z){z=_z;}
    int GetZ(){return z;}
    Derived2V2(){z=0;x=0;y=0;}
    Derived2V2(int _x,int _y,int _z):DerivedV2(_x,_y){z=_z;}
    ~Derived2V2(){}

    void Show()
    {
        cout<<"I'm Derived TWO";
    }
};

//Try Abstract and Pure Virtual Function
class Geoshape {
protected:
    double dim1;
    double dim2;

public:
    void SetDim1(double _dim1){dim1=_dim1;}
    double GetDim1(){return dim1;}
    void SetDim2(double _dim2){dim2=_dim2;}
    double GetDim2(){return dim2;}
    Geoshape()
    {
        dim1=dim2=0;
    }
    Geoshape(double _dim1,double _dim2)
    {
        dim1=_dim1;dim2=_dim2;
    }
    Geoshape(double _num)
    {
        dim1=dim2=_num;
    }
    ~Geoshape(){}

    virtual double CArea() = 0;
};

class Rect : public Geoshape {
public:
    Rect(){}
    Rect(double _d1, double _d2) : Geoshape(_d1, _d2) {}

    double CArea() override {
        return dim1 * dim2;
    }
};

class Square : public Geoshape {
public:
    Square(){}
    Square(double _d) : Geoshape(_d, _d) {}

    double CArea() override {
        return dim1 * dim2;
    }
};
//Try SumOfAreasV2();
double SumOfAreasV2(Geoshape** gPtrArr, int gSize) {
    double sum = 0;
    for (int i = 0; i < gSize; i++) {
        sum += gPtrArr[i]->CArea();
    }
    return sum;
}

int main() {
    //Early / Static Binding
    Base *bPtr = new Derived(3, 4);
    bPtr->Show(); //I'm base

    cout << endl;

    //Late / Dynamic Binding
    BaseV2 *bPtr2 = new DerivedV2(3, 4);
    bPtr2->Show(); //I'm derived

    delete bPtr;
    delete bPtr2;

    Rect r1(2, 3);
    Square s1(4);

    Geoshape* gPtrArr[2] = { &r1, &s1 };

    cout << "\nSum of areas: " << SumOfAreasV2(gPtrArr, 2) << endl;

    return 0;
}


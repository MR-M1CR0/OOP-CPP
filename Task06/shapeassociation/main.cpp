#include <iostream>
using namespace std;
class Color{
protected:
    int color;
public:
    void SetColor(int _color){
        color=_color;
    }
    int GetColor(){
        return color;
    }
    Color(){
        color=0;
    }
    Color(int _color){
        color=_color;
    }
    ~Color(){}
    Color(const Color&old){
        color=old.color;
    }
};
class Point{
    int x;
    int y;
    public:
    void setX(int _x){
        x=_x;
    }
    void setY(int _y){
        y=_y;
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    Point(){
        x=y=0;
    }
    Point(int _x,int _y){
        x=_x;y=_y;
    }
    Point(int _num){
        x=y=_num;
    }
    ~Point(){
        //cout<<"dest 2d called"<<endl;
    }
    Point(const Point& old){
        x=old.x;
        y=old.y;
    }
    void print(){
        cout<<"Point: ("<<x<<","<<y<<")"<<endl;
    }
};
class Line:public Color{
private:
    Point p1;
    Point p2;
public:
    void SetP1(Point _p1){
        p1=_p1;
    }
    void SetP2(Point _p2){
        p2=_p2;
    }
    Point GetP1(){
        return p1;
    }
    Point GetP2(){
        return p2;
    }
    Line(){}
    Line(int x1,int y1,int x2,int y2,int _color):p1(x1,y1),p2(x2,y2),Color(_color){}
    Line(Point _p1,Point _p2, int _color){
        p1=_p1;
        p2=_p2;
        color=_color;
    }
    ~Line(){}
    Line(const Line& old){
        p1=old.p1;
        p2=old.p2;
        color=old.color;
    }
    void DrawLine(){
        cout<<"Drawing Line With There Points ";
        cout<<"("<<p1.getX()<<","<<p1.getY()<<") ,";
        cout<<"("<<p2.getX()<<","<<p2.getY()<<") Using ";
        cout<<color<<" color"<<endl;
    }
};

class Rect:public Color{
private:
    Point upperlef;
    Point lowerrigh;
public:
    void SetUpperlef(Point _upperlef){
        upperlef=_upperlef;
    }
    void SetLowerrigh(Point _lowerrigh){
        lowerrigh=_lowerrigh;
    }
    Point GetUpperlef(){
        return upperlef;
    }
    Point GetLowerrigh(){
        return lowerrigh;
    }
    Rect(){}
    Rect(int x1,int y1,int x2,int y2,int _color)
    :upperlef(x1,y1),lowerrigh(x2,y2),Color(_color){}
    Rect(Point _upperlef,Point _lowerrigh, int _color){
        upperlef=_upperlef;
        lowerrigh=_lowerrigh;
        color=_color;
    }
    ~Rect(){}
    Rect(const Rect& old){
        upperlef=old.upperlef;
        lowerrigh=old.lowerrigh;
        color=old.color;
    }
    void DrawRect(){
        cout<<"Drawing Rectangle With There Points ";
        cout<<"("<<upperlef.getX()<<","<<upperlef.getY()<<") ,";
        cout<<"("<<lowerrigh.getX()<<","<<lowerrigh.getY()<<") Using ";
        cout<<color<<" color"<<endl;
    }
};

class Circle:public Color{
private:
    Point center;
    int radius;
public:
    void SetCenter(Point _center){
        center=_center;
    }
    void SetRadius(int _radius){
        radius=_radius;
    }
    Point GetCenter(){
        return center;
    }
    int GetRadius(){
        return radius;
    }
    Circle(){
        color=0;
    }
    Circle(int x,int y,int _radius,int _color):center(x,y),Color(_color){
        radius=_radius;
    }
    Circle(Point _center,int _radius,int _color){
        center=_center;
        radius=_radius;
        color=_color;
    }
    ~Circle(){}
    Circle(const Circle& old){
        center=old.center;
        radius=old.radius;
        color=old.color;
    }
    void DrawCircle(){
        cout<<"Drawing Circle With That Point ";
        cout<<"("<<center.getX()<<","<<center.getY()<<")";
        cout<<" , With Radius = "<<radius<<" Using ";
        cout<<color<<" color"<<endl;
    }
};

class Trial:public Color{
private:
    Point p1;
    Point p2;
    Point p3;
public:
    void SetP1(Point _p1){
        p1=_p1;
    }
    void SetP2(Point _p2){
        p2=_p2;
    }
    void SetP3(Point _p3){
        p3=_p3;
    }
    Point GetP1(){
        return p1;
    }
    Point GetP2(){
        return p2;
    }
    Point GetP3(){
        return p3;
    }
    Trial(){}
    Trial(int x1,int y1,int x2,int y2,int x3,int y3,int _color)
    :p1(x1,y1),p2(x2,y2),p3(x3,y3),Color(_color){}
    Trial(Point _p1,Point _p2,Point _p3,int _color){
        p1=_p1;
        p2=_p2;
        p3=_p3;
        color=_color;
    }
    ~Trial(){}
    Trial(const Trial& old){
        p1=old.p1;
        p2=old.p2;
        p3=old.p3;
        color=old.color;
    }
    void DrawTrial(){
        cout<<"Drawing Trial With There Points ";
        cout<<"("<<p1.getX()<<","<<p1.getY()<<") , ";
        cout<<"("<<p2.getX()<<","<<p2.getY()<<") , ";
        cout<<"("<<p3.getX()<<","<<p3.getY()<<") Using ";
        cout<<color<<" color"<<endl;
    }
};
class Picture{
private:
    Line* linePtr;
    int lineSize;
    Rect* rectPtr;
    int rectSize;
    Circle* circPtr;
    int circSize;
    Trial* trailPtr;
    int trailSize;
public:
    Picture(){
        linePtr=NULL;
        lineSize=0;
        rectPtr=NULL;
        rectSize=0;
        circPtr=NULL;
        circSize=0;
        trailPtr=NULL;
        trailSize=0;
    }
    void SetLines(Line *_linePtr,int _lineSize){
        linePtr=_linePtr;
        lineSize=_lineSize;
    }
    void SetRect(Rect *_rectPtr,int _rectSize){
        rectPtr=_rectPtr;
        rectSize=_rectSize;
    }
    void SetCirc(Circle *_circPtr,int _circSize){
        circPtr=_circPtr;
        circSize=_circSize;
    }
    void SetTrail(Trial *_trailPtr,int _trailSize){
        trailPtr=_trailPtr;
        trailSize=_trailSize;
    }
    void Drawing(){
        for(int i=0;i<lineSize;i++){
            linePtr[i].DrawLine();
            cout<<"-----------------------------------------------------------------------"<<endl;
        }
        for(int i=0;i<rectSize;i++){
            rectPtr[i].DrawRect();
            cout<<"-----------------------------------------------------------------------"<<endl;
        }
        for(int i=0;i<circSize;i++){
            circPtr[i].DrawCircle();
            cout<<"-----------------------------------------------------------------------"<<endl;
        }
        for(int i=0;i<trailSize;i++){
            trailPtr[i].DrawTrial();
            cout<<"-----------------------------------------------------------------------"<<endl;
        }
    }
};
int main(){
    Point p1(3,2),p2(1,4);
    Line linearr[3]={Line(1,2,3,4,5),Line(p1,p2,2),Line()};
    Point p3(5,6),p4(7,8);
    Rect rectarr[3]={Rect(4,2,7,2,9),Rect(p3,p4,1),Rect()};
    Circle circlearr[3]={Circle(2,2,5,1),Circle(5,5,2,8),Circle()};
    Point p5(1,7),p6(3,5),p7(6,1);
    Trial trailarr[3]={Trial(1,2,3,4,5,6,44),Trial(p5,p6,p7,1),Trial()};
    Picture pic;
    pic.SetLines(linearr,3);
    pic.SetRect(rectarr,3);
    pic.SetCirc(circlearr,3);
    pic.SetTrail(trailarr,3);
    pic.Drawing();
    pic.SetLines(NULL,0);
    pic.SetRect(NULL,0);
    pic.SetCirc(NULL,0);
    pic.SetTrail(NULL,0);

};

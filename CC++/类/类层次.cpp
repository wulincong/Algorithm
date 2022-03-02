#include <bits/stdc++.h>

using namespace std;

class Point{
    int x, y;
};

class Shape{
public:
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;

    virtual void draw() const = 0;      //绘制
    virtual void rotate(int angle) = 0; //旋转

    virtual ~Shape(){}
};

void rotate_all(vector<Shape*> & V, int angle){
    for(auto p:V) p->rotate(angle);
}

class Circle:public Shape{
public:
    Circle(Point p, int rr);    //构造函数
    Point center() const {return x;}
    void move(Point to){x = to;}

    void draw() const;
    void rotate(int){}
private:
    Point x;
    int r;
};

class Smilly: public Circle{
public:
    Smilly(Point p, int r):Circle{p, r}, mouth{nullptr}{}
    ~Smilly(){
        delete mouth;
        for(auto p : eyes) delete p;
    }

    void move(Point to);
    void draw() const;
    void rotate(int);
    void add_eye(Shape * s) {eyes.push_back(s);}
    void set_mouth(Shape * s);
    virtual void wink(int i);   //眨眼
private:
    vector<Shape*> eyes;
    Shape * mouth;
};

void Smilly::draw() const{
    Circle::draw();
    for(auto p: eyes)p->draw();
    mouth->draw();
}
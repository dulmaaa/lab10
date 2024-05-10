#include<iostream>
#include<string.h>
#include<math.h>

#define pi 3.14
using namespace std;

class shape {
protected:
    char *name;
    int x, y;
public:
    shape();
    shape(int x, int y);
    ~shape();
    static int totalCount; // static tooluur 
    static void incrementCount(); // Static function
    void displayInfo(); // delgetsleh
};

int shape::totalCount = 0; // Initializing static variable

void shape::incrementCount() {
    totalCount++;
}

void shape::displayInfo() {
    cout << "Name: " << name << ", Coordinates: (" << x << ", " << y << ")" << endl;
}

shape::shape(){
    name = new char[2];
    cout << "parent no arg\n";
    strcpy(name,"");
    incrementCount(); // Increment object count
}

shape::shape(int x, int y){
    cout << "parent arg\n";
    name = new char[2];
    strcpy(name,"");

    this->x = x;
    this->y = y;
    incrementCount(); // Increment object count
}

shape::~shape(){
    delete[] name;
}

class Dshape: public shape {
protected:
    Dshape() {
        cout<<"Dshape no arg\n";
    }
public:
    virtual float area() = 0;
    virtual float perimeter() = 0; 
};

class circle: public Dshape {
private:
    int r;
public:
    circle();
    ~circle();
    float area();
    float perimeter(); 
    void set_x(int _x);
    void set_y(int _y);
    void set_r(int _r);
};

circle::circle(){
    cout<<"circle no arg\n";
    name = new char[7];
    strcpy(name, "circle");
    x = 0;
    y = 0;
    r = 0;
}

circle::~circle(){
}

void circle::set_x(int _x){
    x = _x;
    cout << "x is set to " << x << endl;
}

void circle::set_y(int _y){
    y = _y;
    cout << "y is set to " << y << endl;
}

void circle::set_r(int _r){
    r = _r;
}

float circle::area(){
    return pi*r*r;
}

float circle::perimeter(){ 
    return 2*pi*r;
}

class square: public Dshape {
private:
    float a;
public:
    square();
    ~square();
    float area();
    float perimeter();
    void set_a(float _a);
    void set_x(int _x);
    void set_y(int _y);
};

square::square(){
    name =  new char[7];
    strcpy(name,"square");
    a = 0; 
}

square::~square(){
}

void square::set_a(float _a){
    this->a = _a;
}

void square::set_x(int _x){
    this->x = _x;
}

void square::set_y(int _y){
    this->y = _y;
}

float square::area(){
    return a*a;
}

float square::perimeter(){
    return 4*a;
}

class triangle: public Dshape{
private:
    float a;
public:
    triangle();
    ~triangle();
    float area();
    float perimeter();
    void set_x(int _x);
    void set_y(int _y);
    void set_a(float _a);
};

triangle::triangle(){
    name = new char[9];
    strcpy(name, "triangle");
    x = 0;
    y = 0;
}

triangle::~triangle(){
}

void triangle::set_x(int _x){
    this->x = _x;
    cout << "x is set to " << x << endl;
}

void triangle::set_y(int _y){
    this->y = _y;
    cout << "y is set to " << y << endl;
}

void triangle::set_a(float _a){
    this->a = _a;
    cout << "a is set to " << a << endl;
}

float triangle::area(){
    float h = sqrt(a*a - a/2 * a/2);
    return h*a/2;
}

float triangle::perimeter(){
    return a*3;
}

int main() {
    circle c;
    square s;
    triangle t;
    int r, cx, cy, sx, sy, tx, ty;
    float sa, ta;
    float s1, s2, s3;

    cout<<"Enter circle coordinates x: ";
    cin>>cx;
    c.set_x(cx);
    cout<<"Enter circle coordinates y: ";
    cin>>cy;
    c.set_y(cy);
    cout<<"Enter circle radius r :";
    cin>>r;
    c.set_r(r);

    cout<<"Enter square side length a: ";
    cin>>sa;
    s.set_a(sa);

    cout<<"Enter square x-coordinate: ";
    cin>>sx;
    s.set_x(sx);

    cout<<"Enter square y-coordinate: ";
    cin>>sy;
    s.set_y(sy);

    cout<<"Enter triangle side length a: ";
    cin>>ta;
    t.set_a(ta);

    cout<<"Enter triangle x-coordinate: ";
    cin>>tx;
    t.set_x(tx);

    cout<<"Enter triangle y-coordinate: ";
    cin>>ty;
    t.set_y(ty);

    s1 = c.area();
    cout<<"Circle area: " << s1 << endl;
    s2 = s.area();
    cout<<"Square area: " << s2 << endl;
    s3 = t.area();
    cout<<"Triangle area: " << s3 << endl;

    float areas[] = { s1, s2, s3 };
    // Sorting areas in descending order
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (areas[j] < areas[j + 1]) {
                float temp = areas[j];
                areas[j] = areas[j + 1];
                areas[j + 1] = temp;
            }
        }
    }

    cout << "Areas in descending order:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << areas[i] << endl;
    }

    int p1 = c.perimeter();
    cout<<"Circle perimeter: " << p1 << endl;
    int p2 = s.perimeter();
    cout<<"Square perimeter: " << p2 << endl;
    int p3 = t.perimeter();
    cout<<"Triangle perimeter: " << p3 << endl;

    float primetres[] = { p1, p2, p3 };
    // Sorting areas in descending order
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (primetres[j] < primetres[j + 1]) {
                float temp = primetres[j];
                primetres[j] = primetres[j + 1];
                primetres[j + 1] = temp;
            }
        }
    }

    cout << "perimeter in descending order:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << primetres[i] << endl;
    }

    cout << "Total shapes created: " << shape::totalCount << endl;

    return 0;
}

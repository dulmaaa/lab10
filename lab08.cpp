#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Shape {
public:
static int totalShapes; 
    char* name;
    Shape(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        totalShapes++; 
    }
    ~Shape() {
        delete[] name;
        totalShapes--; 
    }
    void print() const {
        cout << "Shape: " << name << endl;
    }
    static int getTotalShapes() {
        return totalShapes;
    }
};
int Shape::totalShapes = 0;

class _2DShape : public Shape {
public:
    float area, perimeter;
    float *x, *y;
    _2DShape(const char* name, float area = 0, float perimeter = 0) : Shape(name), area(area), perimeter(perimeter) {}
    ~_2DShape() {}
    void print() const {
        Shape::print();
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
    }
    virtual float calculate_area() const = 0;
    virtual float calculate_perimeter() const = 0;
};

class Circle : public _2DShape {
public:
    float radius;

    Circle(const char* name, float x, float y, float radius)
        : _2DShape(name, M_PI * radius * radius, 2 * M_PI * radius), radius(radius) {}

    float calculate_area() const override { 
        return M_PI * radius * radius;
    }

    float calculate_perimeter() const override { 
        return 2 * M_PI * radius;
    }

    void print() const {
        _2DShape::print();
        cout << "Radius: " << radius << endl;
    }
};

class Square : public _2DShape {
public:
    float length;

    Square(const char* name, float x, float y, float length)
        : _2DShape(name, length * length, 4 * length), length(length) {}

    float calculate_area() const override { 
        return length * length;
    }

    float calculate_perimeter() const override { 
        return 4 * length;
    }

    void print() const {
        _2DShape::print();
        cout << "Length: " << length << endl;
    }
};

class Triangle : public _2DShape {
public:
    float length;

    Triangle(const char* name, float x, float y, float length)
        : _2DShape(name, 0.25 * sqrt(3) * length * length, 3 * length), length(length) {}

    float calculate_area() const override { 
        return 0.25 * sqrt(3) * length * length;
    }

    float calculate_perimeter() const override { 
        return 3 * length;
    }

    void print() const {
        _2DShape::print();
        cout << "Length: " << length << endl;
    }
};

int main() {

    int choice1;
    _2DShape* shapes[100];
    do{
        cout << "Хийх үйлдлээ сонгоно уу" << endl;
        cout << "1. Дүрс нэмэх" << endl;
        cout << "2. Талбайгаар эрэмбэлэх" << endl;
        cout << "3. Приметрээр эрэмбэлэх" << endl;
        cout << "4. Дүрсүүдийг хэвлэх" << endl;
        cout << "5. Нийт дүрсийн тоог хэвлэх" << endl;
        cout << "6. Гарах" << endl;
        cout << "Хийх үйлдлээ оруулна уу: ";
        cin >> choice1;
        switch(choice1) {
            case 1: {
                
                    int choice;
                    cout << "Оруулах дүрсээ сонгоно уу:" << endl;
                    cout << "1. Circle" << endl;
                    cout << "2. Square" << endl;
                    cout << "3. Triangle" << endl;
                    cout << "Оруулах дүрсээ оруулна уу: ";
                    cin >> choice;

                    switch (choice) {
                        case 1: {
                            float x, y, radius;
                            cout << "Тойргийн төвийн координат оруулна уу (x y): ";
                            cin >> x >> y;
                            cout << "Радиусыг оруулна уу: ";
                            cin >> radius;
                            Circle* circle = new Circle("Circle", x, y, radius);
                            circle->area = circle->calculate_area();
                            circle->perimeter = circle->calculate_perimeter();
                            int i=Shape::getTotalShapes()-1;
                            shapes[i] = circle;
                            break;
                        }
                        case 2: {
                            float x, y, length;
                            cout << "Зүүн дээд оройн координат (x y): ";
                            cin >> x >> y;
                            cout << "Талын уртыг оруулна уу: ";
                            cin >> length;
                            Square* square = new Square("Square", x, y, length);
                            square->area = square->calculate_area();
                            square->perimeter = square->calculate_perimeter();
                            int i=Shape::getTotalShapes()-1;
                            shapes[i] = square;
                            break;
                        }
                        case 3: {
                            float x, y, length;
                            cout << "Дээд оройн координатыг оруулна уу (x y): ";
                            cin >> x >> y;
                            cout << "Талын уртыг оруулна уу: ";
                            cin >> length;
                            Triangle* triangle = new Triangle("Triangle", x, y, length);
                            triangle->area = triangle->calculate_area();
                            triangle->perimeter = triangle->calculate_perimeter();
                            int i=Shape::getTotalShapes()-1;
                            shapes[i] = triangle;
                            break;
                        }
                        default:
                            cout << "1-3 хооронд тоо оруулна уу!" << endl;
                            break;
                    }
                    break;
                }
                
            case 2: {
                int n=Shape::getTotalShapes();
                for (int i = 0; i < n-1; ++i) {
                    for (int j = 0; j < n - i - 1; ++j) {
                        if (shapes[j]->calculate_area() > shapes[j + 1]->calculate_area()) {
                            swap(shapes[j], shapes[j + 1]);
                        }
                    }
                }
                cout << "Shapes sorted by area:" << endl;
                for (int i = 0; i < n; ++i) {
                    shapes[i]->print();
                    cout << endl;
                }
                break;
            }
             case 3: {
                int n=Shape::getTotalShapes();
                for (int i = 0; i < n-1; ++i) {
                    for (int j = 0; j < n- i - 1; ++j) {
                        if (shapes[j]->calculate_perimeter() > shapes[j + 1]->calculate_perimeter()) {
                            swap(shapes[j], shapes[j + 1]);
                        }
                    }
                }

                cout << "Shapes sorted by perimeter:" << endl;
                for (int i = 0; i < n; ++i) {
                    shapes[i]->print();
                    cout << endl;
                }
                break;
            }
            case 4: {
                int n=Shape::getTotalShapes();
                cout << "Shapes:" << endl;
                for (int i = 0; i < n; ++i) {
                    shapes[i]->print();
                    cout << endl;
                }
                break;
            }
            case 5: {
        cout << "Total number of shapes: " << Shape::getTotalShapes() << endl;
        break;
    }
            case 6: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice! Please enter 1-5." << endl;
                break;
        }
    }while (choice1 != 6);

    for (int i = 0; i < Shape::totalShapes; ++i) {
        delete shapes[i];
    }

    return 0;
}

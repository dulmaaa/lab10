#include <iostream>
#include <vector>
 
using namespace std;
 
class Shape {

public:

    virtual double area() = 0;

    virtual void print() = 0;

};
 
class Circle : public Shape {

private:

    double radius;

public:

    Circle(double r) : radius(r) {}

    double area() override {

        return 3.14159 * radius * radius;

    }

    void print() override {

        cout << "Circle with radius " << radius << endl;

    }

};
 
class Triangle : public Shape {

private:

    double base;

    double height;

public:

    Triangle(double b, double h) : base(b), height(h) {}

    double area() override {

        return 0.5 * base * height;

    }

    void print() override {

        cout << "Triangle with base " << base << " and height " << height << endl;

    }

};
 
class Square : public Shape {

private:

    double side;

public:

    Square(double s) : side(s) {}

    double area() override {

        return side * side;

    }

    void print() override {

        cout << "Square with side " << side << endl;

    }

};
 
template <typename T>

class List {

private:

    T* data;

    int capacity;

    int size;
 
public:

    List(int initialCapacity = 10) : capacity(initialCapacity), size(0) {

        data = new T[capacity];

    }
 
    ~List() {

        delete[] data;

    }
 
    void add(T t) {

        if (size == capacity) {

            capacity *= 2;

            T* newData = new T[capacity];

            for (int i = 0; i < size; i++) {

                newData[i] = data[i];

            }

            delete[] data;

            data = newData;

        }

        data[size++] = t;

    }
 
    void insert(T t, int index) {

        if (index < 0 || index > size) {

            throw out_of_range("Index out of range");

        }

        if (size == capacity) {

            capacity *= 2;

            T* newData = new T[capacity];

            for (int i = 0; i < size; i++) {

                newData[i] = data[i];

            }

            delete[] data;

            data = newData;

        }

        for (int i = size; i > index; i--) {

            data[i] = data[i - 1];

        }

        data[index] = t;

        size++;

    }
 
    T get(int index) {

        if (index < 0 || index >= size) {

            throw out_of_range("Index out of range");

        }

        return data[index];

    }
 
    void remove(int index) {

        if (index < 0 || index >= size) {

            throw out_of_range("Index out of range");

        }

        for (int i = index; i < size - 1; i++) {

            data[i] = data[i + 1];

        }

        size--;

    }
 
    int length() {

        return size;

    }

};
 
bool compareShapes(Shape* s1, Shape* s2) {

    return s1->area() < s2->area();

}
 
int main() {

    List<Shape*> list;

    for (int i = 0; i < 20; i++) {

        int type = rand() % 3;

        if (type == 0) {

            list.add(new Circle(rand() % 10 + 1));

        } else if (type == 1) {

            list.add(new Triangle(rand() % 10 + 1, rand() % 10 + 1));

        } else {

            list.add(new Square(rand() % 10 +1));

        }

    }
 
    vector<Shape*> vec;

    for (int i = 0; i < list.length(); i++) {

        vec.push_back(list.get(i));

    }
 
    for (int i = 0; i < vec.size() - 1; i++) {

        for (int j = 0; j < vec.size() - i - 1; j++) {

            if (compareShapes(vec[j], vec[j + 1])) {

                Shape* temp = vec[j];

                vec[j] = vec[j + 1];

                vec[j + 1] = temp;

            }

        }

    }
 
    for (int i = 0; i < vec.size(); i++) {

        vec[i]->print();

    }
 
    for (int i = 0; i < vec.size(); i++) {

        delete vec[i];

    }
 
    return 0;

}
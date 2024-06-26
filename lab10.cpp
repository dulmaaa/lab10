#include <iostream>
#include <vector>

using namespace std;

class Shape // ABSTRACT CLASS, funkts todorhoiloogui
{

public:
    virtual double area() = 0;
    virtual void print() = 0;
};

class Circle : public Shape
{

private:
    double *r;

public:
    Circle(double r)
    {
        this->r = new double(r);
    }

    double area() override
    {

        return 3.14 * *r * *r; // haygiin r-d hadgalssan tul * ashiglaj dotorh utgiin ashiglana.
    }

    void print() override
    {

        cout << *r << " radiustai toirog" << endl;
    }
    ~Circle()
    {
        delete r;
    }
};

class Triangle : public Shape
{

private:
    double *a;
    double *h;

public:
    Triangle(double b, double h)
    {
        this->a = new double(b);
        this->h = new double(h);
    }

    double area() override
    {

        return 0.5 * *a * *h;
    }

    void print() override
    {

        cout << *a << " suuritai guraljin, " << *h << " ondortei " << endl;
    }
    ~Triangle()
    {
        delete a;
        delete h;
    }
};

class Square : public Shape
{

private:
    double *a;

public:
    Square(double a)
    {
        this->a = new double(a);
    }

    double area() override
    {

        return *a * *a;
    }

    void print() override
    {

        cout << *a << " taltai kvadrat" << endl;
    }
};

template <typename T>

class List
{

private:
    T *data;

    int capacity;

    int size;

public:
    List()
    {
        size = 0;
        this->capacity = 25;
        data = new T[capacity];
    }

    ~List()
    {

        delete[] data;
    }

    void add(T t)
    {
        if (size < capacity)
            data[size++] = t;
        else
            cout << "bagtaamj duursen" << endl;
    }

    void insert(T t, int index)
    {
        if (size < capacity)
        {
            for (int i = size - 1; i >= index; i--)
            {
                data[i + 1] = data[i];
            }
            data[index] = t;
            size++;
        }
        else
            cout << "bagtaamj duursen" << endl;
    }

    T get(int index)
    {

        if (index < 0 || index >= size)
        {

            cout << "index oldsongui" << endl;
        }

        return data[index];
    }

    void remove(int index)
    {

        if (index < 0 || index >= size)
        {

            cout << "index oldsongui" << endl;
        }

        for (int i = index; i < size - 1; i++)
        {

            data[i] = data[i + 1]; // omnohd in daraagin utguudig ogno
            // indexiig darj bichne
        }

        size--;
    }

    int length()
    {

        return size;
    }
};

bool compareShapes(Shape *s1, Shape *s2)
{

    return s1->area() < s2->area();
}

int main()
{

    List<Shape *> list;

    for (int i = 0; i < 20; i++)
    {

        int type = rand() % 3;

        if (type == 0)
        {

            list.add(new Circle(rand() % 10 + 1));
        }
        else if (type == 1)
        {

            list.add(new Triangle(rand() % 10 + 1, rand() % 10 + 1));
        }
        else
        {

            list.add(new Square(rand() % 10 + 1));
        }
    }

    vector<Shape *> vec;

    for (int i = 0; i < list.length(); i++)
    {

        vec.push_back(list.get(i));
    }

    for (int i = 0; i < vec.size() - 1; i++)
    {

        for (int j = 0; j < vec.size() - i - 1; j++)
        {

            if (compareShapes(vec[j], vec[j + 1]))
            {

                Shape *temp = vec[j];

                vec[j] = vec[j + 1];

                vec[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {

        vec[i]->print();
    }

    for (int i = 0; i < vec.size(); i++)
    {

        delete vec[i];
    }

    return 0;
}
/*
Solve the problem using Object Oriented Programming


int main(){
    int square1width = 50;
    int square2width = 80;
    int rectangle1width = 30, rectangle1height = 40;
    int rectangle2width = 20, rectangle2height = 40;

    int square1area = square1width* square1width;
    int square2area = square2width* square2width;
    int rectangle1area = rectangle1height*rectangle1width;
    int rectangle2area = rectangle2width* rectangle2height;
}
*/

#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual int area() const = 0;  // Pure virtual function for area
};

class Square : public Shape {
private:
    int width;
public:
    Square(int w) : width(w) {}  // Constructor to initialize width

    int area() const override {
        return width * width;  // Area of square
    }
};

class Rectangle : public Shape {
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}  // Constructor to initialize width and height

    int area() const override {
        return width * height;  // Area of rectangle
    }
};

int main() {
    
    Square square1(50);
    Square square2(80);
    Rectangle rectangle1(30, 40);
    Rectangle rectangle2(20, 40);

    cout << "Square 1 area: " << square1.area() << endl;
    cout << "Square 2 area: " << square2.area() << endl;
    cout << "Rectangle 1 area: " << rectangle1.area() << endl;
    cout << "Rectangle 2 area: " << rectangle2.area() << endl;
    return 0;
}
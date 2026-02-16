#include <iostream>
#include <cmath>
using namespace std;

// 위임 생성자와 타겟 생성자 사용

class Circle {
    int radius;
public:
    Circle();
    Circle(int r);
    double getArea();
};

Circle::Circle() : Circle{10} {}
Circle::Circle(int r) : radius{r} { cout << "this Circle's radius -> " << radius << endl; }
double Circle::getArea() { return 3.14 * pow(radius, 2); }

int main() {

    Circle delegate;
    cout << "area of delegate -> " << delegate.getArea() << endl;
    
    Circle target(30);
    cout << "area of target -> " << target.getArea() << endl;

    return 0;
}
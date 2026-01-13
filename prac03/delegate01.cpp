#include <iostream>
#include <cmath>
using namespace std;

class Circle {
    int radius;
public:
    Circle();
    Circle(int radius);
    double getArea();
};

// 아래는 생성자 맴버 이니셜라이즈드 리스트 방식을 사용한 것
Circle::Circle() : Circle{10} {}
Circle::Circle(int radius) : radius{radius} {}
double Circle::getArea() { return 3.14 * pow(radius, 2); }

int main() {

    Circle circ01;     // 기본 생성자
    cout << "circ01 원의 면적 : " << circ01.getArea() << endl;

    Circle circ02(10); // 매개변수를 갖는 생성자
    cout << "circ02 원의 면적 : " << circ02.getArea() << endl;

    return 0;
}

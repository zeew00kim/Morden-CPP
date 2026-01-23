#include <iostream>
#include <cmath>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int r = 1) : radius{r} {}    // 기본 생성자
    Circle(const Circle& c);            // 복사 생성자
    double getArea() { return 3.14 * pow(radius, 2); }
};

// 아래의 작업은 깊은 복사 -> 임의의 메모리 위에 새롭게 할당된 객체에 기존 객체의 정보를 그대로 복사
// 얕은 복사의 경우 새롭게 할당된 객체의 맴버가 기존 객체의 맴버가 위치한 메모리 주소를 참조하는 경우
// (위와 같은 얕은 복사를 하게 되면 원본 값이 변경될 때 복사된 값도 변경되는 문제가 발생할 수 있음)
Circle::Circle(const Circle& c) : radius{c.radius + 10} { 
    cout << "radius of copy constructor : " << radius << endl;;
}

int main() {

    Circle origin(10);
    Circle copy(origin);    // 원본 객체를 인자로 넘겨주는 객체

    cout << "Area of origin constructor : " << origin.getArea() << endl;
    cout << "Area of copified constructor : " << copy.getArea() << endl;

    return 0;
}
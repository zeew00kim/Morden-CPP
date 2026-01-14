#include <iostream>
#include <cmath>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int r = 10) : radius{r} {}
    ~Circle() { cout << "반지름이 " << radius << "인 원을 소멸" << endl; }
    // 생성자 소멸 작업은 사용자가 명시적으로 선언하지 않아도 자동 수행
    // 생성자 소멸은 생성된 순서와 반대(역)으로 진행됨
};

int main() {

    Circle circ01;
    Circle circ02(20);

    return 0;
}
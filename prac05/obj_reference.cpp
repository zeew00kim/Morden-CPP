#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
    int radius;
public:
    Circle() : radius{1} {}
    void setRadius(int r) { this->radius = r; }
    double getArea() { return 3.14 * pow(radius, 2); }
};

// Circle 객체(circ)를 레퍼런스 타입 매개변수로 받아 이미 생성된 객체의 반지름을 설정
// 객체, 문자열, 벡터, 맵 같은 메모리를 많이 차지하는 자료형들은 다음과 같이
// 레퍼런스(&) 타입 매개변수로 받는 것이 좋은 방법 (메모리 사용 효율 향상)
void func_radius(Circle& circ) {
    int r;
    cout << "enter the radius : ";
    cin >> r;
    circ.setRadius(r);
}

int main() {

    Circle circ;

    func_radius(circ);

    cout << "area of circle : " << circ.getArea() << endl;

    return 0;
}
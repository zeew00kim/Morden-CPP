#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    // 이 부분을 맴버 선언부라고 부름
    Point();
    Point(int a, int b);
    void show();
};

// 생성자 맴버 이니셜라이즈드 리스트를 사용해야
// 맴버 내에서 사용하는 변수를 선언과 동시에 초기화할 수 있음
Point::Point() : Point{10, 20} {}
Point::Point(int a, int b) {
    this->x = a;
    this->y = b;
}
void Point::show() { cout << x << ", " << y << endl; }

int main() {

    Point origin, target{10, 20};

    origin.show(); target.show();

    return 0;
}
#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int a = 10, int b = 10) : x{a}, y{b} {}   // 생성자 맴버 이니셜라이즈 리스트 사용
    void showPoint() { cout << "x -> " << x << ", y -> " << y << endl; }
}; 

int main() {

    Point p;
    p.showPoint();

    return 0;
}
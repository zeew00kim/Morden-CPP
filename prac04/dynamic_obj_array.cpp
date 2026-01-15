#include <iostream>
#include <cmath>
using namespace std;

// 동적 객체 배열을 생성해 소멸자 실행 내역을 보이고
// 반지름이 1이상일 경우 해당 원의 면적을 반환하는 코드
class Circle {
    int radius;
    static int cnt;
public:
    Circle() : radius{1} {}
    ~Circle() { cout << "소멸자 실행 (" << ++cnt << "회)" << endl; }
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * pow(radius, 2); }
    int getRadius() { return radius; }
}; 

// static 변수는 클래스의 맴버가 아니라 외부에서 초기화!
int Circle::cnt = 0;

int main() {

    int len;

    do {
        cout << "enter the length of Circle's array : ";
        cin >> len;
        if (len <= 0) { cout << "retry it..." << endl; }
    } while (len <= 0);

    Circle *circArr = new Circle[len];

    for (int i = 0; i < len; i++) {
        int radius;
        cout << "enter the radius : ";
        cin >> radius;
        if (radius <= 0) { break; }
        circArr[i].setRadius(radius);
    }

    for (int i = 0; i < len; i++) {
        if (circArr[i].getRadius() > 1) { 
            cout << "Circle no." << i+1 << "의 면적 : " << circArr[i].getArea() << endl;
        }
    }

    delete[] circArr;

    return 0;
}
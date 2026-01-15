#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Circle {
    int radius;
public:
    Circle() : radius{1} {}
    ~Circle() {} // 이거 안해도 내부적으로 자동 호출됨
    void setRadius(int r) { this->radius = r; }
    double getArea() { return 3.14 * pow(radius, 2); }
};

int main() {

    int len, radius;

    do {
        cout << "length of Circle array : ";
        cin >> len;
        if (len < 1 || len > 10) { cout << "retry it.." << endl; }
    } while (len < 1 || len > 10);

    // Circle 타입 원소를 갖는 벡터(가변 길이 배열)
    // 위에서 입력한 길이(len)만큼 기본 생성자로 초기화
    vector<Circle> circArr(len, Circle());

    for (int i = 0; i < circArr.size(); i++) {
        cout << "enter the no." << i+1 << " Circle's radius : ";
        cin >> radius;
        circArr.at(i).setRadius(radius);
    }

    int cnt = 0;

    vector<Circle*> circPtr(circArr.size());

    for (int i = 0; i < circPtr.size(); i++) {
        circPtr.at(i) = &circArr.at(i);
        cout << "no." << i+1 << "Circle's area : " << circPtr.at(i)->getArea() << endl;
        if (circPtr.at(i)->getArea() >= 100 && circPtr.at(i)->getArea() <= 200) { cnt++; }
    }

    cout << "number of circles with an area of 100~200 : " << cnt << endl;

    return 0;
}
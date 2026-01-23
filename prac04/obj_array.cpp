#include <iostream>
#include <cmath>
#include <array>        // STL array 사용 시 이터레이터 사용 가능
#include <algorithm>
using namespace std;

class Circle {
    mutalbe int radius; // 앞에 mutable 한정자가 있는 맴버변수 const 맴버함수에서도 수정 가능
public:
    void setRadius(int radius) { this->radius = radius; }
    double getArea() const { return 3.14 * pow(radius, 2); }
    // 이 맴버함수 내에서는 절대 객체의 맴버 변수를 변경할 수 없음
    // 객체의 상태를 바꾸지 않겠다는 의미로 double getArea(const Circle& this)
};

int main() {

    // array 템플릿은 컴파일 시점에 정적으로 배열 크기를 지정해야 함
    // 가변 길이 배열을 사용할 때에는 vector 템플릿을 사용
    array<Circle, 5> circArr;

    for (int i = 0; i < circArr.size(); i++) {
        int radius;
        cout << "enter the size of radius : ";
        cin >> radius;
        circArr.at(i).setRadius(radius);
    }

    cout << "[ TOTAL Circle's area ]" << endl;
    for (auto& data : circArr) {
        cout << data.getArea() << " ";
    }
    cout << endl;

    return 0;
}
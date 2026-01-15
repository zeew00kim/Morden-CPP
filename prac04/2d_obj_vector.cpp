#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
    int radius;
public:
    Circle() : radius{ 1 } {}
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * pow(radius, 2); }
};

int main() {

    // 클래스 Circle 자료형을 원소로 갖는 2차원 벡터
    vector<vector<Circle>> v;

    // arr[2][3] 같은 2차원 벡터를 기본 생성자로 초기화
    v.resize(2, vector<Circle>(3, Circle()));

    for (int i = 0; i < 2; i++) {
        static int num = 1;
        for (int j = 0; j < 3; j++) {
            v.at(i).at(j).setRadius(num++);
        }
    }

    for (int i = 0; i < 2; i++) {
        cout << "v.at(" << i << ") = ";
        for (int j = 0; j < 3; j++) {
            cout << v.at(i).at(j).getArea() << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
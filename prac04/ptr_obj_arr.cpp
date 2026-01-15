#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// 객체지향언어(C++) 수업에서 배운 로직은 벡터가 아닌
// C언어 스타일로 동적할당을 하고 이후 자원을 반납해야 함
// 따라서, Modern C++ 에서 빈번히 사용되는 STL 템플릿 중
// 하나인 vector를 사용해 로직을 재구성해보았음
class Circle {
    int radius;
public:
    Circle() : radius{1} {}
    ~Circle() {}
    void setRadius(int r) { this->radius = r; }
    double getArea() { return 3.14 * pow(radius, 2); }
};

int main() {

    int len, radius;

    do {
        cout << "length of Circle's vector (1~10) : ";
        cin >> len;
        if (len < 1 || len > 10) { cout << "retry it..." << endl; }
    } while (len < 1 || len > 10);

    // 위에서 입력한 정수의 길이만큼 벡터의 길이를 설정
    // 그리고, 모두 Circle 클래스의 기본 생성자로 초기화
    vector<Circle> circArr(len, Circle());

    for (int i = 0; i < circArr.size(); i++) {
        cout << "enter the no." << i+1 << " Circle's radius :";
        cin >> radius;
        circArr.at(i).setRadius(radius);
    }
    
    // 면적이 100~300 사이인 원의 개수를 체크하기 위한 정수
    int cnt = 0;

    // 솔직히 이렇게 하면 메모리 낭비이고 절대 실무에서 사용되지 않음
    // Circle 포인터 타입 원소를 갖는 벡터를 다루는 연습을 위해 사용함
    vector<Circle*> circPtr(circArr.size());

    for (int i = 0; i < circPtr.size(); i++) {
        // 왼쪽 벡터의 원소는 포인터 타입 (Circle*)
        // 오른쪽 벡터의 원소는 일반 타입 (Circle)
        circPtr.at(i) = &circArr.at(i);
        cout << "Area of no." << i+1 << " Circle : " << circPtr.at(i)->getArea() << endl;
        if (circPtr.at(i)->getArea() >= 100 && circPtr.at(i)->getArea() <= 300) { cnt++; }
    }

    cout << "SELECT COUNT(circ_obj)" << endl; 
    cout << "FROM Circle" << endl;
    cout << "WHERE area BETWEEN 100 AND 300;" << endl;
    cout << "RESULT --> " << cnt << endl;

    return 0;
}
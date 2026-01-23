#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
    static int circCnt;         // 프로그램 시작 시점부터 메모리의 BSS 영역에 생성됨
    int radius;
public:
    Circle(int r = 1) : radius{r} { circCnt++; }
    ~Circle() { circCnt--; }    // 소멸자 실행은 객체 생성의 반대 순서로 진행
    // double getArea() { return 3.14 * pow(radius, 2); }
    static int getCircCnt() { return circCnt; }
};

int Circle::circCnt = 0;        // 클래스의 객체가 생성되기 이전부터 메모리에 존재하기 때문에 클래스 외부에서 초기화

int main() {

    // vector<Circle> circArr(10); // 기본 생성자를 호출하는 Circle 타입 객체 10개를 갖는 벡터

    vector<Circle> circArr;
    circArr.reserve(10);    // 벡터에 10만큼의 빈 공간(Capacity) 생성

    // 백터의 빈 공간에 emplace_back() 함수를 사용 시 벡터 내부에서 자체적으로 벡터를 생성
    // push_back() 함수 사용 시 기존의 객체를 복사/대입하기 때문에 불필요한 임시 저장 객체를 생성/소멸해야 함
    for (int i = 0; i < 10; i++) { circArr.emplace_back(i); }

    cout << "present Circle count : " << Circle::getCircCnt() << endl;

    // circArr.clear();    // 벡터 내부 원소를 모두 제거 (capacity만 남아있음)
    circArr.erase(circArr.begin(), circArr.end()); // 이렇게 해도 결과는 동일
    cout << "present Circle count : " << Circle::getCircCnt() << endl;

    Circle circ01;
    Circle circ02(10);
    cout << "present Circle count : " << Circle::getCircCnt() << endl;

    return 0;
}
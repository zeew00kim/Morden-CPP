#include <iostream>
#include <utility>  // move() sementic 함수 사용을 위한 헤더
#include <vector>
#include <algorithm>
// #include <iomanip>
using namespace std;

// 다른 클래스 전체를 friend 맴버로 활용하는 예제

class Rect; // 이곳에 먼저 선언하지 않으면 컴파일러는 RectManager 클래스에서 매개변수로 받는 Rect 타입의 존재를 확인할 수 없음

// 여기서 구현부까지 작성해버리면 Rect클래스의 객체 정보를 가져올 수 없어 컴파일 에러 발생 (매개변수로 Rect 객체를 사용할 예정이라는 것만 암시)
class RectManager {
public:
    // 이 클래스는 단순히 Rect 클래스 맴버의 일부를 가져다 사용하기 위한 용도이므로
    // 객체 생성 없이 호출해 사용하기 위해 모두 static 지정자 맴버 함수로 선언
    static bool equals(const Rect&, const Rect&);
    static void getMember(const Rect&);
};

class Rect {
    // move() 함수를 통해 R-value 캐스팅 작업이 수행되더라도 이런 prmitive 자료형들은 파괴되지 않고 기존 객체에 그대로 
    // 남아있는데 기본 자료형은 CPU 레지스터의 공간을 많이 차지하지 않고 주소버스로 해당 변수가 위치한 메모리 주소를 파악하여 
    // 제어버스를 통해 제거 신호를 보내 실제 메모리에 저장된 값을 지우는 비용이 CPU 자원 활용 측면에서 더 손해이기 때문이다.
    int width, height;
public:
    Rect(int w = 1, int h = 1) : width{w}, height{h} {}
    friend RectManager; // 클래스 하나 자체를 friend 맴버로 사용 (RectManager의 모든 맴버는 Rect의 private 맴버까지 접근 가능)
};

bool RectManager::equals(const Rect& r1, const Rect& r2) { return (r1.width == r2.width && r1.height == r2.height); }

void RectManager::getMember(const Rect& r) { cout << r.width << ", " << r.height << endl; }

int main() {

    int width, height;

    // 앞에서 수 차례 설명한 부분이니 벡터 관련 설명은 생략
    vector<Rect> rectArr;
    rectArr.reserve(2);
    for (int i = 0; i < rectArr.capacity(); i++) { 
        cout << "enter the width & height of the Rectangle -> ";
        cin >> width >> height;
        rectArr.emplace_back(width, height);
    }

    // cout << "are they the same Rectangles? -> " << boolalpha << RectManager::equals(rectArr.at(0), rectArr.at(1)) << endl;
    cout << "are they the same Rectangles? -> " << (RectManager::equals(rectArr.at(0), rectArr.at(1)) ? "YES!!" : "NO!!") << endl;

    cout << "The state of before move() -> ";
    RectManager::getMember(rectArr.at(0));  // 객체 생성 없이 범위지정연산자(::)를 통해 클래스의 맴버 기능을 활용

    rectArr.at(0) = move(rectArr.at(1));

    cout << "The state of after move() -> ";
    RectManager::getMember(rectArr.at(0));

    return 0;
}
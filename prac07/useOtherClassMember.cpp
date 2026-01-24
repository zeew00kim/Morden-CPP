#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// 다른 클래스의 맴버 함수를 현재 클래스의 friend 맴버로 사용하는 로직

class Rect; // RectManager 클래스의 매개변수로 취하기 위해 "이 클래스가 존재한다"와 같은 의미로 단순 선언

// Rect 클래스에서 아래 클래스의 맴버 함수를 friend로 사용하기 위해 Rect 클래스보다 우선 선언
class RectManager {
public:
    static bool equals(const Rect&, const Rect&);   // 이렇게 하면 객체 생성 없이 맴버 함수 사용 가능
};

class Rect {
    int width, height;
public:
    Rect(int w = 0, int h = 0) : width{w}, height{h} {}
    // 타 클래스의 맴버 함수인 friend 함수, 이 문장을 컴파일러가 해석하려면 'RectManager'라는 
    // 클래스의 이름을 알고 있어야 하고 그 안에 equals라는 맴버 함수가 반드시 선언되어 있어야 함
    friend bool RectManager::equals(const Rect&, const Rect&);
};

// Rect 클래스 맴버에 대해 구체적인 선언이 이루어진 이후 RectManager 맴버 또한 구체적으로 선언
// C++은 객체지향 언어이지만 컴파일의 순서는 코드의 첫 번째 라인부터 마지막 라인까지 순차적으로 진행
// 따라서, 컴파일 에러 방지를 위해 다음과 같은 설계 순서를 반드시 준수해야 함
bool RectManager::equals(const Rect& r1, const Rect& r2) {
    return (r1.width == r2.width && r1.height == r2.height);
}

int main() {

    int width, height;

    vector<Rect> rectArr;
    rectArr.reserve(2);
    for (int i = 0; i < 2; i++) {
        cout << "enter the width & height -> ";
        cin >> width >> height;
        rectArr.emplace_back(width, height);
    }

    // rectManager 클래스의 맴버 equals()는 static 함수이기 때문에 컴파일&링킹 이후 로더가
    // 메모리에 해당 함수를 즉시 ROAD (해당 함수의 생명주기는 프로그램의 실행 시작부터 종료까지)
    // 이와 같은 방법을 사용하면 불필요한 객체 생성 없이 범위 지정 연산자(::)만 사용해 함수 호출 가능
    cout << "Are they the same Rectangle? -> " << boolalpha 
    << RectManager::equals(rectArr.at(0), rectArr.at(1)) << endl;

    return 0;
}
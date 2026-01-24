#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Rect {
    int width, height;
public:
    Rect(int w = 0, int h = 0) : width{w}, height{h} {}
    friend bool equals (const Rect&, const Rect&);
    // friend 지정자 선언 시 클래스의 맴버가 아님
    // 따라서, 객체 생성을 통한 맴버 호출이 불가능
    // 또한, 실제 구현은 클래스 블록 외부에서 해야함
};

// friend 지정자를 사용 시 객체의 은밀한 곷!(private) 맴버까지 조회 가능
// 클래스와 전혀 무관한 "외부 함수"가 이 방식을 통해 객체 내부를 전부 염탐할 수 있음
bool equals (const Rect& r1, const Rect& r2) { 
    return (r1.width == r2.width && r1.height == r2.height);
}

int main() {

    int width, height;

    vector<Rect> rectArr;
    rectArr.reserve(2);

    for (int i = 0; i < rectArr.capacity(); i++) {
        cout << "enter the width & height of no." << i+1 << " Rectangle -> ";
        cin >> width >> height;
        rectArr.emplace_back(width, height);
    }

    // 여기서 삼항 연산자 앞에 'boolalpah' 출력 지정자 미사용 시 1(true)/0(false) 이렇게 출력됨 (<iomanip> 헤더 선언 필요)
    cout << "Are they the same Rectangle? -> " << boolalpha << equals(rectArr.at(0), rectArr.at(1)) << endl;

    return 0;
}
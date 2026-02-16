#include <iostream>
#include <vector>
using namespace std;

static int num = 1;

class Rect {
    int width, height;
public:
    Rect(int w = 10, int h = 10) : width{w}, height{h} {}
    auto isSquare() -> bool { return (width == height); }
};

int main() {

    vector<Rect> rectArr;   // 벡터를 사용해 세 번 호출하는 것을 간소화
    rectArr.reserve(3);

    for (int i = 0; i < rectArr.capacity(); i++) {
        int a, b;
        cout << "enter the value of a and b -> ";
        cin >> a >> b;
        rectArr.emplace_back(a, b); // 해당 인덱스 위치에 새로운 객체 생성 & 할당 동시 수행
    }

    // 각 인스턴스 별 높이 및 너비 값을 통해 정사각형 여부를 판단
    for (auto data : rectArr) { cout << "no." << num++ << " rect is " << ((data.isSquare()) ? "square" : "not square") << endl; }

    return 0;
}
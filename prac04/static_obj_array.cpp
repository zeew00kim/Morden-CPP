 #include <iostream>
 #include <cmath>
 using namespace std;

// Circle 클래스 타입의 객체를 원소로 가지는 정적 배열 실습
class Circle {
    int radius;
public: 
    Circle() : radius{1} {}
    Circle(int r) : radius{r} {}
    double getArea() { 
        return (radius != 1) ? 3.14 * pow(radius, 2) : 0;
    }
};

 int main() {

    int a, b;

    do {
        cout << "1~10 사이의 정수를 입력 : ";
        cin >> a;
        if (a < 1 || a > 10) { cout << "재입력..." << endl; }
    } while (a < 1 || a > 10);
    do {
        cout << "1~10 사이의 정수를 입력 : ";
        cin >> b;
        if (b < 1 || b > 10) { cout << "재입력..." << endl; }
    } while (b < 1 || b > 10);

    // Circle 객체 배열을 선언 & 초기화
    Circle circArr[3] = { Circle(a), Circle(b), Circle(); }

    for (int i = 0; i < 3; i++) {
        if (circArr[i].getArea() != 0) {
            cout << i+1 << " 번째 원의 면적 -> " << circArr[i].getArea() << endl;
        }
        else { cout << "이 원은 반지름이 1이라 계산하지 않습니다." << endl; }
    }

    return 0;
 }
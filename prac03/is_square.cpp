#include <iostream>
using namespace std;

// 정사각형 여부를 판단하는 로직
class Rect {
protected:
    int width, height;
public:
    Rect(int w, int h) : width{w}, height{h} {}
};

class Square : public Rect {
public:
    Square(int w, int h) : Rect{w, h} {}
    bool is_square() { return (width == height); }
};

int main() {

    Square rect01(10, 20);
    Square rect02(10, 10);

    if (!rect01.is_square()) { cout << "rect01 is not square" << endl; }
    if (rect02.is_square()) { cout << "rect02 is sqaure" << endl;}

    return 0;
}
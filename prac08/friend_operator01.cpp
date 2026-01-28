#include <iostream>
using namespace std;

class Power {
    int kick, punch;
public:
    Power(int k = 0, int p = 0) : kick{k}, punch{p} {}
    void show() const { cout << "kick : " << kick << ", punch : " << punch << endl; }
    // 아래의 operator 함수는 Power 클래스의 맴버 함수
    // 덧셈(+) 연산자 이후 우항에 정수가 오는 연산식의 경우 아래의 함수를 호출
    Power operator+(int op) {
        Power temp;
        temp.kick = kick + op;
        temp.punch = punch + op;
        return temp;
    }
    // 아래의 operator 함수는 Power 클래스의 맴버가 아님
    friend Power operator+(int, const Power&);
};

// operator(연산자 재정의) 또한 함수 개념 (리턴 타입이 Power인 클래스 외부의 전역 함수)
// 좌항(정수) 및 우항(Power 객체) 간의 덧셈(+) 연산 시 호출되는 operator 함수
// friend 함수이기 때문에 객체의 private 맴버까지 접근 가능
Power operator+(int op1, const Power& op2) {
    Power new_obj;
    new_obj.kick = op1 + op2.kick;
    new_obj.punch = op1 + op2.punch;
    return new_obj;
}

int main() {

    int kick, punch;

    cout << "enter the value of kick & punch -> ";
    cin >> kick >> punch;
    Power p1(kick, punch);

    Power p2 = 2 + p1;  // 매개변수로 "정수 및 Power 객체"를 받는 operator 함수를 호출

    Power p3 = p1 + 3;  // 매개변수로 정수를 하나 갖는 operator 함수 호출

    p1.show();
    p2.show();
    p3.show();

    return 0;
}
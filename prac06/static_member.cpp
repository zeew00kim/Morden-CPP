#include <iostream>
using namespace std;

// static 지정자 맴버의 수명은 객체의 소멸까지가 아닌 프로그램의 종료까지이며
// static 맴버 변수는 프로그램의 실행과 동시에 메모리의 DATA 또는 BSS 영역에
// LOAD 되기 때문에 반드시 클래스 객체의 생성보다 먼저 초기화 되어야하고
// static 맴버 변수의 선언은 클래스 내부에 초기화는 외부에 해야 한다.
class Math {
public:
    static int abs(int data) { return (data > 0) ? data : -data; }
    static int max(int a, int b) { return (a > b) ? a : b; }
    static int min(int a, int b) { return (a < b) ? a : b; }
    static int diff(int a, int b) { return (a > b) ? (a - b) : (b - a); }
};

int main() {

    int sel, a, b;

    do {
        cout << "[ 1. abs | 2. max | 3. min | 4. diff | 5. quit ] --> ";
        cin >> sel;

        // static 맴버는 프로그램의 실행과 동시에 DATA 영역에 생성되어있기 때문에 추가적인 객체 생성이 불필요.
        // 또한, static 맴버는 특정 객체의 소속된 것이 아니기 때문에 this 포인터를 가지지 않는다.
        // 따라서, Math::abs()와 같이 범위 지정 연산자(::)를 사용해 특정 경로에 존재하는 abs() 함수에 접근하고
        // 이는 맴버 함수를 사용하면서 어떤 객체에도 영향을 주지 않음을 보장하는 "순수 함수"이다.
        switch(sel) {
        case 1:
            cout << "enter an integer : ";
            cin >> a;
            cout << "result of abs() : " << Math::abs(a) << endl;   // 접근지정(::) 연산자를 사용해 Math 클래스의 맴버 함수를 호출
            break;
        case 2:
            cout << "enter two integers : ";
            cin >> a >> b;
            cout << "result of max() : " << Math::max(a, b) << endl;
            break;
        case 3:
            cout << "enter two integers : ";
            cin >> a >> b;
            cout << "result of min() : " << Math::min(a, b) << endl;
            break;
        case 4:
            cout << "enter the two integers : ";
            cin >> a >> b;
            cout << "result of diff() : " << Math::diff(a, b) << endl;
            break;
        case 5:
            cout << "[ end of while function ]" << endl;
            break;
        default:
            cout << "[ retry it (1~5) ]" << endl;
        }
    } while (sel != 5);

    return 0;
}
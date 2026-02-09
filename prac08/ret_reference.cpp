#include <iostream>
#include <string>
using namespace std;

class Zeew00 {
    int id;
    string major;
public:
    Zeew00(int num, const string& str) : id{num}, major{str} {}
    void show() { cout << id << ", " << major << endl; }
    // main() 함수의 함수 호출에서 인수로 zeew00 인스턴스의 this 포인터를 통해 전달
    Zeew00& operator>>(int num) { id = num; return *this; }
    Zeew00& operator<<(const string& str) { major = str; return *this; }
};

int main() {

    int id, sel;
    string major;

    cout << "enter your student id number -> ";
    cin >> id;
    cin.ignore();

    cout << "enter the your major name -> ";
    getline(cin, major);

    Zeew00 zeew00(id, major);
    zeew00.show();

    while (true) {
        cout << "[ 1. ID | 2. MAJOR ] -> ";
        cin >> sel;
        if (sel > 2 || sel < 1) { break; }
        switch (sel) {
        case 1:
            cout << "enter the new ID number -> ";
            cin >> id;
            cin.ignore();
            // 객체의 주소와 정수 값 두 개를 인수로 전달
            zeew00 >> id; // zeew00.operator>>(sel); 이것과 동일
            break;
        default:
            cout << "enter the new major name -> ";
            getline(cin, major);
            zeew00 << major;
        }
    }

    cout << "result of replace work -> ";
    zeew00.show();

    return 0;
}
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// 하나의 메모리 주소를 여러 포인터가 가리킬 수 있고, 해당 메모리를
// 가리키는 포인터가 0개일 경우 자동으로 자원을 반납하는 shared_ptr 예제

class Zeew00 {
    int id;
    string name;
public:
    Zeew00(int num, const string& str) : id{num}, name{str} {
        cout << " instance was created (" << id << ", " << name << ")" << endl;
    }
    ~Zeew00() { cout << " instance was deleted (" << id << ", " << name << ")" << endl; }
};

int main() {

    int id;
    string name;

    vector<shared_ptr<Zeew00>> pArr;            // 공유 포인터 (shared_ptr) 타입의 원소를 가지는 벡터 선언
    pArr.reserve(3);

    cout << "enter the id : ";
    cin >> id;
    cin.ignore();

    cout << "enter the name : ";
    getline(cin, name);

    pArr.emplace_back(new Zeew00(id, name));    // 0 번째 인덱스 위치에만 새로운 인스턴스 생성

    // 0 번째 인덱스에 위치한 인스턴스의 메모리 주소를 가리키는 포인터 저장
    for (int i = 1; i < 3; i++) { pArr.emplace_back(pArr.at(0)); } 

    // 동일한 메모리 주소를 가리키는 포인터의 개수를 반환 use_count() -> 이게 0이면 메모리 자원을 반납
    cout << "number of pointers pointing to the same memory : " << pArr.at(0).use_count() << endl;

    return 0;
}
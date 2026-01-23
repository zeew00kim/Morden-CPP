#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char* name;
    int id;
public:
    Person(int id, const char* name) : id{id} { // 원본 생성자
        int len = strlen(name) + 1;             // strlen() 함수는 문자열의 마지막 '\0'은 포함하지 않음 그래서 +1을 해줘야 함
        this->name = new char[len];
        strcpy(this->name, name);
    }
    Person(const Person& p) : id(p.id) {        // 깊은 복사 생성자
        int len = strlen(p.name) + 1;
        name = new char[len];
        strcpy(name, p.name);
    }
    ~Person() {
        // 두 코드는 비슷해 보이지만 위의 코드는 단순히 char* 타입 변수가 가리키는 주소가 nullptr이 아니면 메모리를 반환하는 방식
        // 하지만, 두 번째 코드는 생성된 각 객체마다 문자열의 끝('\0')을 만날 때까지 순회하기 때문에 O(n) 만큼 메모리 효율을 낭비
        if (name != nullptr) { delete[] name; }
        /* if (strlen(name) > 0) { delete[] name; } */
    }
    void changeName(const char* name) {
        if (strlen(this->name) < strlen(name)) {    // 기존 문자열의 공간이 새로운 문자열의 공간보다 적은 경우
            delete[] this->name;                    // 현재 객체의 맴버 name의 메모리 자원을 해제
            int len = strlen(name) + 1;             
            this->name = new char[len];
        }
        strcpy(this->name, name);
    }
    void show() { cout << "id : " << id << ", name : " << name << endl; }
};

int main() {

    int id;
    char name[10];

    cout << "enter an ID of original constructor : ";
    cin >> id;
    cin.ignore();   // 이걸 해야 다음에 getline()함수로 문자열을 정상적으로 입력 받을 수 있음 (입력 버퍼에 저장된 '\n' 무시)

    cout << "enter the NAME of original constructor : ";
    cin.getline(name, 10);
    
    Person original(id, name);
    Person copified(original); // Person copified = original -> 이렇게 해도 동일하게 동작

    cout << "[ intial object's status ]" << endl;
    original.show();
    copified.show();

    cout << "enter the new name : ";
    cin.getline(name, 10);
    
    copified.changeName(name);

    cout << "[ renamed object's status ]" << endl;
    original.show();
    copified.show();

    return 0;
}
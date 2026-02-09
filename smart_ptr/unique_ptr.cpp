#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// STL/RAII 스마트 포인터 (std::unique_ptr) 사용 예제

class Zeew00 {
    int id;
    string name;
public:
    Zeew00(int std_id, const string& std_name) : id{std_id}, name{std_name} {
        cout << "members of the instance before the move function : " << id ", " << name << endl;
    }
    void getMem() { 
        cout << "members of the instance after the move function : " << id << ", " << name << endl;
    }
    // 기존 객체의 소유권을 새로운 이름의 객체로 이전했기 때문에 소멸자는 한 번만 호출
    ~Zeew00() { cout << "instance was deleted" << endl; }
};

int main() {

    int id;
    string name;

    cout << "enter the student ID : ";
    cin >> id;
    cin.ignore();

    cout << "enter the student Name : ";
    getline(cin, name);

    vector<unique_ptr<Zeew00>> pArr;            // 스마트 포인터(unique_ptr) 객체를 갖는 벡터 선언
    pArr.emplace_back(new Zeew00(id, name));    // 빈 벡터 공간에 새로운 인스턴스를 생성하며 할당
    
    // `unique_ptr`의 경우 한 번에 하나의 포인터만 특정 메모리 주소를 가리킬 수 있음
    // 따라서, 새로운 객체에 기존 객체의 소유권을 넘겨주는 move() 함수를 사용
    pArr.emplace_back(move(pArr.at(0)));        
    pArr.at(1)->getMem();

    return 0;
}
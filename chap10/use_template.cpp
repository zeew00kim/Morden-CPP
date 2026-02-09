#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Zeew00 {
    int id;
    string major;
public:    
    Zeew00() {}
    Zeew00(int i, const string& m) : id{i}, major{m} {}               // 원본 생성자
    Zeew00(const Zeew00& cp) : id{cp.id + 1}, major{cp.major} {}      // 복사 생성자
    friend void getInfor(const Zeew00&);
};

void getInfor(const Zeew00& infor) { cout << "( id = " << infor.id << ", major = " << infor.major << " )" << endl; }

template <typename T>   // <class T> 와 같이 사용해도 동일
void dataSwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = a;
}

int main() {

    int id;
    string major;

    // 정수를 입력해야 하는 상황에서 char 타입 입력 시 무한루프가 발생하는 문제 방지용
    
    while (true) {
        try {
            cout << "enter the number of your id -> ";
            if (!(cin >> id)) { throw runtime_error("an error was occured!!"); }
            cin.ignore(1000, '\n'); // 정상 입력 시 1000 만큼의 공간을 비우는 작업 (개행 '\n' 제거)
        }
        catch (const runtime_error& e) { 
            cerr << e.what() << endl;
            // 문자열 입력 시 입력 스트림 상태 플래그(cin)에는 내부적으로 failbit를 1로 설정
            // 이게 1로 설정되는 순간 cin 객체는 불통이 되고 이후 cin >> id 작업을 반복해도 무시함
            // 따라서, cin.clear() 맴버 함수를 사용해 활성화된 failbit를 0으로 리셋하여 출력 스트림을 정상화 함
            cin.clear(); 
            cin.ignore(1000, '\n'); // 혹시나 버퍼에 쓰레기 문자열이 남아있다면 모두 무시 (그래야 이후 정상적인 입력이 가능)
            major = "error";
        }
        if (major != "error") { break; }
    }
    
    cout << "enter the name of your major -> ";
    getline(cin, major);

    vector<Zeew00> zeew00;
    zeew00.reserve(2);
    
    zeew00.emplace_back(id, major);       // 0 번째 인덱스 위치에 입력한 id, major를 갖는 새로운 객체 생성과 동시에 할당
    getInfor(zeew00.at(0));               // 첫 인스턴스에 할당된 값을 출력하는 friend 함수

    zeew00.emplace_back(zeew00.at(0));    // 1 번째 인덱스 위치에 기존 객체를 복사한 새로운 객체 생성 및 할당
    getInfor(zeew00.at(1));             

    dataSwap(zeew00.at(0), zeew00.at(1)); // 두 객체 간 맴버 정보를 swap 하는 함수  

    for (int i = 0; i < 2; i++) { getInfor(zeew00.at(i)); }

    return 0;
}
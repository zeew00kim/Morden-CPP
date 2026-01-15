#include <iostream>
using namespace std;

// 배열 동적 할당 예제인데 이런 C 스타일 문법 사용은 지양하기
int main() {

    int len;
    
    do {
        cout << "enter the length of Array : ";
        cin >> len;
        if (len < 1 || len > 10) { cout << "retry..." << endl; }
    } while (len < 1 || len > 10);

    int *p = new int[len];

    if (!p) { cout << "malloc fail" << endl; return 1; }
    
    for (int i = 0; i < len; i++) {
        do {
            cout << "enter the no." << i+1 << " integer : ";
            cin >> p[i];
            if (p[i] <= 0) { cout << "retry it..." << endl; }
        } while (p[i] <= 0);
    }

    int sum = 0;
    for (int i = 0; i < len; i++) { sum += p[i]; }

    // C++에선 primitive 자료형 간의 캐스팅을 할 때
    // 괄호 캐스팅이 아닌 static_cast<>() 문법을 사용
    cout << "average of array's total -> " << static_cast<double>(sum) / len << endl;

    delete[] p;

    return 0;
}
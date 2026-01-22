#include <iostream>
#include <string>
using namespace std;

// string 객체에 +/- 연산자를 포함한 산술연산 문자열을 
// 입력 후 stoi()를 통해 누적 연산결과를 출력하는 로직
int main() {

    string str, part = "";
    int startIdx = 0, result = 0, cnt;
    char op;

    cout << "정수 문자열 입력 (연산자 포함) : ";
    getline(cin, str);

    do {
        cout << "연산자 입력 (+/-) : ";
        cin >> op;
        cin.ignore();
        if (op != '+' && op != '-') { cout << "재입력" << endl; }
    } while (op != '+' && op != '-');

    switch(op) {
    case '+':
        while (true) {
            int finIdx = str.find('+', startIdx);
            if (findIdx == -1) {                    // 전체 문자열에서 '+' 탐색 실패 시 더 이상의 연산자는 없다고 판단
                part = str.substr(startIdx);        // part 문자열에 startIdx부터 문자열의 끝까지 복사
                if (part == "") { break; }          // 근데 만약 part가 빈 문자열이라면 즉시 종료
                result += stoi(part);               // 결과에 stoi(part) 정수 값을 누적 저장
                cout << part << " = ";              // 마지막으로 더할 값과 총 결과 표시를 위한 '=' 출력
                break;
            }
            cnt = findIdx - startIdx;
            part = str.substr(startIdx, cnt);       // 시작 인덱스부터 cnt만큼 ex) 0 + 3 = 3
            result += stoi(part);                   // 결과에 part 값을 string to integer 하여 누적
            cout << part << " + ";                  // 해당 값과 + 연산자 출력 ex) "3 + "
            startIdx = findIdx + 1;                 // 시작 인덱스는 연산자를 찾은 다음 인덱스로 초기화 
        }
        break;
    case '-':
        while (true) {
            int findIdx = str.find('-', startIdx);
            if (findIdx == -1) {                    // 특정 문자 탐색 실패 시 -1
                part = str.substr(startIdx);
                if (part == "") { break; }
                result += stoi(part);
                cout << part << " = ";
                break;
            }
            cnt = findIdx - startIdx;
            part = str.substr(startIdx, cnt);
            if (result == 0 || result < stoi(part)) { 
                result += stoi(part);
                cout << part << "(result < part --> 덧셈 진행) - ";
            }
            else { 
                result -= stoi(part); 
                cout << part << " - ";
            }
            startIdx = findIdx + 1;
        }
        break;
    }

    cout << result << endl; // 문자열을 순회하면 누적된 연산 결과는 프로그램의 마지막에 출력

    return 0;
}
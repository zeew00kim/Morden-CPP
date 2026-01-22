#include <iostream>
#include <string>
using namespace std;

int main() {

    string str, search, newStr, choice;
    int startIdx = 0, findIdx = 0;

    cout << "[ 여러 줄의 문자열을 입력 ]" << endl;
    getline(cin, str, '&'); // '&' 문자 포함 시 문자열 입력 종료 (기본은 '\n')
    cin.ignore();

    while (true) {
        
        cout << "검색할 문자열 -> ";
        getline(cin, search);

        findIdx = str.find(search, startIdx);
        if (findIdx == - 1) {
            cout << "[ 존재하지 않는 문자열 (재입력) ]" << endl;
            continue;
        }

        cout << "교체할 문자열 -> ";
        getline(cin, newStr);

        str.replace(findIdx, search.length(), newStr);

        cout << "[ 추가 진행 여부 (yes/no) ] -> ";
        getline(cin, choice);
        if (choice == "no" || choice == "n") { break; }
        cout << endl;
    }

    cout << "[ 교체 이후 문자열 ]" << endl;
    cout << str << endl;

    return 0;
}
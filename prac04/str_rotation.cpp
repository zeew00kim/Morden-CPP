#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 문자열을 Left / Right 방향으로 회전시키는 로직
int main() {

    string str;

    cout << "문자열 입력(공백 포함) : ";
    getline(cin, str);

    int len = str.length();
    int spaceCnt = 0;
    int idx = 0;

    // 사용자가 입력한 문자열을 순회하면서 공백 개수를 셈
    for (int i = 0; i < len; i++) { if (str[i] == ' ') spaceCnt++; }

    int wordCnt = spaceCnt + 1;     // 전체 문자열 - 공백 개수 = substr 개수
    vector<string> subStr(wordCnt); // 벡터에 wordCnt 만큼의 공간을 할당
    string temp = "";

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {        // 순회 중 공백을 만나면
            subStr.at(idx++) = temp;// 공백 이전까지의 문자열을 벡터에 대입
            temp = "";              // 이후 임시 문자열은 다시 공백으로 초기화
            continue;
        }
        temp += str[i];             // temp 문자열에 문자를 하나씩 누적
    }
    subStr.at(idx) = temp;          // 마지막 공백을 만난 이후의 문자열을 벡터의 마지막 인덱스에 대입

    while (true) {
        int sel;
        cout << "[ 1. LEFT | 2. RIGHT ] --> ";
        cin >> sel;
        if (sel > 2 || sel < 1) { break; }
        switch(sel) { 
        case 1: // 문자열을 왼쪽으로 회전
            for (int i = 0; i < wordCnt; i++) {
                for (int j = 0; j < wordCnt; j++) {
                    cout << subStr.at((wordCnt + j - i) % wordCnt) << " ";
                    // i = 1 일 때, 5+0+1 = 6%5 = 1 -> 1번 인덱스의 문자열을 먼저 출력
                    // i = 2 일 때, 5+0+2 = 7%5 = 2 -> 2번 인덱스의 문자열을 먼저 출력
                    // (이런 매커니즘을 통해 문자열이 왼쪽으로 회전하는 것처럼 보임)
                }
                cout << endl;
            }
            cout << endl;
            break;
        default: // 문자열을 오른쪽으로 회전
            for (int i = 0; i < wordCnt; i++) {
                for (int j = 0; j < wordCnt; j++) {
                    cout << subStr.at((wordCnt + j + i) % wordCnt) << " ";
                    // i = 1 일 때, 5+0-1 = 4%5 = 4 -> 4번 인덱스의 문자열을 먼저 출력
                    // i = 2 일 때, 5+0-2 = 3%5 = 3 -> 3번 인덱스의 문자열을 먼저 출력
                    // (이런 매커니즘을 통해 문자열이 오른쪽으로 회전하는 것처럼 보임)
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
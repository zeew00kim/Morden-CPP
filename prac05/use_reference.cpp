#include <iostream>
using namespace std;

int main() {

    int i = 1, n = 2;

    int& ref = n;   // ref 변수는 n과 동일한 메모리 공간을 공유하는 별칭
    n = 4;          // 원본 값이 바뀌변 ref 변수 값도 바뀜
    ref++;          // 참조 변수는 원본 값과 동일한 메모리 공간을 공유하기 때문에
                    // 이 값을 바꾸면 원본의 값도 변경됨 (유닉스 파일의 심볼릭 링크와 유사)
    cout << "참조 변수 값 -> " << ref << endl;

    ref = i;        // 참조 변수 ref가 가리키는 메모리 주소를 변수 i의 주소로 변경
    ref++;          // 원본 값(i)이 1 -> 2로 증가

    cout << "참조 변수 값 -> " << ref << endl;
    // 레퍼런스 타입 변수는 실제 메모리 공간을 차지하지 않는 특정 변수의 새로운 Alias라고 생각하기

    return 0;
}
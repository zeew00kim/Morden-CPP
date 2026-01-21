#include "share.hpp"

void selectionSort(vector<int>&);

int main() {

    srand(time(nullptr));

    int size;

    cout << "enter the size of vector : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < arr.capacity(); i++) {
        arr.at(i) = rand() % 30 + 1;
    }

    selectionSort(arr);

    for (int data : arr) { cout << data << " "; }
    cout << endl;

    return 0;
}

// 선택 정렬은 비교 기반 정렬이며 제자리 정렬이라고도 말한다.
// 외부 루프에서 최소 값을 가진 인덱스라고 가정 후 내부 루프 순회를 통해 
// 선택된 minIdx의 원소와 그 다음 모든 다음 인덱스들이 가진 원소 값의 
// 비교를 진행하는데 이 때, 비교 후 가장 작은 원소 값을 가진 인덱스 
// 번호를 새로운 minIdx 값으로 지정하고, 실제 원소 값에 대한 
// swap 작업은 내부 루프가 종료된 이후 진행된다.
void selectionSort(vector<int>& v) {
    for (int i = 0; i < v.capacity() - 1; i++) {        // 외부 루프는 종료 조건을 포함 -> n (v.capacity()만큼)    
        int minIdx = i;                                 // 매 루프마다 단순 변수 선언&초기화 -> (n - 1)
        for (int j = i + 1; j < v.capacity(); j++) {    // 내부 루프는 (n-1)까지 n번 반복
            if (v.at(j) < v.at(minIdx)) { minIdx = j; } // 등비수열의 합 공식 사용 -> (n*(n-1))/2
        }
        int temp = v.at(i);                             // 매 루프마다 단순 교환 -> (n - 1)
        v.at(i) = v.at(minIdx);                         // 매 루프마다 단순 교환 -> (n - 1)
        v.at(minIdx) = temp;                            // 매 루프마다 단순 교환 -> (n - 1)
    }
}
// 모든 step을 더한 값 = n + 4(n - 1) + n(n-1)/2 -> n^2/2 - n/2 + 3n - 4 -> n^2 - 5n - 8
// n^2 -> 5n - 8 이 식에서 계수와 나머지항을 제외한 최고차항만 남긴다면 시간 복잡도는 O(n^2)
// 따라서, 선택정렬 함수의 시간복잡도는 최악의 경우 점근적 상한 O(n^2)에 수렴한다.
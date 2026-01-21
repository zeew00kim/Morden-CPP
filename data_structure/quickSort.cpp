#include "share.hpp"

void quickSort(vector<int>&, int, int);

int main() {

    int size;
    srand(time(nullptr));

    cout << "enter the size of vector : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; i++) { arr.at(i) = rand() % 50 + 1; }

    quickSort(arr, 0, size - 1);
    
    for (auto &data : arr) { cout << data << " "; }
    cout << endl;

    return 0;
}

// 퀵 정렬은 재귀호출을 이용한 분할정복 정렬 알고리즘이며 피벗 값을 기준으로
// 배열을 반으로 나누는 분할(Partition) 작업을 먼저 수행하는데 트리에 비유를 하면
// 우선 루트에서 pivot 값과 checkLeft & checkRight 인덱스에 위치한 원소 값들을
// 비교하여 정렬 후 checkLeft <= checkRight 조건을 벗어나 더 이상 정렬을
// 진행할 수 없을 때 마치 이진 트리 구조처럼 왼쪽 및 오른쪽 재귀호출 자식을 생성함
// 이런 재귀호출 트리 생성은 left < right 조건을 만족하지 않는 시점까지 반복되고
// 이 로직의 실행 흐름을 직접 그려보면 트리의 전위 순회 매커니즘과 동일하게 흘러간다.
void quickSort(vector<int>& v, int left, int right) {
    if (left < right) {
        int pivot = v.at((left + right) / 2);                   // 상수 시간 -> O(1)
        int checkLeft = left;                                   // 상수 시간 -> O(1)
        int checkRight = right;                                 // 상수 시간 -> O(1)
        do {                                                    // 한 번의 Partition 작업에서 소요되는 비교/정렬 횟수 -> O(n)    
            while (v.at(checkLeft) < pivot) { checkLeft++; }    // do-while문을 말하는거고 트리의 각 노드(Root & 재귀호출) 당 n번씩 반복됨
            while (v.at(checkRight) > pivot) { checkRight--; }
            if (checkLeft <= checkRight) { 
                int temp = v.at(checkLeft);
                v.at(checkLeft) = v.at(checkRight);
                v.at(checkRight) = temp;
                checkLeft++;
                checkRight--;
            }
        } while (checkLeft <= checkRight);                                           
        quickSort(v, left, checkRight);                         // pivot 값 기준 좌측 원소 갯수만큼 -> O(k)
        quickSort(v, checkLeft, right);                         // pivot 값과 좌측 값을 제외한 우측 원소 갯수만큼 -> O(n-k-1)
    }
}
// 점화식 T(n) = T(k) + T(n-k-1) + O(n)
// Recursion Tree 방식으로 증명 시 -> n * log2 n - 1 + n^log2 -> n * log2 n -1 + 1 -> n log2 n -> O(n log2 n)
// 재귀 트리 그림을 코드로 그릴 수는 없어서 간소화 했지만 결과적으로 O(n log n)에 수렴하는 것을 확인 가능
// 최적의 경우 점근적 하한 빅 오메가에 n log n / 평균적으로는 점근적 상한 O(n log n)에 수렴한다.
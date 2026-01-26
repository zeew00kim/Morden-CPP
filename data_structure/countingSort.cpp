#include "share.hpp"

auto countingSort(vector<int>&) -> void;

int main() {

    int size;
    vector<int> arr;
    srand(time(nullptr));

    do {
        cout << "enter the size of vector : ";
        cin >> size;
        if (size > 10 || size < 5) { cout << "[ retry it (5~10) ]" << endl; }
    } while (size > 10 || size < 5);

    arr.resize(size);

    for (int i = 0; i < size; i++) { arr.at(i) = rand() % 10; } 

    countingSort(arr);

    for (int data : arr) { cout << data << " "; }
    cout << endl;

    return 0;
}

auto countingSort(vector<int>& A) -> void {
    
    // 카운팅 배열 C의 크기 -> 입력 배열의 원소 중 가장 큰 값 - 가장 작은 값 + 1
    vector<int>::iterator max = max_element(A.begin(), A.end());                // O(n)
    auto min = min_element(A.begin(), A.end());                                 // O(n)
    int cnt = *max - *min + 1;                                                  // O(1)

    // B -> C를 통해 카운팅된 원소 값을 저장하는 버킷(출력) 배열
    // C -> 정렬된 값을 저장하는 카운팅 배열
    vector<int> B(A.size()), C(cnt);                                            // O(1) + O(1)
    
    // 입력 배열 A의 원소 값을 하나씩 순회하며 C에 카운팅 (C의 모든 원소는 0으로 초기화 되어 있음)
    for (int i = 0; i < A.size(); i++) { C.at(A.at(i))++; }                     // O(n)

    // 누적합 계산 -> 각 인덱스의 원소에 바로 앞 인덱스의 원소 값을 더함
    for (int i = 1; i < C.size(); i++) { C.at(i) += C.at(i - 1); }              // O(k)

    // A를 뒤에서부터 순회하며 C의 원소 값을 참고해 B에 삽입
    for (int i = A.size() - 1; i >= 0; i--) {                                   // O(n)
        B.at(C.at(A.at(i)) - 1) = A.at(i);
        C.at(A.at(i))--;
    }
}
// countingSort 알고리즘은 정렬 이후에도 동일한 원소 간의 논리적 순서가 보장되는 안정정렬이다.
// 또한, 비교 기반 정렬 방식이 아닌 단순히 배열 3개를 사용해 각 인덱스에 위치한 값의 빈도를 세어
// 누적합으로 각 원소의 위치를 계산하는 방식이기 때문에 O(n log n)의 제약을 받지 않는다.
// 총 시간 복잡도 (각 STEP들의 합) = 5 + 2n + k -> 최고차항만 남긴다면 O(n + k)
// 여기서 n + k 가 의미하는 것은 두 값을 더하는 것이 아닌 둘 중 더 큰 값이
// 총 시간복잡도를 지배한다는 뜻으로 O(max(n, k))의 의미를 갖는다.

// Radix(기수) 정렬에서 서브 루틴으로 사용되는 정렬 방식이며 비교할 값의 범위가 적은 경우 유용한데
// 그 이유는 비교할 값이 매우 많으면 그 만큼 3개의 배열은 메모리 공간을 매우 많이 잡아먹게 된다.
// 위의 함수를 보면 반복문이 3개인 것을 볼 수 있는데 이건 그 만큼 CPU가 각 배열의 원소가 저장된
// 메모리 공간에서 데이터를 읽어와야 한다는 의미이고 컴파일 및 링킹 이후 로더는 이 프로세스에서
// 당장 필요한 프로세스의 일부 페이지만 메모리의 프레임에 적재하고 나머진 보조기억장치에 저장함
// 이 때, 메모리의 프레임에 해당 페이지가 없기 때문에 페이지 폴트가 발생하고 보조기억장치의
// 디스크 블록에서 해당 데이터를 찾아야 한다. 디스크에서 데이터를 탐색하는 속도는 매우 느리고
// 이로 인해 전체 시스템 사용 효율이 저하되는 문제가 발생할 수 있다. 따라서, 말이 길었지만 
// 공간복잡도 면에서 손실이 있을 수 있기 때문에 이런 경우에는 시간 복잡도 면에서 손해를 보더라도
// 비교 기반 정렬 중 공간 사용 효율이 우세하고 속도가 빠른 퀵/합병 정렬을 사용하는 것이 좋은 선택이다.

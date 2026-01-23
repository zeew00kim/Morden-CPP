#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>&, int, int, int);
void mergeSort(vector<int>&, int, int);
auto getAvg(vector<int>&, double&) -> bool;
vector<int> temp;   // 전역 변수로 설정 시 merge() 함수에서 매번 선언&초기화 할 필요가 없어 메모리 사용 측면에서 우세

// mergeSort()를 통해 벡터를 정렬하고 모든 원소 값들의 합에 대한 평균을 산출하는 로직 (& 레퍼런스 타입 사용)
int main() {

    srand(time(nullptr));

    int size;
    double avg;

    cout << "enter the size of vector : ";
    cin >> size;

    vector<int> arr(size);
    temp.resize(size);

    for (int i = 0; i < size; i++) { arr.at(i) = rand() % 30 + 1; }

    mergeSort(arr, 0, size - 1);

    cout << "result of mergeSort : ";
    for (int data : arr) {
        cout << data << " ";
    }
    cout << endl;

    cout << "average value of element in vector : " << ((getAvg(arr, avg)) ? avg : -1) << endl;

    return 0;
}

void mergeSort(vector<int>& v, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;   // O(1)
        mergeSort(v, left, mid);        // O(n/2)
        mergeSort(v, mid+1, right);     // O(n/2)
        merge(v, left, mid, right);      // O(n-1) -> 병합 과정서 최악의 경우 n-1번 비교
        // 총 시간 복잡도 = 2T(n/2) + (n - 1) + 1 = 2T(n/2) + O(n)
        // 재귀 트리의 높이(h)만큼 각 레벨마다 n만큼 연산 -> log2 n * n -> O(n log n)
    }
}

void merge(vector<int>& v, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    
    while (i <= mid && j <= right) {
        if (v.at(i) <= v.at(j)) { temp.at(k++) = v.at(i++); }
        else { temp.at(k++) = v.at(j++); }
    }
    while (i <= mid) { temp.at(k++) = v.at(i++); }
    while (j <= right) { temp.at(k++) = v.at(j++); }
    for (i = left; i <= right; i++) { v.at(i) = temp.at(i); }
}

// 이런 모던 C++ 문법은 안정성을 보장하지만 그 만큼 작업량이 많음 따라서, CPU 사용 효율
// 측면에서는 C 스타일로 프로그래밍 하는 것이 더 좋다. (에러/에러 발생 가능성이 없는 경우)
// double 변수 avg는 레퍼런스 타입이며 이 값을 변경 시 main() 함수의 원본 값도 변경됨
auto getAvg(vector<int>& v, double& avg) -> bool {
    if (v.size() > 0) {
        int sum = 0;
        for (int data : v) { sum += data; }
        avg = static_cast<double>(sum) / v.size();
        return true;
    }
    return false;
}
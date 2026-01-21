#include "share.hpp"

void insertionSort(vector<int>& p);

int main() {

    int size;
    srand(time(nullptr));

    cout << "enter the size of vector : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        arr.at(i) = rand() % 30 + 1;
    }

    insertionSort(arr);

    for (int data : arr) { cout << data << " "; }
    cout << endl;

    return 0;
}

void insertionSort(vector<int>& p) {
    for (int i = 1; i < p.size(); i++) {    // 외부 루프는 종료 조건까지 포함해 반복 -> n
        int key = p.at(i);                  // 이후 키 값과 앞 인덱스의 원소 값들을 비교 -> (n - 1)
        int j = i - 1;                      // 비교할 인덱스 번호는 키 값의 인덱스-1 부터 시작 -> (n - 1)
        while (j >= 0 && p.at(j) > key) {   // j 번째 인덱스에 위치한 원소가 키 값보다 크다면 계속 반복 -> n(n - 1)/2
            p.at(j + 1) = p.at(j);          // 이후 key 값보다 큰 원소 값은 다음 인덱스 번호로 한 칸씩 뒤로 이동
            j--;                            // 다음(앞) 인덱스의 원소와 비교를 위해 j -= 1
        }
        p.at(++j) = key;                    // key값보다 작은 값을 만나면 그 원소의 바로 다음 인덱스 위치에 key값을 대입 -> (n - 1)
    }
}
// 총 시간 복잡도 (모든 step 값들의 합) = n + 3(n - 1) + n(n - 1)/2 -> 4n - 3 + n^2/2 - n/2
// n^2 + 7n - 6 이 식에서 최고차항만을 남기면 n^2이며 점근적 상한은 O(n^2)이 된다.
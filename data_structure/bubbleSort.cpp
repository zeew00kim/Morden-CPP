#include "share.hpp"

void bubbleSort(vector<int>&);

int main() {

    int size;
    srand(time(nullptr));

    cout << "enter the size of vector : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; i++) { arr.at(i) = rand() % 20 + 1; }

    bubbleSort(arr);

    for (int data : arr) { cout << data << " "; }
    cout << endl;

    return 0;
}

// 버블 정렬은 외부 루프를 순회할 때마다 비교하는 값들 중 가장 큰 값을
// 벡터(배열)의 뒤에 하나씩 마치 방울처럼 띄우는 정렬 방식
void bubbleSort(vector<int>& p) {
    for (int i = 0; i < p.capacity(); i++) {
        int swapCnt = 0;
        for (int j = 0; j < p.capacity() - 1 - i; j++) {
            if (p.at(j) > p.at(j+1)) {
                int temp = p.at(j);
                p.at(j) = p.at(j + 1);
                p.at(j + 1) = temp;
                swapCnt++;
            }
        }
        // 이 조건을 통해 더이상 정렬할 필요가 없다면 break;
        if (swapCnt == 0) { break; }    
    }
}
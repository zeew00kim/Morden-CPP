#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

template <class T>
T average(const vector<T>& data) {
    T sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += data.at(i);
    }
    return static_cast<double>(sum) / data.size();
}

template <class T>
void insertionSort(vector<T>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr.at(i);
        int j = i - 1;
        while (j >= 0 && arr.at(j) > key) {
            arr.at(j + 1) = arr.at(j);
            j--;
        }
        arr.at(++j) = key;
    }

    for (T data : arr) { cout << data << " "; }
    cout << endl;
}

int main() {

    srand(time(nullptr));

    int num;

    cout << "enter the number of array length : ";
    cin >> num;

    vector<int> arr_i(num);
    vector<double> arr_d(num);

    for (int i = 0; i < num; i++) {
        arr_i.at(i) = rand() % 30 + 1;
        arr_d.at(i) = static_cast<double>(rand() % 30 + 1);
    }

    insertionSort(arr_i);
    insertionSort(arr_d);

    cout << "result by summation of integer array : " << average(arr_i) << endl;
    cout << "result by summation of double array : " << average(arr_d) << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void insertionSort(vector<string>&);

int main() {

    vector<string> name(5);

    for (int i = 0; i < 5; i++) {
        cout << "enter the no." << i+1 << "name -> ";
        getline(cin, name.at(i));
        if (name.at(i) == "") { cout << "end of cycle..." << endl; break; }
    }

    insertionSort(name);

    for (auto &data : name) { cout << data << " "; }
    cout << endl;

    return 0;
}

// main에서 입력 받은 문자열을 사전 순서로 정렬
void insertionSort(vector<string>& name) {
    for (int i = 1; i < name.size(); i++) {
        string key = name.at(i);
        int j = i - 1;
        while (j >= 0 && name.at(j) > key) {
            name.at(j + 1) = name.at(j);
            j--;
        }
        name.at(++j) = key;
    }
}
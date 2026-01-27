#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 선형 큐의 경우 rear 인덱스가 마지막 위치에 도달 시 더이상 이전 공간을 재활용할 수 없음
// 이와 같은 메모리 공간 낭비 문제를 해결하기 위해 고안된 원형 큐를 구현하는 연습 코드

template <typename T>   // int 외에도 어떤 자료형이든 받을 수 있는 template 클래스
class Queue {
    int front, rear, size;
    vector<T> arr;
public:
    // 큐를 초기화
    Queue(int s = 0) : size{s}, front{0}, rear{0} { arr.resize(size); }

    // 큐가 비어있는지 확인 -> front(삭제) 및 rear(삽입) 인덱스가 동일하다면 현재 큐가 비어있는 상태
    bool is_empty() { return (front == rear); }

    // 큐가 가득 차있는지 확인 
    // -> 원형 큐이기 때문에 rear(4+1) % 5를 하면 다시 0 번째 인덱스로 돌아가는데 이 때, front의 인덱스가 0이라면 큐가 가득 찬 상태
    bool is_full() { return (((rear + 1) % size) == front); }

    // 큐에 데이터를 삽입 -> 큐가 가득 찼다면 main() 함수에 예외를 던지고, 아닐 경우 rear 위치에 값을 삽입 후 rear++
    void enqueue(T element) { 
        if (is_full()) { throw runtime_error("fail to enqueue (queue overflow!!)"); }
        arr.at(rear) = element;     
        rear = (rear + 1) % size;   
        // 원형 큐는 rear 인덱스가 마지막 위치에 도달했을 시 맨 앞인 0 번째 인덱스로 회귀
        // -> 자리가 남아있다면 빙빙 돌면서 삽입/삭제 작업이 이루어지기 때문에 원형 큐라고 부른다.
    }

    // 큐에서 데이터를 삭제 -> 큐가 비어있는 상태라면 main() 함수에 예외를 던지고, 아닐 경우 front 위치의 값을 반환 후 front++
    T dequeue() { 
        if (is_empty()) { throw runtime_error("fail to dequeue (queue underflow!!)"); }
        int temp = front;
        front = (front + 1) % size; // front 인덱스 또한 원형 큐이기 때문에 마지막 위치 도달 시 맨 앞 0 번째 인덱스로 회귀
        return arr.at(temp);
    }

    // 현재 큐에서 가장 먼저 입력된 데이터를 조회 -> 단순히 값만 조회
    T peek() {
        if (is_empty()) { throw runtime_error("fail to peek (queue underflow!!)"); }
        return arr.at(front);   
    }
};

int main() {

    int size, data, sel;

    cout << "enter the capacity of Queue -> ";
    cin >> size;

    Queue<int> queue(size+1);

    while (true) {
        
        cout << "[ 1. enqueue | 2. dequeue | 3. peek ] -> ";
        cin >> sel;

        if (sel > 3 || sel < 1) { break; }

        try {
            switch(sel) {
            case 1:
                cout << "enter the enqueue data -> ";
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                cout << "result of dequeue -> " << queue.dequeue() << endl;
                break;
            default:
                cout << "result of peek -> " << queue.peek() << endl;
            }
        } catch (runtime_error e) { cout << e.what() << endl; }
    }

    return 0;
}
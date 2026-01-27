#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 기존에 구현된 Queue 클래스의 맴버를 상속 받는 Deque 클래스 (기존 자원에 전단 삽입, 후단 삭제 기능만 추가해 덱을 구현)

template <typename T>
class Queue {
protected:  // Deque 클래스에서 상속 받아 사용하기 위해 protected 접근 지정자 사용
    mutable int front, rear, size;  // mutable 한정자는 const 함수 테스트 용도로 선언함
    mutable vector<T> arr;
public:
    // 큐를 초기화
    Queue(int s = 0) : size{s}, front{0}, rear{0} { arr.resize(size); }

    // 큐가 비어있는지 확인
    bool is_empty() const { return (front == rear); }

    // 큐가 가득 차있는지 확인 
    bool is_full() const { return (((rear + 1) % size) == front); }

    // 큐에 데이터를 삽입
    void enqueue(T element) const { 
        if (is_full()) { throw runtime_error("fail to enqueue (queue overflow!!)"); }
        arr.at(rear) = element;     
        rear = (rear + 1) % size;   
    }

    // 큐에서 데이터를 삭제
    T dequeue() const { 
        if (is_empty()) { throw runtime_error("fail to dequeue (queue underflow!!)"); }
        int temp = front;
        front = (front + 1) % size; 
        return arr.at(temp);
    }

    // 현재 큐에서 가장 먼저 입력된 데이터를 조회
    T peek() const {
        if (is_empty()) { throw runtime_error("fail to peek (queue underflow!!)"); }
        return arr.at(front);   
    }
};

// 큐의 기존 기능은 그대로 상속 받아 사용하는 Deque 클래스 (덱은 스택의 LIFO 및 큐의 FIFO 구조를 동시에 사용 가능)
template <typename T>
class Deque : public Queue<T> {
public:
    // 맴버 이니셜라이즈 리스트를 통해 명시적으로 부모 클래스의 디폴트 생성자 호출 후 초기화
    Deque(int s = 0) : Queue<T>{s} {}

    // 큐는 후단에서 삽입, 전단에서 삭제가 이루어지는 구조이지만 덱은 전단 삽입, 후단 삭제 작업이 가능 (이로써 LIFO 작업이 가능해짐)
    void insert_front(T element) const {
        if (this->is_full()) { throw runtime_error("enqueue(front) fail (overflow error!!)"); }
        this->front = (this->front - 1 + this->size) % this->size;
        this->arr.at(this->front) = element;
    }
    T delete_rear() const {
        if (this->is_empty()) { throw runtime_error("dequeue(rear) fail (underflow error!!)"); }
        this->rear = (this->rear - 1 + this->size) % this->size;
        return this->arr.at(this->rear);
    }
};

int main() {

    int size, data, sel;

    cout << "enter the capacity of Deque -> ";
    cin >> size;

    // Queue<int> queue(size+1);
    const Deque<int> deque(size + 1);

    while (true) {
        
        cout << "[ 1. enqueue | 2. dequeue | 3. enqueue(front) | 4. dequeue(rear) | 5. peek ] -> ";
        cin >> sel;

        if (sel > 5 || sel < 1) { break; }

        try {
            // 아래와 같이 조건 분기를 통해 비교해야할 값들이 순차적이고 또 양이 많은 경우 if-else문 보다는 switch문 사용을 권장
            // 1. CPU 내부 레지스터에 sel 값을 저장 -> O(1)
            // 2. 메모리의 점프 테이블 시작 주소 + 레지스터에 저장된 값 -> sel 값과 동일한 정수가 저장된 주소로 이동 -> O(1)
            // 3. 해당 주소에서 읽은 실제 case문의 시작 주소를 다시 레지스터에 로드하고 해당 위치로 간접 점프 수행 -> O(1)
            // 이와 같은 "레지스터 간접 주소 지정" 방식을 통해 원하는 값을 탐색하는 데에 소요되는 시간은 상수시간 O(1)에 수렴
            // if-else 조건이 많아지면 CPU는 다음 명령어를 미리 가져오는 "분기 예측"에 실패할 확률이 높아짐 이런 경우 파이프라인 작업
            // 라인에 들어와 처리되던 모든 명령어들을 Flush(폐기)하고 처음부터 일일히 다시 비교 -> 최악의 경우 데이터의 개수(n)만큼 비교
            switch(sel) {
            case 1:
                cout << "enter the enqueue data -> ";
                cin >> data;
                deque.enqueue(data);
                break;
            case 2:
                cout << "result of dequeue -> " << deque.dequeue() << endl;
                break;
            case 3:
                cout << "enter the enqueue(front) data -> ";
                cin >> data;
                deque.insert_front(data);
                break;
            case 4:
                cout << "result of dequeue(rear) -> " << deque.delete_rear() << endl;
                break;
            default:
                cout << "result of peek -> " << deque.peek() << endl;
            }
        } catch (runtime_error e) { cout << e.what() << endl; }
    }

    return 0;
}
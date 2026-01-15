#include "share.hpp"

// 자료구조 스택을 구현한 코드 이 또한, STL의 일부이지만
// 스택 구조의 이해와 작동 매커니즘으 이해하기 위한 실습
template <typename T>
class Stack {
    int top, size;
    vector<T> arr;
public: 
    // 아래의 기본 생성자가 init_stack 역할을 수행
    Stack(int size = 3) : top{-1}, size{size} { arr.resize(size);}
    bool is_empty() { return (top == -1) ? true : false; }
    bool is_full() { return (top == size - 1) ? true : false; }
    // push, pop, peek 작업 중 스택이 비어있거나 가득 찬 경우에는
    // 현재 어떤 문제가 발생했는지 예외처리를 통해 main() 함수로 throw
    void push(T element) {
        if (is_full()) { throw runtime_error("stack overflow!!"); }
        arr.at(++top) = element;
    }
    T pop() {
        if (is_empty()) { throw runtime_error("stack underflow!!"); }
        return arr.at(top--);
    }
    T peek() {
        if (is_empty()) { throw runtime_error("stack underflow!!"); }
        return arr.at(top);
    }
};

int main() {

    int size;

    do {
        cout << "enter the size of Stack : ";
        cin >> size;
        if (size < 1 || size > 5) { cout << "retry it..." << endl; }
    } while (size < 1 || size > 5);

    Stack<int> stack(size);

    while (true) {
        int data, sel;

        cout << "[ 1. push | 2. pop | 3. peek ] --> ";
        cin >> sel;

        if (sel < 1 || sel > 3) { break; }

        try {
            switch(sel) {
            case 1:
                cout << "enter the push data : ";
                cin >> data;
                stack.push(data);
                break;
            case 2:
                cout << "pop data : " << stack.pop() << endl;
                break;
            default:
                cout << "peek data : " << stack.peek() << endl;
            }
        // 예외를 받아서(catch) 그 내용이 뭔지 출력    
        } catch (runtime_error e) { cout << e.what() << endl; }
    }

    return 0; 
}
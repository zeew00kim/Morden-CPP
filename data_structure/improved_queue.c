#include "ds.h"
#define SIZE 4 // 비트 연산을 위해 2의 거듭제곱으로 입력 

typedef uint16_t T;
T temp = 0;

typedef struct {
    volatile T front, rear;
    T arr[SIZE];
} CircularQueue;

CircularQueue origin = {0, 0};
CircularQueue *queue = &origin;

static bool is_full() { return (queue->front == ((queue->rear + 1) & (SIZE-1))); }

static bool is_empty() { return (queue->front == queue->rear); }

static void enqueue(T data) {
    if (is_full()) { 
        printf("queue overflow error\n");
        return;
    }
    queue->arr[queue->rear] = data;
    queue->rear = (queue->rear + 1) & (SIZE-1);
}

static T dequeue() {
    if (is_empty()) { return 1; }
    temp = queue->front;
    queue->front = (queue->front + 1) & (SIZE-1);
    return queue->arr[temp];
}

static T peek() {
    if (is_empty()) { return 1; }
    return queue->arr[queue->front];
}

int main() {

    T data;

    while (1) {
        printf("[ 1-> enqueue | 2-> dequeue | 3-> peek ] -> ");
        scanf("%hd", &data);
        if (data < 1 || data > 3) break;
        switch (data) {
        case 1:
            printf("enter the enqueue data : ");
            scanf("%hd", &data);
            enqueue(data);
            break;
        case 2:
            data = dequeue();
            if (data == 1) {
                printf("queue underflow error\n"); 
                break;
            }
            printf("result of dequeue : %hd\n", data);
            break;
        default:
            data = peek();
            if (data == 1) {
                printf("queue underflow error\n"); 
                break;
            }
            printf("result of peek : %hd\n", data);
            break;
        }
    }

    return 0;
}

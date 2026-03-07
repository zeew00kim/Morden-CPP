#include "./ds.h"
#define SIZE 5

typedef int T;
int temp = 0;

typedef struct {
    int front, rear;
    int arr[SIZE];
} CircularQueue;

CircularQueue queue = {0, 0};

static bool is_full() { return (queue.front == (queue.rear + 1) % SIZE); }

static bool is_empty() { return (queue.front == queue.rear); }

static void enqueue(T data) {
    if (is_full()) { 
        printf("queue overflow error\n");
        return;
    }
    queue.arr[queue.rear] = data;
    queue.rear = (queue.rear + 1) % SIZE;
}

static T dequeue() {
    if (is_empty()) { return -1; }
    temp = queue.front;
    queue.front = (queue.front + 1) % SIZE;
    return queue.arr[temp];
}

static T peek() {
    if (is_empty()) { return -1; }
    return queue.arr[queue.front];
}

int main() {

    while (1) {
        printf("[ 1. enqueue | 2. dequeue | 3. peek ] -> ");
        scanf("%d", &temp);
        if (temp < 1 || temp > 3) break;
        switch (temp) {
        case 1:
            printf("enter the enqueue data : ");
            scanf("%d", &temp);
            enqueue(temp);
            break;
        case 2:
            temp = dequeue();
            if (temp == -1) {
                printf("queue underflow error\n"); 
                break;
            }
            printf("result of dequeue : %d\n", temp);
            break;
        default:
            temp = peek();
            if (temp == -1) {
                printf("queue underflow error\n"); 
                break;
            }
            printf("result of peek : %d\n", temp);
            break;
        }
    }

    return 0;
}
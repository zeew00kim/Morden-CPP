#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t front, rear, size;
    int *arr;
} Queue;

bool is_full(Queue*);
bool is_empty(Queue*);
void enqueue(Queue*, uint8_t);
int8_t dequeue(Queue*);
int8_t peek(Queue*);

int main() {

    Queue queue = {0, 0};

    printf("enter the size of queue -> ");
    scanf("%hhu", &queue.size);

    queue.arr = (int*)malloc(sizeof(int) * queue.size);

    for (;;) {
        uint8_t sel;
        int8_t data;
        printf("[ 1. Enqueue | 2. Dequeue | 3. peek ] -> ");
        scanf("%hhu", &sel);
        if (sel > 3 || sel < 1) break;

        switch(sel) {
        case 1:
            printf("enter the enqueue data -> ");
            if (scanf("%hhd", &data) != 1) {
                puts("Please, enter the integer in boundary of 1~127...");
                while (getchar() != '\n');
                continue;
            }
            enqueue(&queue, data);
            break;
        case 2:
            if ((data = dequeue(&queue)) == -1) { 
                puts("Queue Underflow Error");
                break;
            }
            printf("result of dequeue -> %hhd\n", data);
            break;
        default:
            if ((data = peek(&queue)) == -1) {
                puts("Queue Underflow Erorr");
                break;
            }
            printf("result of peek -> %hhd\n", data);
        }
    }
    
    free(queue.arr);

    return 0;
}

bool is_full(Queue* q) { return (q->front == (q->rear + 1) % q->size); }
bool is_empty(Queue* q) { return (q->front == q->rear); }

void enqueue(Queue* q, uint8_t data) {
    if (is_full(q)) { 
        puts("Queue Overflow Error");
        return;
    }
    q->arr[q->rear] = data;
    q->rear = (q->rear + 1) % q->size;  // 배열 인덱스 초과 시 0번 인덱스로 이동
}

int8_t dequeue(Queue* q) {
    if (is_empty(q)) { return -1; }
    int8_t temp = q->arr[q->front];   // 현재 인덱스 위치의 값 반환 후 인덱스 +1 증가
    q->front = (q->front + 1) % q->size;
    return temp;
}

int8_t peek(Queue* q) {
    if (is_empty(q)) { return -1; }    
    return q->arr[q->front];            // 현재 인덱스 위치의 값만 반환
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
	int8_t top;
	uint8_t size;
	int* arr;
} Stack;

bool is_full(Stack*);
bool is_empty(Stack*);
void push(Stack*, uint8_t);
int8_t pop(Stack*);
int8_t peek(Stack*);

int main() {

	Stack stack;

	stack.top = -1;

	printf("enter the size of stack -> ");
	scanf("%hhu", &stack.size);

	stack.arr = (int*)malloc(sizeof(int) * stack.size);

	while (1) {
		int8_t data = 0;	// -128 ~ 127 범위 값 입력 가능
		uint8_t sel = 0;
		printf("[ 1. PUSH | 2. POP | 3. PEEK ] -> ");
		scanf("%hhu", &sel);
		if (sel < 1 || sel > 3) break;

		switch (sel) {
		case 1:
			do {
				printf("enter the push data -> ");
				if (scanf("%hhd", &data) != 1) {
					puts("please enter the number in boundary of 0~127!!!");
					while (getchar() != '\n');	// 입력 버퍼에 잘못 입력된 알파벳 또는 특수기호 모두 제거
					continue;
				}
				if (data < 1 || data > 127) puts("please enter the number in boundary of 0~127!!!");
			} while (data < 1 || data > 127);
			push(&stack, data);
			break;
		case 2:
			data = pop(&stack);
			if (data == -1) {
				puts("stack underflow error");
				break;
			}
			printf("result of pop -> %hhd\n", data);
			break;
		default:
			if ((data = peek(&stack)) == -1) {
				puts("stack underflow error");
				break;
			}
			printf("result of peek -> %hhd\n", data);
		}
	}

	free(stack.arr);

	return 0;
}

bool is_full(Stack* s) { return (s->top == s->size - 1); }

bool is_empty(Stack* s) { return (s->top == -1); }

void push(Stack* s, uint8_t data) {
	if (is_full(s)) { 
		puts("stack overflow error!"); 
		return;
	}
	s->arr[++s->top] = data;
}

int8_t pop(Stack* s) {
	if (is_empty(s)) return -1;
	return s->arr[s->top--];
}

int8_t peek(Stack* s) {
	if (is_empty(s)) return -1;
	return s->arr[s->top];
}
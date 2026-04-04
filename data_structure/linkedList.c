#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 가장 단순한 방식으로 선형 연결리스트를 만들어본 연습용 로직 (정처기 24년 3회차에 나왔던 문제랑 유사)

typedef struct Node {
    struct Node* head;
    struct Node* tail;
    int data;
} Node;

int main() {

    Node *link;
    Node *node = (Node*)malloc(sizeof(Node) * 3);   // Node 구조체 원소를 3개 저장하는 배열

    Node node02;
    Node *node03;

    int num02 = node02.data;
    int num03 = node03->data;

    node[0].data = 10;

    if (link->head == NULL) {
        link->head = node[0].head;  // 구조체의 head가 가리키는 곳이 null일 경우 방금 생성한 노드가 head가 됨
        link->tail = link->head;    // 구조체의 tail 또한 초기에는 head와 같은 메모리 주소를 레퍼런스함
    }

    node[1].data = 20;
    link->tail = node[1].head;      // node[1].head 인 이유는 node[1]가 Node 자료형 실체 데이터 값이기 때문 (주소 값이 아님!)

    node[2].data = 30;              // 정처기 실기에선 이 순서를 꼬아서 냈던 것을 기억 (20, 10, 30 이런식으로 출력되게) 
    node[1].tail = node[2].head;

    for (int i = 0; i < 3; i++) { printf("%d ", node[i].data); }
    puts("");

    free(node);

    return 0;
}
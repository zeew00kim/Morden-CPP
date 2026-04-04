#define _CRT_SECURE_NO_WARNINGS
#define ZEE         Zeew00 *zee
#define ZDATA       zee->data = 10
#define WAN         Zaewan *wan
#define WDATA       wan->data = 20
#define JIN         DragonJin *jin
#define JDATA       jin->data = 30

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct List {
    struct List *head;
    struct List *tail;
    uint8_t data;
} List;

typedef struct Zeew00 {
    struct Zeew00 *head;
    struct Zeew00 *tail;
    uint8_t data;
} Zeew00;

typedef struct Zaewan {
    struct Zaewan *head;
    struct Zaewan *tail;
    uint8_t data;
} Zaewan;

typedef struct DragonJin {
    struct Dragonjin *head;
    struct Dragonjin *tail;
    uint8_t data;
} DragonJin;

int main() {

    uint8_t sel;
    
    List *list;
    list->data = 0;

    while (2) {
        printf("[ 1. Zeew00 | 2. Zaewan | 3. DragonJin ] --> ");
        scanf("%hhu", &sel);
        if (sel > 3 || sel < 1) { break; }
        
        if (list->head == NULL) {
            switch(sel) {
            case 1:
                ZEE;    ZDATA;
                list->head = zee->head;
                list->tail = list->head;
                break;
            case 2:
                WAN;    WDATA;
                list->head = wan->head;
                list->tail = list->head;
                break;
            default:
                JIN;    JDATA;
                list->head = jin->head;
                list->tail = list->head;
            }
        }
        else {
            switch (sel) {
            case 1:
                ZEE;    ZDATA;
                list->tail = zee->head;
                zee->tail = NULL;
                break;
            case 2:
                WAN;    WDATA;
                list->tail = wan->head;
                wan->tail = NULL;
                break;
            default:
                JIN;    JDATA;
                list->tail = jin->head;
                jin->tail = NULL;
            }
        }
    }

    List *dummy;
    while (dummy->tail != NULL) {
        dummy->head = list->head;
        printf("%d ", dummy->data);
        dummy->tail = list->tail;
    }

    return 0;
}
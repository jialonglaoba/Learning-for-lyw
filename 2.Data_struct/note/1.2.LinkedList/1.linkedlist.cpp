/*************************************************************************
	> File Name: 1.linklist.cpp
	> Author: 少年宇
	> Mail: 
	> Created Time: 2019年10月02日 星期三 17时48分15秒
 ************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList {
    ListNode head;
    int length;
} LinkedList;

ListNode *init_ListNode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = val;
    node->next = NULL;
    return node;
}

LinkedList *init_LinkedList() {
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_ListNode(ListNode *node) {
    if (!node) return;
    free(node);
    return ;
}

void clear_LinkedList(LinkedList *l) {
    if (!l) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_ListNode(p);
        p = q;
    }
    free(l);
    return ;
}

int insert(LinkedList *l, int ind, int val) {
    if (!l) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = init_ListNode(val);
    while (ind--) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(LinkedList *l, int ind) {
    if (!l) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    clear_ListNode(q);
    l->length -= 1;
    return 1;
}

void output(LinkedList *l) {
    if (!l) return;
    printf("LinkedList(%d) = [", l->length);
    ListNode *p = l->head.next;
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL]\n");
    return ;
}

void reverse(LinkedList *l) {
    if (!l) return;
    ListNode *q, *p = l->head.next;;
    //p = p->next;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return;
}

void mark(LinkedList *l, int x, int ind) {
    if (!l) return ;
    switch (x) {
        case 1: {
            int cnt1 = ind * 4 + 17;
            int cnt2 = cnt1;
            while (cnt1--) printf(" ");
            printf("^\n");
            while (cnt2--) printf(" ");
            printf("l\n");
        } break;
        case 2: {
            int cnt1 = 11;
            int cnt2 = 11;
            while (cnt1--) printf(" ");
            printf("^\n");
            while (cnt2--) printf(" ");
            printf("l\n");
        } break;
        default: return ;
    }
    return ;
}


int main() {
    LinkedList *l = init_LinkedList();
    #define max_op 20
    srand(time(0));
    int op, ind, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 5;
        ind = rand() % (l->length + 3) - 1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d to LinkedList = %d\n",
                      val, ind, insert(l, ind, val));
                output(l);
                mark(l, 1, ind);
            } break;
            case 3: {
                printf("erase item at %d from LinkedList = %d\n",
                      ind, erase(l, ind));
                output(l);
                mark(l, 2, ind);
            } break;
            case 4: {
                printf("reverse the LinkedList\n");
                reverse(l);
                output(l);
                printf("\n");
            } break;
        }
    }
    clear_LinkedList(l);
    return 0;
}





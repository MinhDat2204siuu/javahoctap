#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->value = v;
    p->next = NULL;
    return p;
}

Node* insertLast(Node* h, int v) {
    if (h == NULL) {
        return makeNode(v);
    }

    Node* p = h;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = makeNode(v);
    return h;
}

Node* removeNode(Node* h, int v) {
    if (h == NULL) {
        return NULL;
    }

    if (h->value == v) {
        Node* tmp = h;
        h = h->next;
        free(tmp);
        return h;
    }

    Node* p = h;
    while (p->next != NULL) {
        if (p->next->value == v) {
            Node* q = p->next;
            p->next = q->next;
            free(q);
            break;
        }
        p = p->next;
    }

    return h;
}

Node* removeNodeRecursive(Node* h, int v) {
    if (h == NULL) {
        return NULL;
    }

    if (h->value == v) {
        Node* tmp = h;
        h = h->next;
        free(tmp);
        return removeNodeRecursive(h, v);
    }

    h->next = removeNodeRecursive(h->next, v);
    return h;
}

Node* removeAll(Node* h, int v) {
    while (h != NULL && h->value == v) {
        Node* tmp = h;
        h = h->next;
        free(tmp);
    }

    Node* p = h;
    while (p != NULL && p->next != NULL) {
        if (p->next->value == v) {
            Node* q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }

    return h;
}

int countRecursive(Node* h) {
    if (h == NULL) {
        return 0;
    }
    return 1 + countRecursive(h->next);
}

int count(Node* h) {
    int cnt = 0;
    Node* p = h;
    while (p != NULL) {
        cnt += 1;
        p = p->next;
    }
    return cnt;
}

Node* reverse(Node* h) {
    Node* p = h;
    Node* pp = NULL;
    Node* np = NULL;
    while (p != NULL) {
        np = p->next;
        p->next = pp;
        pp = p;
        p = np;
    }
    return pp;
}

void printList(Node* h) {
    Node* p = h;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        head = insertLast(head, x);
    }
    printf("Danh sach ban dau: ");
    printList(head);

    // Loại bỏ tất cả các nút có giá trị 2
    head = removeAll(head, 2);

    printf("danh sach sau khi loai bo gia tri 2: ");
    printList(head);

    // Đảo ngược danh sách
    head = reverse(head);

    printf("Danh sach sau khi dao nguoc: ");
    printList(head);

    // Đếm số nút trong danh sách
    int nodeCount = count(head);
    printf("so nut trong danh sach: %d\n", nodeCount);

    // Giải phóng bộ nhớ
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}


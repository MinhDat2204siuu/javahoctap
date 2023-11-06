#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Định nghĩa cấu trúc của một Node trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tạo một Node mới với dữ liệu được cung cấp
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Lỗi cấp phát bộ nhớ\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm chèn một Node mới vào đầu danh sách liên kết
Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Hàm chèn một Node mới vào cuối danh sách liên kết
Node* insertAtTail(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Hàm in ra danh sách liên kết
void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Hàm xóa tất cả các Node có giá trị bằng v trong danh sách
Node* deleteAllNodesWithValue(Node* head, int value) {
    Node *temp = head, *prev = NULL;

    // Xóa các nút ở đầu có giá trị bằng 'value'
    while (temp != NULL && temp->data == value) {
        head = temp->next;  // Thay đổi head
        free(temp);         // Giải phóng nút cũ
        temp = head;        // Cập nhật temp tới head mới
    }

    // Duyệt qua danh sách để xóa các nút không phải là đầu
    while (temp != NULL) {
        // Khi tìm thấy nút có giá trị cần xóa
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        // Kiểm tra xem danh sách đã được duyệt hết chưa
        if (temp == NULL) return head;

        // Bỏ qua nút cần xóa và giải phóng bộ nhớ
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
    return head;
}

// Hàm xóa tất cả các Node có giá trị lớn nhất trong danh sách
Node* deleteMaxNodes(Node* head) {
    if (head == NULL) {
        return head;
    }

    int max = INT_MIN;
    Node *temp = head, *prev = NULL;

    // Tìm giá trị lớn nhất trong danh sách
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    // Xóa tất cả các nút có giá trị là max
    temp = head;
    while (temp != NULL) {
        if (temp->data == max) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            temp = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// Hàm xóa tất cả các Node có giá trị nhỏ nhất trong danh sách
Node* deleteMinNodes(Node* head) {
    if (head == NULL) {
        return head;
    }

    int min = INT_MAX;
    Node *temp = head, *prev = NULL;

    // Tìm giá trị nhỏ nhất trong danh sách
    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }

    // Xóa tất cả các nút có giá trị là min
    temp = head;
    while (temp != NULL) {
        if (temp->data == min) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            temp = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

// Hàm đảo ngược danh sách liên kết
Node* reverseList(Node* head) {
    Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Hàm đếm số lượng nút trong danh sách liên kết
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Node* head = NULL; // Khởi tạo head của danh sách liên kết là NULL

    // Ví dụ sử dụng các hàm
    head = insertAtHead(head, 1);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);

    printf("Danh sách liên kết ban đầu:\n");
    printList(head);

    head = deleteAllNodesWithValue(head, 2); // Xóa tất cả các Node có giá trị 2
    printf("Danh sách liên kết sau khi xóa giá trị 2:\n");
    printList(head);

    head = deleteMaxNodes(head); // Xóa tất cả các Node có giá trị lớn nhất
    printf("Danh sách liên kết sau khi xóa phần tử lớn nhất:\n");
    printList(head);

    head = deleteMinNodes(head); // Xóa tất cả các Node có giá trị nhỏ nhất
    printf("Danh sách liên kết sau khi xóa phần tử nhỏ nhất:\n");
    printList(head);

    head = reverseList(head); // Đảo ngược danh sách liên kết
    printf("Danh sách liên kết sau khi đảo ngược:\n");
    printList(head);

    int count = countNodes(head); // Đếm số lượng nút
    printf("Số lượng nút trong danh sách liên kết: %d\n", count);

    // Giải phóng danh sách liên kết khi hoàn thành
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

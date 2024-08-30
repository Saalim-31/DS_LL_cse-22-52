#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void create() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of nodes should be positive.\n");
        return;
    }

    for (int i = 0; i < n; ++i) {
        Node* temp = (Node*)malloc(sizeof(Node));  // Use malloc for dynamic memory allocation
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        
        printf("Enter the data: ");
        scanf("%d", &(temp->data));
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
}

void view() {
    Node* trav = head;

    if (trav == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (trav != NULL) {
        printf("%d\n", trav->data);
        trav = trav->next;
    }
}

void deleteList() {
    Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // Use free to release memory
    }
    tail = NULL;
}

int main() {
    int choice;

    while (1) {
        printf("1 for create\n2 for view\n3 for exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                view();
                break;
            case 3:
                deleteList();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

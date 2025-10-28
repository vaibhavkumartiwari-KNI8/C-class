#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *next;
};

// Use typedef for cleaner syntax
typedef struct node Node;

// --- Function Prototypes ---

/**
 * @brief Creates an initial circular linked list based on user input.
 * @param head_ref A pointer to the head pointer of the list.
 */
void create(Node **head_ref);

/**
 * @brief Inserts a new node at the beginning of the circular list.
 * @param head_ref A pointer to the head pointer of the list.
 */
void insertAtBeg(Node **head_ref);

/**
 * @brief Displays the elements of the circular linked list.
 * @param head The head pointer of the list.
 */
void display(Node *head);


// --- Main Function ---
int main() {
    Node *head = NULL; // Start with an empty list
    int choice;

    printf("--- Circular Singly Linked List Operations ---\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            // Clear the invalid input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                create(&head);
                break;
            case 2:
                insertAtBeg(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                // Ideally, free all memory here before exiting
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// --- Function Definitions ---

/**
 * @brief Creates an initial circular linked list based on user input.
 */
void create(Node **head_ref) {
    int n, i, data;
    Node *temp, *last;

    if (*head_ref != NULL) {
        printf("List already exists. Cannot create a new one.\n");
        return;
    }

    printf("Enter the number of nodes to create: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return;
    }

    // --- Create the first node (head node) ---
    printf("Enter data for node 1: ");
    scanf("%d", &data);

    // Allocate memory
    temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->data = data;
    *head_ref = temp; // This is now the head
    last = temp;      // And also the last node (for now)

    // Since it's circular, the first node points to itself
    temp->next = *head_ref;

    // --- Create the remaining nodes ---
    for (i = 1; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        // Allocate memory for the new node
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        temp->data = data;

        // 1. The *previous* last node points to this new node
        last->next = temp;

        // 2. This new node points back to the head to maintain the circle
        temp->next = *head_ref;

        // 3. Update 'last' to be this new node
        last = temp;
    }

    printf("List created successfully.\n");
    display(*head_ref);
}

/**
 * @brief Inserts a new node at the beginning of the circular list.
 */
void insertAtBeg(Node **head_ref) {
    int data;
    Node *newNode, *last;

    printf("Enter data for the new node: ");
    scanf("%d", &data);

    // 1. Allocate memory for the new node
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    // --- Case 1: The list is empty ---
    if (*head_ref == NULL) {
        *head_ref = newNode;
        newNode->next = newNode;
        printf("Node inserted at beginning (list was empty).\n");
        return;
    }
    last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    newNode->next = *head_ref;
    last->next = newNode;
    *head_ref = newNode;
    printf("Node inserted at the beginning.\n");
}

void display(Node *head) {
    Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data);
}
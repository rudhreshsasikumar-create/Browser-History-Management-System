#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

// Clear forward history
void clearForward() {
    if (current == NULL)
        return;

    struct Node *temp = current->next;

    while (temp != NULL) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    current->next = NULL;
}

// Visit new website
void visitWebsite() {
    char url[100];

    printf("Enter Website URL: ");
    scanf("%99s", url);

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        return;
    }

    strcpy(newNode->url, url);

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        clearForward();

        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    printf("Website Opened: %s\n", current->url);
}

// Go back
void goBack() {
    if (current == NULL) {
        printf("No Browsing History!\n");
    } else if (current->prev == NULL) {
        printf("No Previous Website!\n");
    } else {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    }
}

// Go forward
void goForward() {
    if (current == NULL) {
        printf("No Browsing History!\n");
    } else if (current->next == NULL) {
        printf("No Forward Website!\n");
    } else {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    }
}

// Display current website
void currentWebsite() {
    if (current == NULL) {
        printf("No Website Opened!\n");
    } else {
        printf("Current Website: %s\n", current->url);
    }
}

// Display history
void displayHistory() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("History is Empty!\n");
        return;
    }

    printf("\n===== BROWSER HISTORY =====\n");

    while (temp != NULL) {
        printf("%s", temp->url);

        if (temp == current)
            printf("  <-- Current");

        printf("\n");
        temp = temp->next;
    }
}

// Clear complete history
void clearHistory() {
    struct Node *temp = head;

    while (temp != NULL) {
        struct Node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    head = NULL;
    current = NULL;

    printf("Browser History Cleared!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n===== BROWSER HISTORY MANAGEMENT =====\n");
        printf("1. Visit Website\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Current Website\n");
        printf("5. Display History\n");
        printf("6. Clear History\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input!\n");
            break;
        }

        switch (choice) {
            case 1:
                visitWebsite();
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                currentWebsite();
                break;

            case 5:
                displayHistory();
                break;

            case 6:
                clearHistory();
                break;

            case 7:
                clearHistory();
                printf("Exiting Browser...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}
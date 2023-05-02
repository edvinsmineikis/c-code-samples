#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*

An example of a linked list, where a user can manipulate it with methods, such as:
1) Add a member to beginning of list;
2) Add a member to end of list;
3) Add a member to an index of list;
4) Delete a member at index of list;
5) Update a member at index of list;
6) Search for the index of a member in list;
7) Display contents of a list.

I am aware that a few function calls should be tested for failure,
though this is practice and focus was not on error handling in this program,
but rather challenging the understanding of linked lists, pointers and pass-by function calls.
*/

// Declaration of node structure, every member is declared with this struct
struct node {
    int value;
    struct node *nextPtr;
};

// Function to insert a member in beginning of list
void insert_first(struct node *head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    struct node *head_next_ptr = head->nextPtr;
    head->nextPtr = new_node;
    new_node->value = value;
    if(head_next_ptr != NULL) {
        new_node->nextPtr = head_next_ptr;
    }
    else {
        new_node->nextPtr = NULL;
    }
}

// Function to insert a member at end of list
void insert_last(struct node *head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = value;
    new_node->nextPtr = NULL;
    struct node *current_node = head;
    struct node *next_node = NULL;
    while(1) {
        next_node = current_node->nextPtr;
        if(next_node== NULL) {
            current_node->nextPtr = new_node;
            break;
        }
        current_node = next_node;
    }

}

// Inserting a member into a position of list
void insert_position(struct node *head, int value, int position) {
    struct node *prev_node = NULL;
    struct node *current_node = head;
    struct node *next_node = NULL;
    struct node *temp_node = NULL;
    int cnt = 0;
    while(1) {
        next_node = current_node->nextPtr;
        if(next_node == NULL && position > cnt - 1) {
            printf("List too small for position");
            return;
        }
        if(position == cnt - 1) {
            struct node *new_node = malloc(sizeof(struct node));
            new_node->value = value;
            new_node->nextPtr = current_node;
            prev_node->nextPtr = new_node;
            return;
        }
        prev_node = current_node;
        current_node = next_node;
        cnt++;
    }
}

// Deleting a member at position of list
void delete_position(struct node *head, int position) {
    struct node *prev_node = NULL;
    struct node *current_node = head;
    struct node *next_node = NULL;
    struct node *temp_node = NULL;
    int cnt = 0;
    while(1) {
        next_node = current_node->nextPtr;
        if(next_node == NULL && position > cnt - 1) {
            printf("List too small for position");
            return;
        }
        if(position == cnt - 1) {
            free(current_node);
            prev_node->nextPtr = next_node;
            return;
        }
        prev_node = current_node;
        current_node = next_node;
        cnt++;
    }
}

// Updating a member at position of list
void update(struct node *head, int value, int position) {
    struct node *prev_node = NULL;
    struct node *current_node = head;
    struct node *next_node = NULL;
    struct node *temp_node = NULL;
    int cnt = 0;
    while(1) {
        next_node = current_node->nextPtr;
        if(next_node == NULL && position > cnt - 1) {
            printf("List too small for position");
            return;
        }
        if(position == cnt - 1) {
            struct node *new_node = malloc(sizeof(struct node));
            new_node->value = value;
            new_node->nextPtr = next_node;
            prev_node->nextPtr = new_node;
            return;
        }
        prev_node = current_node;
        current_node = next_node;
        cnt++;
    }
}

// Searching for index of a member recognized by int value
void search(struct node *head, int value) {
    struct node *current_node = head;
    struct node *next_node = NULL;
    int cnt = -1;
    while(1) {
        if(current_node == NULL) {
            printf("Could not find anything\n");
            return;
        }
        next_node = current_node->nextPtr;
        if(current_node->value == value) {
            printf("Value %d found at index %d\n", value, cnt);
            return;
        }
        current_node = next_node;
        cnt++;
    }
}

// Displaying list members
void display(struct node *head) {
    int i = 0;
    struct node *current_node = head;
    struct node *next_node;
    printf("\nValues:\n");
    while(1) {
        next_node = current_node->nextPtr;
        if (i > 0) {
            printf("Value %d is %d\n", i - 1, current_node->value);
        }
        if(next_node == NULL) {
            break;
        }
        else {
            current_node = next_node;
        }
        i++;
    }
}

int main() {
    // Variables associated with user interface
    int choice, value, position;
    
    // Declaration of first member of list, the head, which is not actually represented in the list
    // The head simply points to first member, which we can then manipulate, the head pointer always remains the same
    struct node head;
    head.value = 0;
    head.nextPtr = NULL;

    // Infinite loop of user interface for manipulating the list
    while(choice!=8) {
        choice = 0;
        value = 0;
        position = 0;

        printf("\nSelect your operation:\n1. Insert at first\n2. Insert at last\n3. Insert at position\n4. Delete from position\n5. Update node value\n6. Search an element\n7. Display list\n8. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 8) {
            printf("Exiting..\n");
            break;
        }

        // Call of various methods based on user input
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_first(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_last(&head, value);
                break;
            case 3:
                printf("Enter position to put new value into: ");
                scanf("%d", &position);
                printf("Enter value: ");
                scanf("%d", &value);
                insert_position(&head, value, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_position(&head, position);
                break;
            case 5:
                printf("Enter position to update value: ");
                scanf("%d", &position);
                printf("Enter value: ");
                scanf("%d", &value);
                update(&head, value, position);
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(&head, value);
                break;
            case 7:
                display(&head);
                break;
            default:
                printf("\nWrong input, try again.\n");
                break;
        }
    }
    return 0;
}
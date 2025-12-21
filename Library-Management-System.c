#include <stdio.h>
#include <string.h>

struct Library {
    int book_id;
    char book_name[50];
    char author[50];
    int quantity;
};

int main() {
    struct Library lib[100];
    int choice, n = 0, i, id, found;

    while (1) {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &lib[n].book_id);
            printf("Enter Book Name: ");
            scanf(" %[^\n]", lib[n].book_name);
            printf("Enter Author Name: ");
            scanf(" %[^\n]", lib[n].author);
            printf("Enter Quantity: ");
            scanf("%d", &lib[n].quantity);
            n++;
            printf("Book added successfully!\n");
            break;

        case 2:
            if (n == 0) {
                printf("No books available.\n");
            } else {
                printf("\nBook ID\tBook Name\tAuthor\t\tQuantity\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t%s\t%s\t%d\n",
                           lib[i].book_id,
                           lib[i].book_name,
                           lib[i].author,
                           lib[i].quantity);
                }
            }
            break;

        case 3:
            printf("Enter Book ID to search: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (lib[i].book_id == id) {
                    printf("Book Found!\n");
                    printf("Name: %s\n", lib[i].book_name);
                    printf("Author: %s\n", lib[i].author);
                    printf("Quantity: %d\n", lib[i].quantity);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Book not found!\n");
            break;

        case 4:
            printf("Enter Book ID to issue: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (lib[i].book_id == id) {
                    if (lib[i].quantity > 0) {
                        lib[i].quantity--;
                        printf("Book issued successfully!\n");
                    } else {
                        printf("Book not available!\n");
                    }
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Book not found!\n");
            break;

        case 5:
            printf("Enter Book ID to return: ");
            scanf("%d", &id);
            found = 0;
            for (i = 0; i < n; i++) {
                if (lib[i].book_id == id) {
                    lib[i].quantity++;
                    printf("Book returned successfully!\n");
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Book not found!\n");
            break;

        case 6:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

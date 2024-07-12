#include <stdio.h>

#include <string.h>


#define MAX_BOOKS 10


typedef struct {

    int isbn;

    char title[50];

    char author[50];

    char genre[20];

    int quantity;

} Book;


typedef union {

    int isbn;

    char title[50];

    char author[50];

    char genre[20];

} SearchCriteria;


void display_menu() {

    printf("Library Management System\n");

    printf("1. Add Book\n");

    printf("2. Search Book\n");

    printf("3. Update Book Quantity\n");

    printf("4. Delete Book\n");

    printf("5. Display All Books\n");

    printf("6. Exit\n");

    printf("Enter your choice: ");

}


void add_book(Book books[], int *num_books) {

    printf("Enter book details:\n");

    printf("ISBN: ");

    scanf("%d", &books[*num_books].isbn);

    printf("Title: ");

    scanf("%49s", books[*num_books].title);

    printf("Author: ");

    scanf("%49s", books[*num_books].author);

    printf("Genre: ");

    scanf("%19s", books[*num_books].genre);

    printf("Quantity: ");

    scanf("%d", &books[*num_books].quantity);

    (*num_books)++;

}


void search_book(Book books[], int num_books) {

    SearchCriteria criteria;

    int choice;

    printf("Search by:\n");

    printf("1. ISBN\n");

    printf("2. Title\n");

    printf("3. Author\n");

    printf("4. Genre\n");

    printf("Enter your choice: ");

    scanf("%d", &choice);


    switch (choice) {

        case 1:

            printf("Enter ISBN: ");

            scanf("%d", &criteria.isbn);

            break;

        case 2:

            printf("Enter Title: ");

            scanf("%49s", criteria.title);

            break;

        case 3:

            printf("Enter Author: ");

            scanf("%49s", criteria.author);

            break;

        case 4:

            printf("Enter Genre: ");

            scanf("%19s", criteria.genre);

            break;

        default:

            printf("Invalid choice\n");

            return;

    }


    int found = 0;

    for (int i = 0; i < num_books; i++) {

        switch (choice) {

            case 1:

                if (books[i].isbn == criteria.isbn) {

                    found = 1;

                    break;

                }

            case 2:

                if (strcmp(books[i].title, criteria.title) == 0) {

                    found = 1;

                    break;

                }

            case 3:

                if (strcmp(books[i].author, criteria.author) == 0) {

                    found = 1;

                    break;

                }

            case 4:

                if (strcmp(books[i].genre, criteria.genre) == 0) {

                    found = 1;

                    break;

                }

        }

        if (found) {

            printf("Book found:\n");

            printf("ISBN: %d\n", books[i].isbn);

            printf("Title: %s\n", books[i].title);

            printf("Author: %s\n", books[i].author);

            printf("Genre: %s\n", books[i].genre);

            printf("Quantity: %d\n", books[i].quantity);

            return;

        }

    }

    printf("Book not found\n");

}


void update_book_quantity(Book books[], int num_books) {

    int isbn;

    printf("Enter ISBN of book to update: ");

    scanf("%d", &isbn);

    for (int i = 0; i < num_books; i++) {

        if (books[i].isbn == isbn) {

            printf("Enter new quantity: ");

            scanf("%d", &books[i].quantity);

            printf("Quantity updated successfully\n");

            return;

        }

    }

    printf("Book not found\n");

}


void delete_book(Book books[], int *num_books) {

    int isbn;

    printf("Enter ISBN of book to delete: ");

    scanf("%d", &isbn);

    for (int i = 0; i < *num_books; i++) {

        if (books[i].isbn == isbn) {

            for (int j = i; j < *num_books - 1; j++) {

                books[j] = books[j + 1];

            }

            (*num_books)--;

            printf("Book deleted successfully\n");

            return;

        }

    }

    printf("Book not found\n");

}


void display_all_books(Book books[], int num_books) {

    printf("All Books:\n");

    for (int i = 0; i < num_books; i++) {

        printf("ISBN: %d\n", books[i].isbn);

        printf("Title: %s\n", books[i].title);

        printf("Author: %s\n", books[i].author);

        printf("Genre: %s\n", books[i].genre);

        printf("Quantity: %d\n", books[i].quantity);

    }

}


void perform_action(Book books[], int *num_books) {

    int choice;

    while (1) {

        printf("\n");

        printf("1. Add book\n");

        printf("2. Search book\n");

        printf("3. Update book quantity\n");

        printf("4. Delete book\n");

        printf("5. Display all books\n");

        printf("6. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:

                add_book(books, num_books);

                break;

            case 2:

                search_book(books, *num_books);

                break;

            case 3:

                update_book_quantity(books, *num_books);

                break;

            case 4:

                delete_book(books, num_books);

                break;

            case 5:

                display_all_books(books, *num_books);

                break;

            case 6:

                return;

            default:

                printf("Invalid choice\n");

        }

    }

}


int main() {

    Book books[MAX_BOOKS];

    int num_books = 0;

    perform_action(books, &num_books);

    return 0;

}

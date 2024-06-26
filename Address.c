#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Contact struct to represent each contact
typedef struct {
    char name[50];
    char phoneNumber[20];
    char email[50];
} Contact;

// AddressBook struct to manage contacts
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int numContacts;
} AddressBook;

// Function prototypes
void addContact(AddressBook *addressBook, const char *name, const char *phoneNumber, const char *email);
void displayContacts(const AddressBook *addressBook);
void search(const AddressBook *addressBook, const char *keyword);
void addAll(AddressBook *addressBook, Contact newContacts[], int numNewContacts);
void removeContact(AddressBook *addressBook, const char *name);
void removeAll(AddressBook *addressBook);
void sortByName(AddressBook *addressBook);
void sortByNumber(AddressBook *addressBook);
void clear(AddressBook *addressBook);
int getSize(const AddressBook *addressBook);
void swap(Contact *a, Contact *b);
void menu();

int main() {
    AddressBook addressBook;
    addressBook.numContacts = 0;
    int choice;
    char name[50], phoneNumber[20], email[50], keyword[50];
    int numContactsToAdd;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                printf("Enter phone number: ");
                fgets(phoneNumber, sizeof(phoneNumber), stdin);
                phoneNumber[strcspn(phoneNumber, "\n")] = '\0'; // Remove newline character
                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove newline character
                addContact(&addressBook, name, phoneNumber, email);
                break;
            case 2:
                printf("Enter number of contacts to add: ");
                scanf("%d", &numContactsToAdd);
                getchar(); // Consume newline character
                Contact newContacts[numContactsToAdd];
                for (int i = 0; i < numContactsToAdd; i++) {
                    printf("Contact %d:\n", i + 1);
                    printf("Enter name: ");
                    fgets(newContacts[i].name, sizeof(newContacts[i].name), stdin);
                    newContacts[i].name[strcspn(newContacts[i].name, "\n")] = '\0'; // Remove newline character
                    printf("Enter phone number: ");
                    fgets(newContacts[i].phoneNumber, sizeof(newContacts[i].phoneNumber), stdin);
                    newContacts[i].phoneNumber[strcspn(newContacts[i].phoneNumber, "\n")] = '\0'; // Remove newline character
                    printf("Enter email: ");
                    fgets(newContacts[i].email, sizeof(newContacts[i].email), stdin);
                    newContacts[i].email[strcspn(newContacts[i].email, "\n")] = '\0'; // Remove newline character
                }
                addAll(&addressBook, newContacts, numContactsToAdd);
                break;
            case 3:
                displayContacts(&addressBook);
                break;
            case 4:
                printf("Enter name or phone number to search: ");
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = '\0'; // Remove newline character
                search(&addressBook, keyword);
                break;
            case 5:
                printf("Enter name to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                removeContact(&addressBook, name);
                break;
            case 6:
                removeAll(&addressBook);
                break;
            case 7:
                sortByName(&addressBook);
                break;
            case 8:
                sortByNumber(&addressBook);
                break;
            case 9:
                printf("Current size of address book: %d\n", getSize(&addressBook));
                break;
            case 10:
                clear(&addressBook);
                break;
            case 11:
                printf("Exiting address book. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 11.\n");
        }
        printf("\n"); // Add a blank line for readability
    }

    return 0;
}

// Function definitions
void addContact(AddressBook *addressBook, const char *name, const char *phoneNumber, const char *email) {
    if (addressBook->numContacts < MAX_CONTACTS) {
        strcpy(addressBook->contacts[addressBook->numContacts].name, name);
        strcpy(addressBook->contacts[addressBook->numContacts].phoneNumber, phoneNumber);
        strcpy(addressBook->contacts[addressBook->numContacts].email, email);
        addressBook->numContacts++;
        printf("Contact added successfully!\n");
    } else {
        printf("Address book is full. Cannot add more contacts.\n");
    }
}

void displayContacts(const AddressBook *addressBook) {
    if (addressBook->numContacts == 0) {
        printf("Address book is empty.\n");
    } else {
        printf("Listing all contacts:\n");
        for (int i = 0; i < addressBook->numContacts; i++) {
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone Number: %s\n", addressBook->contacts[i].phoneNumber);
            printf("Email: %s\n", addressBook->contacts[i].email);
            printf("--------------------\n");
        }
    }
}

void search(const AddressBook *addressBook, const char *keyword) {
    int found = 0;
    for (int i = 0; i < addressBook->numContacts; i++) {
        if (strcasecmp(addressBook->contacts[i].name, keyword) == 0 || strcmp(addressBook->contacts[i].phoneNumber, keyword) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone Number: %s\n", addressBook->contacts[i].phoneNumber);
            printf("Email: %s\n", addressBook->contacts[i].email);
            printf("--------------------\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void addAll(AddressBook *addressBook, Contact newContacts[], int numNewContacts) {
    if (addressBook->numContacts + numNewContacts <= MAX_CONTACTS) {
        for (int i = 0; i < numNewContacts; i++) {
            addressBook->contacts[addressBook->numContacts++] = newContacts[i];
        }
        printf("Contacts added successfully!\n");
    } else {
        printf("Not enough space to add all contacts.\n");
    }
}

void removeContact(AddressBook *addressBook, const char *name) {
    int found = 0;
    for (int i = 0; i < addressBook->numContacts; i++) {
        if (strcasecmp(addressBook->contacts[i].name, name) == 0) {
            for (int j = i; j < addressBook->numContacts - 1; j++) {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->numContacts--;
            printf("Contact removed successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void removeAll(AddressBook *addressBook) {
    addressBook->numContacts = 0;
    printf("All contacts removed successfully.\n");
}

void sortByName(AddressBook *addressBook) {
    for (int i = 0; i < addressBook->numContacts - 1; i++) {
        for (int j = i + 1; j < addressBook->numContacts; j++) {
            if (strcasecmp(addressBook->contacts[i].name, addressBook->contacts[j].name) > 0) {
                swap(&addressBook->contacts[i], &addressBook->contacts[j]);
            }
        }
    }
    printf("Contacts sorted by name.\n");
}

void sortByNumber(AddressBook *addressBook) {
    for (int i = 0; i < addressBook->numContacts - 1; i++) {
        for (int j = i + 1; j < addressBook->numContacts; j++) {
            if (strcmp(addressBook->contacts[i].phoneNumber, addressBook->contacts[j].phoneNumber) > 0) {
                swap(&addressBook->contacts[i], &addressBook->contacts[j]);
            }
        }
    }
    printf("Contacts sorted by phone number.\n");
}

void clear(AddressBook *addressBook) {
    addressBook->numContacts = 0;
    printf("Address book cleared.\n");
}

int getSize(const AddressBook *addressBook) {
    return addressBook->numContacts;
}

void swap(Contact *a, Contact *b) {
    Contact temp = *a;
    *a = *b;
    *b = temp;
}

void menu() {
    printf("Address Book Menu:\n");
    printf("1. Add a new contact\n");
    printf("2. Add multiple contacts\n");
    printf("3. Display all contacts\n");
    printf("4. Search for a contact by name or phone number\n");
    printf("5. Remove a contact by name\n");
    printf("6. Remove all contacts\n");
    printf("7. Sort contacts by name\n");
    printf("8. Sort contacts by phone number\n");
    printf("9. Get size of address book\n");
    printf("10. Clear address book\n");
    printf("11. Exit\n");
}

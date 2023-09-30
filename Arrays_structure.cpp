#include <stdio.h>
#include <string.h>

struct person {
    char name[100];
    int age;
    char phone[15];
};

int main() {
    struct person addressBook[100]; // Assuming a maximum of 100 entries
    int choice, numEntries = 0;

    while (1) {
        printf("\nAddress Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Search by Name\n");
        printf("4. Edit Entry by Name\n");
        printf("5. Delete Entry by Name\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numEntries < 100) {
                    printf("Enter Name: ");
                    scanf("%s", addressBook[numEntries].name);
                    printf("Enter Age: ");
                    scanf("%d", &addressBook[numEntries].age);
                    printf("Enter Phone Number: ");
                    scanf("%s", addressBook[numEntries].phone);
                    numEntries++;
                    printf("Entry added successfully.\n");
                } else {
                    printf("Address book is full. Cannot add more entries.\n");
                }
                break;

            case 2:
                if (numEntries > 0) {
                    printf("\nAddress Book Entries:\n");
                    for (int i = 0; i < numEntries; i++) {
                        printf("Entry %d:\n", i + 1);
                        printf("Name: %s\n", addressBook[i].name);
                        printf("Age: %d\n", addressBook[i].age);
                        printf("Phone: %s\n", addressBook[i].phone);
                    }
                } else {
                    printf("Address book is empty.\n");
                }
                break;

            case 3:
                if (numEntries > 0) {
                    char searchName[100];
                    printf("Enter the name to search for: ");
                    scanf("%s", searchName);
                    int found = 0;
                    for (int i = 0; i < numEntries; i++) {
                        if (strcmp(searchName, addressBook[i].name) == 0) {
                            printf("Search Result:\n");
                            printf("Name: %s\n", addressBook[i].name);
                            printf("Age: %d\n", addressBook[i].age);
                            printf("Phone: %s\n", addressBook[i].phone);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("No matching entry found for %s\n", searchName);
                    }
                } else {
                    printf("Address book is empty.\n");
                }
                break;

            case 4:
                if (numEntries > 0) {
                    char editName[100];
                    printf("Enter the name to edit: ");
                    scanf("%s", editName);
                    int found = 0;
                    for (int i = 0; i < numEntries; i++) {
                        if (strcmp(editName, addressBook[i].name) == 0) {
                            printf("Enter new Name: ");
                            scanf("%s", addressBook[i].name);
                            printf("Enter new Age: ");
                            scanf("%d", &addressBook[i].age);
                            printf("Enter new Phone Number: ");
                            scanf("%s", addressBook[i].phone);
                            printf("Entry edited successfully.\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("No matching entry found for %s\n", editName);
                    }
                } else {
                    printf("Address book is empty.\n");
                }
                break;

            case 5:
                if (numEntries > 0) {
                    char deleteName[100];
                    printf("Enter the name to delete: ");
                    scanf("%s", deleteName);
                    int found = 0;
                    for (int i = 0; i < numEntries; i++) {
                        if (strcmp(deleteName, addressBook[i].name) == 0) {
                            // Shift entries to remove the entry to be deleted
                            for (int j = i; j < numEntries - 1; j++) {
                                strcpy(addressBook[j].name, addressBook[j + 1].name);
                                addressBook[j].age = addressBook[j + 1].age;
                                strcpy(addressBook[j].phone, addressBook[j + 1].phone);
                            }
                            numEntries--;
                            printf("Entry deleted successfully.\n");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("No matching entry found for %s\n", deleteName);
                    }
                } else {
                    printf("Address book is empty.\n");
                }
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

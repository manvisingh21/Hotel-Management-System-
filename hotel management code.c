#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 50

struct Customer {
    char name[MAX_NAME_LENGTH];
    int roomNumber;
};

struct Customer customers[MAX_ROOMS];
int bookedRooms[MAX_ROOMS] = {0};

void displayMenu() {
    printf("\n===== Hotel Management System =====\n");
    printf("1. Book a Room\n");
    printf("2. Check Room Availability\n");
    printf("3. Display Customer Information\n");
    printf("4. Exit\n");
    printf("===================================\n");
}

void bookRoom() {
    int roomNumber;

    printf("Enter Room Number (1 to 10): ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    if (bookedRooms[roomNumber - 1] == 0) {
        struct Customer newCustomer;

        printf("Enter Customer Name: ");
        scanf("%s", newCustomer.name);

        newCustomer.roomNumber = roomNumber;

        customers[roomNumber - 1] = newCustomer;
        bookedRooms[roomNumber - 1] = 1;

        printf("Room booked successfully!\n");
    } else {
        printf("Room is already booked.\n");
    }
}

void checkAvailability() {
    int roomNumber;

    printf("Enter Room Number (1 to 10): ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    if (bookedRooms[roomNumber - 1] == 0) {
        printf("Room is available.\n");
    } else {
        printf("Room is already booked.\n");
    }
}

void displayCustomerInfo() {
    int roomNumber;

    printf("Enter Room Number (1 to 10): ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    if (bookedRooms[roomNumber - 1] == 1) {
        struct Customer customer = customers[roomNumber - 1];
        printf("Customer Name: %s\n", customer.name);
        printf("Room Number: %d\n", customer.roomNumber);
    } else {
        printf("Room is not booked yet.\n");
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                checkAvailability();
                break;
            case 3:
                displayCustomerInfo();
                break;
            case 4:
                printf("Exiting Hotel Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

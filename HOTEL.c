#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a hotel room
typedef struct {
    int roomNumber;
    char guestName[50];
    int isOccupied;
} Room;

// Function prototypes
void initializeRooms(Room rooms[], int numRooms);
void displayMenu();
void displayRooms(Room rooms[], int numRooms);
void bookRoom(Room rooms[], int numRooms);
void checkoutRoom(Room rooms[], int numRooms);

int main() {
    const int numRooms = 5; // Change this to the number of rooms in your hotel
    Room rooms[numRooms];

    initializeRooms(rooms, numRooms);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, numRooms);
                break;
            case 2:
                bookRoom(rooms, numRooms);
                break;
            case 3:
                checkoutRoom(rooms, numRooms);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize rooms in the hotel
void initializeRooms(Room rooms[], int numRooms) {
    for (int i = 0; i < numRooms; ++i) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isOccupied = 0; // 0 means the room is not occupied
        strcpy(rooms[i].guestName, "");
    }
}

// Function to display the main menu
void displayMenu() {
    printf("\n===== Hotel Management System =====\n");
    printf("1. Display Rooms\n");
    printf("2. Book a Room\n");
    printf("3. Checkout\n");
    printf("4. Exit\n");
}

// Function to display the status of each room
void displayRooms(Room rooms[], int numRooms) {
    printf("\n===== Room Status =====\n");
    printf("Room Number\tGuest Name\tOccupied\n");

    for (int i = 0; i < numRooms; ++i) {
        printf("%d\t\t%s\t\t%s\n", rooms[i].roomNumber, rooms[i].guestName,
               rooms[i].isOccupied ? "Yes" : "No");
    }
}

// Function to book a room
void bookRoom(Room rooms[], int numRooms) {
    int roomNumber;
    printf("Enter the room number to book: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > numRooms) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    if (rooms[roomNumber - 1].isOccupied) {
        printf("Sorry, the room is already occupied.\n");
    } else {
        printf("Enter guest name: ");
        scanf("%s", rooms[roomNumber - 1].guestName);
        rooms[roomNumber - 1].isOccupied = 1;
        printf("Room booked successfully!\n");
    }
}

// Function to checkout from a room
void checkoutRoom(Room rooms[], int numRooms) {
    int roomNumber;
    printf("Enter the room number to checkout: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > numRooms) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    if (rooms[roomNumber - 1].isOccupied) {
        printf("Guest %s has checked out from Room %d.\n",
               rooms[roomNumber - 1].guestName, roomNumber);
        rooms[roomNumber - 1].isOccupied = 0;
        strcpy(rooms[roomNumber - 1].guestName, "");
    } else {
        printf("Room %d is not occupied.\n", roomNumber);
    }
}

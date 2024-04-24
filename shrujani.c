#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold grocery item information
struct GroceryItem {
    char name[50];
    float price;
};

void displayMenu(struct GroceryItem items[], int size);
void getCustomerDetails(char **name, char **email, char **address);
int login(char *username, char *password);

int main() {
    struct GroceryItem groceryItems[5] = {{"Apple", 1.00}, {"Banana", 0.50}, {"Orange", 0.75}, {"Potato", 1.25}, {"Carrot", 0.89}};
    int choice;
    int quantity;
    float total = 0.0;
    char *name = NULL;
    char *email = NULL;
    char *address = NULL;

    printf("Welcome to our grocery store!\n\n");
    displayMenu(groceryItems, 5);

    printf("\nEnter your choice (1-5): ");
    scanf("%d", &choice);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (choice >= 1 && choice <= 5) {
        total += groceryItems[choice - 1].price * quantity;
        printf("Added %s to your cart.\n", groceryItems[choice - 1].name);
    } else {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    getCustomerDetails(&name, &email, &address);

    printf("\n\n--------- Order Summary ---------\n");
    printf("Customer Name: %s\n", name);
    printf("Customer Email: %s\n", email);
    printf("Customer Address: %s\n", address);
    printf("Total: $%.2f\n", total);

    // Free dynamically allocated memory
    free(name);
    free(email);
    free(address);

    return 0;
}

void displayMenu(struct GroceryItem items[], int size) {
    printf("Menu:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

void getCustomerDetails(char **name, char **email, char **address) {
    *name = (char *)malloc(50 * sizeof(char));
    *email = (char *)malloc(100 * sizeof(char));
    *address = (char *)malloc(100 * sizeof(char));

    printf("\nEnter your name: ");
    scanf("%s", *name);
    printf("Enter your email: ");
    scanf("%s", *email);
    printf("Enter your address: ");
    scanf("%s", *address);
}

// Simple login function, returns 1 if login successful, 0 otherwise
int login(char *username, char *password) {
    // Implement your login logic here
    // For simplicity, let's assume the username is "admin" and password is "password"
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }
}

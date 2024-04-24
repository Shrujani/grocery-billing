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

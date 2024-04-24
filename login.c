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

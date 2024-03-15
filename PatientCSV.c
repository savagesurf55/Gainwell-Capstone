#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Define maximum length for a line in the CSV file
#define MAX_LINE_LENGTH 1024

// Database connection details
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASSWORD "student"
#define DB_NAME "hospital"

MYSQL *conn; // MySQL connection object

// Function to execute SQL queries
void execute_query(const char *query) {
    // Execute the query and handle any errors
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query execution error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Open the CSV file containing patient data
    FILE *csv_file = fopen("CSV Files/patients.csv", "r");
    if (!csv_file) {
        fprintf(stderr, "Error opening file: patients.csv\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the MySQL connection
    conn = mysql_init(NULL);
    if (!conn) {
        fprintf(stderr, "Error initializing MySQL: %s\n", mysql_error(conn));
        exit(EXIT_FAILURE);
    }

    // Connect to the MySQL database
    if (!mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASSWORD, DB_NAME, 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to MySQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH]; // Buffer to store each line from the CSV file
    while (fgets(line, sizeof(line), csv_file)) { // Read each line from the CSV file
        line[strcspn(line, "\n")] = '\0'; // Remove newline character at the end of the line

        char *token;
        token = strtok(line, ","); // Tokenize the line using comma as the delimiter
        char *values[9]; // Array to store the tokenized values
        int i = 0;
        while (token != NULL) { // Iterate over each token
            values[i++] = token; // Store the token in the values array
            token = strtok(NULL, ","); // Get the next token
        }

        // Construct the SQL query to insert the patient data into the database
        char query[MAX_LINE_LENGTH];
        snprintf(query, sizeof(query),
                "INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, City, State, ZipCode, Phone, Email) "
                "VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')",
                values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8], values[9]);

        // Execute the query to insert the patient data
        execute_query(query);
    }

    // Close the CSV file and MySQL connection
    fclose(csv_file);
    mysql_close(conn);

    return 0;
}

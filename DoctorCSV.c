#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

// Define constants for maximum line length and database connection details
#define MAX_LINE_LENGTH 1024
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASSWORD "student"
#define DB_NAME "hospital"

// Global MySQL connection object
MYSQL *conn;

// Function to execute SQL queries
void execute_query(const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query execution error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Open the CSV file for reading
    FILE *csv_file = fopen("CSV Files/doctors.csv", "r");
    if (!csv_file) {
        fprintf(stderr, "Error opening file: CSV files/doctors.csv\n");
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

    // Read each line from the CSV file and insert into the database
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), csv_file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        // Tokenize the line based on commas
        char *token;
        token = strtok(line, ",");
        char *values[6]; // Assuming there are 6 fields in the CSV
        int i = 0;
        while (token != NULL) {
            values[i++] = token;
            token = strtok(NULL, ",");
        }

        // Construct and execute the SQL query to insert the doctor information
        char query[MAX_LINE_LENGTH];
        snprintf(query, sizeof(query),
                 "INSERT INTO Doctor (FirstName, LastName, Specialization, Phone, Email) "
                 "VALUES ('%s', '%s', '%s', '%s', '%s')",
                 values[0], values[1], values[2], values[4], values[3]);
        execute_query(query);
    }

    // Close the CSV file and MySQL connection
    fclose(csv_file);
    mysql_close(conn);

    return 0;
}

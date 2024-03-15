#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

#define MAX_LINE_LENGTH 1024

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASSWORD "student"
#define DB_NAME "hospital"

MYSQL *conn; // MySQL connection object

// Function to execute SQL queries
void execute_query(const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query execution error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }
}

int main() 
{
    // Open the CSV file for reading
    FILE *csv_file = fopen("CSV Files/appointments.csv", "r");
    if (!csv_file) {
        fprintf(stderr, "Error opening file: CSV Files/appointments.csv\n");
        exit(EXIT_FAILURE);
    }

    // Initialize MySQL connection
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

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), csv_file)) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character

        char *token;
        token = strtok(line, ",");
        char *values[7];
        int i = 0;
        while (token != NULL) {
            values[i++] = token;
            token = strtok(NULL, ",");
        }

        // Check if the PatientID exists in the Patient table
        char check_query[MAX_LINE_LENGTH];
        snprintf(check_query, sizeof(check_query),
                 "SELECT * FROM Patient WHERE PatientID = %s", values[0]);
        if (mysql_query(conn, check_query)) {
            fprintf(stderr, "Query execution error: %s\n", mysql_error(conn));
            mysql_close(conn);
            exit(EXIT_FAILURE);
        }
        MYSQL_RES *result = mysql_store_result(conn);
        if (!mysql_fetch_row(result)) {
            fprintf(stderr, "Error: PatientID %s does not exist in the Patient table\n", values[0]);
            mysql_close(conn);
            exit(EXIT_FAILURE);
        }
        mysql_free_result(result);

        // Insert the appointment data into the Appointment table
        char query[MAX_LINE_LENGTH];
        snprintf(query, sizeof(query),
                 "INSERT INTO Appointment (PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) "
                 "VALUES (%s, %s, '%s', '%s', '%s', '%s')",
                 values[0], values[1], values[2], values[3], values[4], values[5]);
        execute_query(query);
    }

    // Close the CSV file and MySQL connection
    fclose(csv_file);
    mysql_close(conn);

    return 0;
}
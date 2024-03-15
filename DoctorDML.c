#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database connection settings
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

// Function to add a new doctor
void addNewDoctor() {
    char firstName[255], lastName[255], specialization[255], phone[20], email[255];

    printf("Enter Doctor Details:\n");
    printf("First Name: ");
    scanf("%s", firstName);
    printf("Last Name: ");
    scanf("%s", lastName);
    printf("Specialization: ");
    scanf("%s", specialization);
    printf("Phone: ");
    scanf("%s", phone);
    printf("Email: ");
    scanf("%s", email);

    char insertQuery[2048];
    snprintf(insertQuery, sizeof(insertQuery),
             "INSERT INTO Doctor (FirstName, LastName, Specialization, Phone, Email) "
             "VALUES ('%s', '%s', '%s', '%s', '%s')",
             firstName, lastName, specialization, phone, email);

    execute_query(insertQuery);
    printf("Doctor added successfully!\n");
}

// Function to search for doctor information
void searchDoctorInformation() {
    char searchTerm[255];

    printf("Enter search term (name, ID, etc.): ");
    scanf("%s", searchTerm);

    char selectQuery[1024];
    snprintf(selectQuery, sizeof(selectQuery),
             "SELECT * FROM Doctor WHERE FirstName LIKE '%%%s%%' OR LastName LIKE '%%%s%%' OR DoctorID = '%s'",
             searchTerm, searchTerm, searchTerm);

    execute_query(selectQuery);

    MYSQL_RES *result = mysql_use_result(conn);
    if (result) {
        MYSQL_ROW row;
        printf("\nSearch Results:\n");
        while ((row = mysql_fetch_row(result))) {
            printf("DoctorID: %s, Name: %s %s, Specialization: %s, Email: %s, Phone: %s\n",
                   row[0], row[1], row[2], row[3], row[5], row[4]);
        }
        mysql_free_result(result);
    }
}



// Function to update doctor information
void updateDoctorInformation() {
    int doctorID, updateChoice;
    char newValue[255];

    printf("Enter Doctor ID to update: ");
    scanf("%d", &doctorID);

    printf("What would you like to update?\n");
    printf("1. Phone\n");
    printf("2. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &updateChoice);

    printf("Enter the new value: ");
    scanf("%s", newValue);

    char updateQuery[512];
    switch (updateChoice) {
        case 1:
            snprintf(updateQuery, sizeof(updateQuery),
                     "UPDATE Doctor SET Phone='%s' WHERE DoctorID=%d",
                     newValue, doctorID);
            break;
        case 2:
            snprintf(updateQuery, sizeof(updateQuery),
                     "UPDATE Doctor SET Email='%s' WHERE DoctorID=%d",
                     newValue, doctorID);
            break;
        default:
            printf("Invalid update choice.\n");
            return;
    }

    execute_query(updateQuery);
    printf("Doctor information updated successfully!\n");
}

int main() {
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

    int choice;
    // Main menu loop
    do {
        printf("\nDoctor Menu:\n");
        printf("1. Add New Doctor\n");
        printf("2. Search Doctor Information\n");
        printf("3. Update Doctor Information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check if the choice is within the valid range
        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            // Clear input buffer
            while(getchar() != '\n');
            continue; // Continue to the next iteration of the loop
        }

        switch (choice) {
            case 1:
                addNewDoctor();
                break;
            case 2:
                searchDoctorInformation();
                break;
            case 3:
                updateDoctorInformation();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Close MySQL connection and exit
    mysql_close(conn);
    return EXIT_SUCCESS;
}

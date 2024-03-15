#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASSWORD "student"
#define DB_NAME "hospital"

MYSQL *conn;// MySQL connection object

// Function to execute SQL queries
void execute_query(const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query execution error: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }
}

// Function to schedule a new appointment
void scheduleNewAppointment() {
    // Input variables
    int patientID, doctorID;
    char date[11], time[9], purpose[255];

    // Get user input
    printf("Enter Patient ID: ");
    scanf("%d", &patientID);
    printf("Enter Doctor ID: ");
    scanf("%d", &doctorID);
    printf("Enter Appointment Date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter Appointment Time (HH:MM:SS): ");
    scanf("%s", time);
    printf("Enter Purpose of Appointment: ");
    scanf("%s", purpose);

    // Construct and execute the SQL query to insert the new appointment
    char insertQuery[512];
    snprintf(insertQuery, sizeof(insertQuery),
             "INSERT INTO Appointment (PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) "
             "VALUES (%d, %d, '%s', '%s', '%s', 'Scheduled')",
             patientID, doctorID, date, time, purpose);

    execute_query(insertQuery);
    printf("Appointment scheduled successfully!\n");
}

// Function to update an existing appointment
void updateExistingAppointment() {
    // Input variables
    int appointmentID, updateChoice;
    char newValue[255];

    // Get user input
    printf("Enter Appointment ID to update: ");
    scanf("%d", &appointmentID);

    // Choose what to update
    printf("\nWhat would you like to update?\n");
    printf("1. Appointment Date\n");
    printf("2. Appointment Time\n");
    printf("3. Purpose of Appointment\n");
    printf("Enter your choice: ");
    scanf("%d", &updateChoice);

    // Get new value based on user choice and construct the SQL query
    char updateQuery[512];
    switch (updateChoice) {
        case 1:
            printf("Enter new Appointment Date (YYYY-MM-DD): ");
            scanf("%s", newValue);
            snprintf(updateQuery, sizeof(updateQuery), "UPDATE Appointment SET AppointmentDate='%s' WHERE AppointmentID=%d", newValue, appointmentID);
            break;
        case 2:
            printf("Enter new Appointment Time (HH:MM:SS): ");
            scanf("%s", newValue);
            snprintf(updateQuery, sizeof(updateQuery), "UPDATE Appointment SET AppointmentTime='%s' WHERE AppointmentID=%d", newValue, appointmentID);
            break;
        case 3:
            printf("Enter new Purpose of Appointment: ");
            scanf("%s", newValue);
            snprintf(updateQuery, sizeof(updateQuery), "UPDATE Appointment SET Purpose='%s' WHERE AppointmentID=%d", newValue, appointmentID);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    // Execute the SQL query to update the appointment
    execute_query(updateQuery);
    printf("Appointment updated successfully!\n");
}


// Function to cancel an appointment
void cancelAppointment() {
    // Input variable
    int appointmentID;

    //User Input
    printf("Enter Appointment ID to cancel: ");
    scanf("%d", &appointmentID);

    // Construct and execute the SQL query to cancel the appointment
    char cancelQuery[512];
    snprintf(cancelQuery, sizeof(cancelQuery),
             "UPDATE Appointment SET Status='Cancelled' WHERE AppointmentID=%d",
             appointmentID);

    execute_query(cancelQuery);
    printf("Appointment cancelled successfully!\n");
}

// Function to search for an appointment
void searchAppointment() {
    int searchChoice;
    printf("Select search criteria:\n");
    printf("1. Appointment ID\n");
    printf("2. Patient ID\n");
    printf("3. Doctor ID\n");
    printf("Enter your choice: ");
    scanf("%d", &searchChoice);

    int id;
    switch (searchChoice) {
        case 1:
            printf("Enter Appointment ID to search: ");
            scanf("%d", &id);
            break;
        case 2:
            printf("Enter Patient ID to search: ");
            scanf("%d", &id);
            break;
        case 3:
            printf("Enter Doctor ID to search: ");
            scanf("%d", &id);
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    char searchQuery[512];
    // Construct the SQL query based on the selected search criteria
    switch (searchChoice) {
        case 1:
            snprintf(searchQuery, sizeof(searchQuery),
                     "SELECT A.AppointmentID, A.PatientID, P.FirstName AS PatientFirstName, P.LastName AS PatientLastName, "
                     "A.DoctorID, D.FirstName AS DoctorFirstName, D.LastName AS DoctorLastName, "
                     "A.AppointmentDate, A.AppointmentTime, A.Purpose, A.Status "
                     "FROM Appointment A "
                     "JOIN Patient P ON A.PatientID = P.PatientID "
                     "JOIN Doctor D ON A.DoctorID = D.DoctorID "
                     "WHERE A.AppointmentID=%d", id);
            break;
        case 2:
            snprintf(searchQuery, sizeof(searchQuery),
                     "SELECT A.AppointmentID, A.PatientID, P.FirstName AS PatientFirstName, P.LastName AS PatientLastName, "
                     "A.DoctorID, D.FirstName AS DoctorFirstName, D.LastName AS DoctorLastName, "
                     "A.AppointmentDate, A.AppointmentTime, A.Purpose, A.Status "
                     "FROM Appointment A "
                     "JOIN Patient P ON A.PatientID = P.PatientID "
                     "JOIN Doctor D ON A.DoctorID = D.DoctorID "
                     "WHERE A.PatientID=%d", id);
            break;
        case 3:
            snprintf(searchQuery, sizeof(searchQuery),
                     "SELECT A.AppointmentID, A.PatientID, P.FirstName AS PatientFirstName, P.LastName AS PatientLastName, "
                     "A.DoctorID, D.FirstName AS DoctorFirstName, D.LastName AS DoctorLastName, "
                     "A.AppointmentDate, A.AppointmentTime, A.Purpose, A.Status "
                     "FROM Appointment A "
                     "JOIN Patient P ON A.PatientID = P.PatientID "
                     "JOIN Doctor D ON A.DoctorID = D.DoctorID "
                     "WHERE A.DoctorID=%d", id);
            break;
        default:
            return;
    }

    // Execute the SQL query
    execute_query(searchQuery);
    MYSQL_RES *result = mysql_use_result(conn);
    if (result) {
        MYSQL_ROW row;
        printf("\nSearch Results:\n");
        // Iterate over the result set and print each appointment's details
        while ((row = mysql_fetch_row(result))) {
            printf("AppointmentID: %s, PatientID: %s, Patient Name: %s %s, \nDoctorID: %s, Doctor Name: %s %s, "
                   "\nDate: %s, Time: %s, Purpose: %s, Status: %s\n",
                   row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10]);
        }
        // Free the result set
        mysql_free_result(result);
    } else {
        printf("No appointments found.\n");
    }
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
    do {
        //Main Menu Loop
        printf("\nAppointment Menu:\n");
        printf("1. Schedule New Appointment\n");
        printf("2. Update Existing Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Search Appointment\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check if the choice is within the valid range
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            // Clear input buffer
            while(getchar() != '\n');
            continue; // Continue to the next iteration of the loop
        }

        // Switch case based on user choice
        switch (choice) {
            case 1:
                scheduleNewAppointment();
                break;
            case 2:
                updateExistingAppointment();
                break;
            case 3:
                cancelAppointment();
                break;
            case 4:
                searchAppointment();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Close MySQL connection
    mysql_close(conn);
    return EXIT_SUCCESS;
}

#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASSWORD "student"
#define DB_NAME "hospital"

MYSQL *conn;

//SQL query function
void execute_query(const char *query) 
{
if (mysql_query(conn, query)) 
    {
    fprintf(stderr, "Query execution error: %s\n",
    mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
    }
}

int main() 
{
    //connect to MySQL
    conn = mysql_init(NULL);
    if (conn == NULL) 
        {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
        }
    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASSWORD, NULL, 0, NULL, 0) == NULL)   
        {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return EXIT_FAILURE;
        }

    // Drop database if exists
    execute_query("DROP DATABASE IF EXISTS hospital");

    // Create database
    execute_query("CREATE DATABASE IF NOT EXISTS hospital");

    // Use the hospital database
    execute_query("USE hospital");

    //create Patient Table
    execute_query("CREATE TABLE IF NOT EXISTS Patient ("
                          "PatientID INT AUTO_INCREMENT PRIMARY KEY,"
                          "FirstName VARCHAR(255) NOT NULL,"
                          "LastName VARCHAR(255) NOT NULL,"
                          "DateOfBirth DATE,"
                          "Gender ENUM('Male', 'Female', 'Other'),"
                          "Address VARCHAR(255),"
                          "City VARCHAR(255),"
                          "State VARCHAR(255),"
                          "ZipCode VARCHAR(20),"
                          "Phone VARCHAR(20),"
                          "Email VARCHAR(255)"
                          ")");


    //create Doctor Table
    execute_query("CREATE TABLE IF NOT EXISTS Doctor ("
                          "DoctorID INT AUTO_INCREMENT PRIMARY KEY,"
                          "FirstName VARCHAR(255) NOT NULL,"
                          "LastName VARCHAR(255) NOT NULL,"
                          "Specialization VARCHAR(255) NOT NULL,"
                          "Phone VARCHAR(30),"
                          "Email VARCHAR(255)"
                          ")");
    
    //create Appointment Table
    execute_query("CREATE TABLE IF NOT EXISTS Appointment ("
                          "AppointmentID INT AUTO_INCREMENT PRIMARY KEY,"
                          "PatientID INT,"
                          "DoctorID INT,"
                          "AppointmentDate DATE,"
                          "AppointmentTime TIME,"
                          "Purpose VARCHAR(255),"
                          "Status ENUM('Scheduled', 'Completed', 'Cancelled'),"
                          "FOREIGN KEY (PatientID) REFERENCES Patient(PatientID),"
                          "FOREIGN KEY (DoctorID) REFERENCES Doctor(DoctorID)"
                          ")");

    //create TestResults Table
    execute_query("CREATE TABLE IF NOT EXISTS TestResults ("
                          "TestResultID INT AUTO_INCREMENT PRIMARY KEY,"
                          "PatientID INT,"
                          "DoctorID INT,"
                          "TestType VARCHAR(255),"
                          "Result VARCHAR(255),"
                          "TestDate DATE,"
                          "FOREIGN KEY (PatientID) REFERENCES Patient(PatientID),"
                          "FOREIGN KEY (DoctorID) REFERENCES Doctor(DoctorID)"
                          ")");

    //create EmergencyContacts Table
    execute_query("CREATE TABLE IF NOT EXISTS EmergencyContacts ("
                          "EmergencyContactID INT AUTO_INCREMENT PRIMARY KEY,"
                          "PatientID INT,"
                          "FirstName VARCHAR(255) NOT NULL,"
                          "LastName VARCHAR(255) NOT NULL,"
                          "Relationship VARCHAR(255) NOT NULL,"
                          "Phone VARCHAR(20),"
                          "FOREIGN KEY (PatientID) REFERENCES Patient(PatientID)"
                          ")");

    // Execute query to show tables
    if (mysql_query(conn, "SHOW TABLES")) {
        fprintf(stderr, "Failed to show tables: Error: %s\n", mysql_error(conn));
        return 1;
    }

    MYSQL_RES *res;
    MYSQL_ROW row;

    res = mysql_use_result(conn);

    // Fetch and print table names
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s\n", row[0]);
    }

    // Execute query to describe tables
    if (mysql_query(conn, "SELECT table_name, column_name, data_type, is_nullable FROM information_schema.columns WHERE table_schema = 'hospital'")) {
        fprintf(stderr, "Failed to describe tables: Error: %s\n", mysql_error(conn));
        return 1;
    }

    res = mysql_use_result(conn);

    // Fetch and print table descriptions
    char current_table[256] = "";
    while ((row = mysql_fetch_row(res)) != NULL) {
        if (strcmp(current_table, row[0]) != 0) {
            strcpy(current_table, row[0]);
            printf("Table: %s\n", current_table);
        }
        printf("  Column: %s, Type: %s, Nullable: %s\n", row[1], row[2], row[3]);
    }

    mysql_free_result(res);

    mysql_close(conn);

return 0;
}
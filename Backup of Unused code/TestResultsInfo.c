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
            // Use the hospital database
            execute_query("USE hospital");

            execute_query("INSERT INTO TestResults (PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID1', 'DoctorID1', 'High Blood Pressure', 'Negative', '2024-02-20')");
            
            execute_query("INSERT INTO TestResults ( PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID2', 'DoctorID2', 'Diabetes Screening', 'Negative', '2024-01-05')");

            execute_query("INSERT INTO TestResults ( PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID3', 'DoctorID3', 'Flu', 'Positive', '2023-10-30')");

            execute_query("INSERT INTO TestResults ( PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID4', 'DoctorID4', 'Bone density test', 'Negative', '2023-08-25')");
        
            execute_query("INSERT INTO TestResults ( PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID5', 'DoctorID5', 'Neurology Exam', 'Positive', '2024-01-16')");

            execute_query("INSERT INTO TestResults ( PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID6', 'DoctorID6', 'EKG heart disease', 'Negative', '2024-01-12')");

            execute_query("INSERT INTO TestResults ( PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID7', 'DoctorID7', 'Urinalysis', 'Negative', '2024-01-06')");

            execute_query("INSERT INTO TestResults ( PatientID, DoctorID, TestType, Result, TestDate) VALUES ('PatientID8', 'DoctorID8', 'Thyroid function testing', 'Positive', '2023-12-30')");
            
}
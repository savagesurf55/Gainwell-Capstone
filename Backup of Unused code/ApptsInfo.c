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

        execute_query("USE hospital");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-05', '08:30:00', 'Regular checkup', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-06', '09:30:00', 'Cardiology consultation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-07', '10:00:00', 'Follow-up', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-08', '08:30:00', 'Family medicine consultation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-09', '09:00:00', 'Neurology evaluation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-10', '10:30:00', 'Orthopedic consultation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-11', '08:30:00', 'Radiology screening', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-12', '09:30:00', 'Urology checkup', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-13', '10:00:00', 'General consultation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-14', '08:30:00', 'Follow-up', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-15', '09:00:00', 'Neurology consultation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-16', '10:30:00', 'Orthopedic follow-up', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-17', '08:30:00', 'Radiology screening', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-18', '09:30:00', 'Urology consultation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-19', '10:00:00', 'Family medicine checkup', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-20', '08:30:00', 'Cardiology consultation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-21', '09:00:00', 'Neurology follow-up', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-22', '10:30:00', 'Orthopedic evaluation', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-23', '08:30:00', 'Radiology screening', 'Scheduled')");

        execute_query ("INSERT INTO Appointments (AppointmentID, PatientID, DoctorID, AppointmentDate, AppointmentTime, Purpose, Status) VALUES ('2024-03-24', '09:30:00', 'Urology consultation', 'Scheduled')");

}
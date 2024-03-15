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

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Stephen', 'Owens', 'Cardiology', 'stephen.owens@atlgeneral.org', '470-658-1002')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Amber', 'Henry', 'Cardiology', 'amber.henry@atlgeneral.org', '470-658-1008')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Jill', 'Morales', 'Cardiology', 'jill.morales@atlgeneral.org', '470-658-1016')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Tony', 'Tucker', 'Family Medicine', 'tony.tucker@atlgeneral.org', '470-658-1003')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Andrew', 'Black', 'Family Medicine', 'andrew.black@atlgeneral.org', '470-658-1007')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Sheila', 'McDonald', 'Family Medicine', 'sheila.mcdonald@atlgeneral.org', '470-658-1012')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Andrew', 'Cook', 'Family Medicine', 'andrew.cook@atlgeneral.org', '470-658-1015')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Samantha', 'Wade', 'Neurology', 'samantha.wade@atlgeneral.org', '470-658-1004')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Jeffrey', 'Wilson', 'Neurology', 'jeffrey.wilson@atlgeneral.org', '470-658-1006')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Lisa', 'Brooks', 'Neurology', 'lisa.brooks@atlgeneral.org', '470-658-1011')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Ryan', 'Ellis', 'Orthopedics', 'ryan.ellis@atlgeneral.org', '470-658-1014')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Lori', 'Jenkins', 'Orthopedics', 'lori.jenkins@atlgeneral.org', '470-658-1019')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Jacob', 'Martinez', 'Radiology', 'jacob.martinez@atlgeneral.org', '470-658-1001')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Laura', 'Robbins', 'Radiology', 'laura.robbins@atlgeneral.org', '470-658-1013')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Jason', 'Gibson', 'Urology', 'jason.gibson@atlgeneral.org', '470-658-1005')");

        execute_query("INSERT INTO doctors (FirstName, LastName, Specialization, Email, Phone) VALUES ('Jennifer', 'Wells', 'Urology', 'jennifer.wells@atlgeneral.org', '470-658-1018')");

}
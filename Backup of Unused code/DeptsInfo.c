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

        execute_query("INSERT INTO Department (DeptName) VALUES ('Cardiology')");

        execute_query("INSERT INTO Department (DeptName) VALUES ('Family Medicine')");
        
        execute_query("INSERT INTO Department (DeptName) VALUES ('Neurology')");
        
        execute_query("INSERT INTO Department (DeptName) VALUES ('Orthopedics')");
        
        execute_query("INSERT INTO Department (DeptName) VALUES ('Radiology')");
        
        execute_query("INSERT INTO Department (DeptName) VALUES ('Urology')");
}
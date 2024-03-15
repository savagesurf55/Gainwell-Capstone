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

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Lisa', 'Myers', 'Wife', '402-305-9630', 'lisa.myers@aol.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('John', 'Miller', 'Son', '668-813-9631', 'footballplayer@yahoo.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Tina', 'Ashland', 'Aunt', '710-262-7892', 'seashells09@icloud.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Adam', 'Alexander', 'Husband', '691-701-1325', 'alexanderdad5@charter.net')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Ellie', 'Gordon', 'Mother', '805-859-8452', 'tarheelsfan1@att.net')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Trevor', 'Tapia', 'Grandson', '544-232-2358', 'tapia.trevor@google.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Mary', 'Riley', 'Wife', '852-821-8235', 'mary.riley1985@aol.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Jonathan', 'Adkins', 'Father', '961-478-0238', 'panthers18@yahoo.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Veronica', 'Ramos', 'Cousin', '458-741-3964', 'jamison.v@att.net')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Blanche', 'King', 'Wife', '735-982-3085', 'b.king1945@icloud.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Alan', 'Miller', 'Husband', '588-956-3566', 'alanmiller20@aol.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Whitney', 'Brooks', 'Sister', '649-458-5692', 'atlantawhitney@yahoo.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Jessica', 'Pham', 'Mother', '396-345-8432', 'phammom45@google.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Larry', 'Winters', 'Father', '436-785-1325', 'mrlarrywinters@att.net')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Brenda', 'Henry', 'Mother', '203-421-9825', 'mrshenry@charter.net')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Tony', 'Walker', 'Husband', '785-231-8956', 'tony.walker@icloud.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Dennis', 'Hill', 'Father', '412-785-9650', 'hill.dennis@yahoo.com')");

            execute_query("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Lilly', 'Heath', 'Mother', '386-789-5624', 'toyotalilly65@att.net')");

            execute_query ("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Carl', 'Ingram', 'Brother', '803-412-6932', 'falconsfan1980@google.com')");

            execute_query ("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Hazel', 'Shelton', 'Wife', '336-741-6594', 'hazelskitchen@yahoo.com')");

            execute_query ("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Wanda', 'Johnson', 'Sister', '212-555-8975', 'johnson.wanda@google.com')");

            execute_query ("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Mary', 'Smith', 'Wife', '310-302-7531', 'marymack@aol.com')");

            execute_query ("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Janet', 'Brown', 'Aunt', '645-985-9526', 'janetbrown302@icloud.com')");

            execute_query ("INSERT INTO emergency_contacts (FirstName, LastName, Relationship, Phone, Email) VALUES ('Tanya', 'Wilson', 'Wife', '426-896-4529', 'wilsonmtanya@google.com')");

    
}
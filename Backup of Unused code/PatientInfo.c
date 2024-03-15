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

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Jonathan', 'Myers', '1974-09-23', 'Male', '106 White Way, Marietta, GA 30064', '402-101-5121', 'myers.jonathan@aol.com', '402-632-1569')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Lisa', 'Miller', '1943-05-10', 'Female', '8615 Dana Alley , Roswell, GA 30076', '668-728-2652', 'livefortheday@yahoo.com', '668-728-3695')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Michael', 'Garrison', '1984-07-30', 'Female', '1871 Yolanda Union St, Decatur, GA 30032', '710-262-3755', 'mgarrison@charter.net', '710-365-4689')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Alyssa', 'Alexander', '1981-11-01', 'Female', '6060 Kirk Trail, Duluth, GA 30096', '691-701-5665', 'mamaalyssa@gmail.com', '691-701-3218')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Robert', 'Gordon', '2004-07-19', 'Male', '123 Main St, Marietta, GA 30068 ', '805-859-5412', 'mrgordon@gmail.com', '805-859-7963')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Emily', 'Tapia', '1937-07-23', 'Female', '70400 McCarthy Plains St, Smyrna, GA 30080', '544-232-3824', 'etapia@aol.com', '544-232-8465')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Peter', 'Riley', '1950-02-04', 'Female', '2188 Brown Mountain Dr, Johns Creek, GA 30022', '852-568-0921', 'motorcycle@icloud.com', '852-465-9832')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact)  VALUES ('Jacqueline', 'Adkins', '2005-10-02', 'Female', '96942 Lyons Way, Kennesaw, GA 30144', '961-154-0131', 'adkinsj@mail.com', '961-896-4523')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Charles', 'Ramos', '1986-10-18', 'Male', '7268 Diane Pines Ave, Marietta, GA 30067', '458-858-1627', 'basketball1268@att.net', '458-858-4568')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Jeffrey', 'King', '1969-03-04', 'Male', '6471 Richard Crossroad, Alpharetta, GA 30004', '735-878-2742', 'jeffking1969@gmail.com', '735-878-8912')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Steven', 'Miller', '1987-02-20', 'Male', '181 Laurie Summit, Sandy Springs, GA 30328', '588-725-2585', 'miller.steven@yahoo.com', '588-895-8963')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Helen', 'Brooks', '1948-03-16', 'Female', '654 Cedar St, Roswell, GA 30075', '649-399-7896', 'floridasunshine@aol.com', '649-399-9862')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Marc', 'Pham', '2011-12-19', 'Male', '23207 Gem Mine Trail, Johns Creek, GA 30024', '396-507-8652', 'pham2011@gmail.com', '396-507-8971')");

            execute_query("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Tiffany', 'Winters', '1990-06-08', 'Female', '309 Munoz Plaza, Kennesaw, GA 30144', '436-682-0229', 'mswinters1990@icloud.com', '436-962-9876')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Hunter', 'Henry', '2008-12-06', 'Male', '250 Ramirez Station Dr, Alpharetta, GA 30009', '203-217-0303', 'henryhunts1305@att.net', '203-978-3452')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Courtney', 'Walker', '1944-03-11', 'Female', '68154 Tanya Overpass, Marietta, GA 30062', '785-193-7735', 'cwalkernycity@mail.com', '785-193-9845')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Gina', 'Hill', '2011-04-09', 'Female', '5458 Mark Crossroad, Atlanta, GA 30301', '412-708-9942', 'tennisstar@charter.net', '412-708-5612')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Olivia', 'Heath', '1989-11-22', 'Female', '220 David Park, Decatur, GA 30034', '386-116-5485', 'jazzfan1864@aol.com', '386-116-9863')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Kelly', 'Ingram', '1966-03-16', 'Male', '703 Hudson Crescent, Duluth, 30097', '803-547-0598', 'goterrapins66@icloud.com', '803-547-9331')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Karl', 'Shelton', '1963-09-21', 'Male', '414 Juan Locks Dr, Atlanta, GA 30306', '336-889-4011', 'shelton.karl@att.net', '336-957-6384')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Alice', 'Johnson', '1985-02-20', 'Female', '456 Elm St, Lawrenceville, GA 30045', '212-555-1653', 'aliceinny1985@aol.com', '212-569-9833')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Bob', 'Smith', '1990-09-25', 'Male', '789 Oak St, Smyrna, GA 30082', '310-302-1485', 'mrbobsmith@yahoo.com', '310-823-8971')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('Emily', 'Brown', '1973-04-21', 'Female', '321 Maple Ave, Roswell, GA 30077', '645-985-4362', 'longhorns4ever@gmail.com', '645-985-3672')");

            execute_query ("INSERT INTO Patient (FirstName, LastName, DateOfBirth, Gender, Address, Phone, Email, EmergencyContact) VALUES ('David', 'Wilson', '1964-03-10', 'Male', '987 Pine St, Sandy Springs, GA 30342', '426-896-4356', 'washingtonwilson@charter.net', '426-896-9812')");       
}
        
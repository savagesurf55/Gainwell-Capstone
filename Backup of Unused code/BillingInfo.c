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

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Unpaid', '$70.30', '0000-00-00', 'Unpaid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Unpaid', '$99.83', '0000-00-00', 'Unpaid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Unpaid', '$77.22', '0000-00-00', 'Unpaid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$85.29', '2024-01-04', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Unpaid', '$150.00', '0000-00-00', 'Unpaid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$35.00', '2024-02-06', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$250.00', '2023-12-27', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Unpaid', '$150.00', '0000-00-00', 'Unpaid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$80.86', '2024-01-26', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$300.06', '2023-08-27', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES  ('Paid', '$125.86', '2023-07-06', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$169.45', '2023-05-13', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$116.06', '2023-06-10', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$200.00', '2023-12-24', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$80.69', '2023-03-13', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$96.85', '2023-12-18', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Unpaid', '$120.98', '0000-00-00', 'Unpaid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$85.36', '2023-09-02', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$79.62', '2023-11-15', 'Paid')");

        execute_query("INSERT INTO Invoices (InvoiceID, PatientID, DateIssued, Amount, Status, PaymentDate) VALUES ('Paid', '$198.62', '2023-08-11', 'Paid')");

}
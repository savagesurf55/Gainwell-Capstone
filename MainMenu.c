#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    do {
        // Display the main menu options
        printf("Main Menu:\n");
        printf("1. Patients\n");
        printf("2. Doctors\n");
        printf("3. Appointments\n");
        printf("4. Test Results\n");
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

        // Use a switch statement to handle user's choice
        switch (choice) {
            case 1:
                // Compile and execute the PatientDML program
                system("gcc -o PatientDML PatientDML.c -L/usr/lib/mysql -lmysqlclient");
                system("./PatientDML");
                break;
            case 2:
                // Compile and execute the DoctorDML program
                system("gcc -o DoctorDML DoctorDML.c -L/usr/lib/mysql -lmysqlclient");
                system("./DoctorDML");
                break;
            case 3:
                // Compile and execute the AppointmentsDML program
                system("gcc -o AppointmentsDML AppointmentsDML.c -L/usr/lib/mysql -lmysqlclient");
                system("./AppointmentsDML");
                break;
            case 4:
                // Compile and execute the TestResultDML program
                system("gcc -o TestResultsDML TestResultsDML.c -L/usr/lib/mysql -lmysqlclient");
                system("./TestResultsDML");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

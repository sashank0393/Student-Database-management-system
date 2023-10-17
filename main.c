#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Function to add a new student to the database
void addStudent(struct Student *database, int *size) {
    printf("Enter Roll Number: ");
    scanf("%d", &database[*size].rollNumber);
    printf("Enter Name: ");
    scanf("%s", database[*size].name);
    printf("Enter Marks: ");
    scanf("%f", &database[*size].marks);

    (*size)++; // Increment the size of the database
}

// Function to display all students in the database
void displayStudents(const struct Student *database, int size) {
    printf("\nStudent Database:\n");
    printf("Roll Number\tName\t\tMarks\n");
    for (int i = 0; i < size; ++i) {
        printf("%d\t\t%s\t\t%.2f\n", database[i].rollNumber, database[i].name, database[i].marks);
    }
}

// Function to search for a student by roll number
void searchByRollNumber(const struct Student *database, int size) {
    int rollNumber;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < size; ++i) {
        if (database[i].rollNumber == rollNumber) {
            printf("\nStudent Found:\n");
            printf("Roll Number\tName\t\tMarks\n");
            printf("%d\t\t%s\t\t%.2f\n", database[i].rollNumber, database[i].name, database[i].marks);
            return;
        }
    }

    printf("\nStudent not found with Roll Number %d\n", rollNumber);
}

int main() {
    struct Student studentDatabase[100]; // Assuming a maximum of 100 students
    int databaseSize = 0; // Current number of students in the database
    int choice;

    do {
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(studentDatabase, &databaseSize);
                break;
            case 2:
                displayStudents(studentDatabase, databaseSize);
                break;
            case 3:
                searchByRollNumber(studentDatabase, databaseSize);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

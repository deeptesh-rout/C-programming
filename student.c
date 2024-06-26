/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int rollNumber;
    int age;
    double grade;
} Student;

Student students[100];
int studentCount = 0;

void addStudent() {
    Student student;
    
    printf("Enter student name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);
    printf("Enter age: ");
    scanf("%d", &student.age);
    printf("Enter grade: ");
    scanf("%lf", &student.grade);

    students[studentCount++] = student;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }
    printf("\nStudents:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s, Roll Number: %d, Age: %d, Grade: %.2f\n",
               students[i].name, students[i].rollNumber, students[i].age, students[i].grade);
    }
}

void updateStudent() {
    int rollNumber, found = 0;
    printf("Enter roll number of student to update: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new grade: ");
            scanf("%lf", &students[i].grade);

            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

void deleteStudent() {
    int rollNumber, found = 0;
    printf("Enter roll number of student to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}

void calculateAverageGrade() {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }
    double totalGrade = 0;
    for (int i = 0; i < studentCount; i++) {
        totalGrade += students[i].grade;
    }
    double averageGrade = totalGrade / studentCount;
    printf("Average Grade: %.2f\n", averageGrade);
}

int main() {
    int isRunning = 1;

    while (isRunning) {
        int choice;
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Calculate Average Grade\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                calculateAverageGrade();
                break;
            case 6:
                isRunning = 0;
                printf("Thank you ..exiting\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
*/
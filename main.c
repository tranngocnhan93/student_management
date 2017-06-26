#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_STUDENT 300
#define ID_LEN 9
#define NAME_LEN 20
#define DOB_LEN 11
#define EMAIL_LEN 20
#define PHONE_LEN 15
#define ADDRESS_LEN 30

typedef struct student{
    char id[ID_LEN];
    char name[NAME_LEN];
    char dob[DOB_LEN];
    char email[EMAIL_LEN];
    char phone[PHONE_LEN];
    char address[ADDRESS_LEN];
} student_t;

void welcome(void){
    printf("*****************************************************\n");
    printf("Welcome to FPT Student Management!\nEnter what to do:\n");
    printf("1: Add new student\n");
    printf("2: View all student\n");
    printf("3: Search student\n");
    printf("4: Delete student\n");
    printf("5: Update student\n");
    printf("6: Exit\n");
}
student_t add_student(void){
    student_t std;
    printf("Enter student ID\n");
    fgets(std.id, ID_LEN, stdin);

    printf("Enter student name\n");
    fgets(std.name, NAME_LEN, stdin);

    printf("Enter student date of birth\n");
    fgets(std.dob, DOB_LEN, stdin);

    printf("Enter student email\n");
    fgets(std.email, EMAIL_LEN, stdin);

    printf("Enter student phone\n");
    fgets(std.phone, PHONE_LEN, stdin);

    printf("Enter student address\n");
    fgets(std.address, ADDRESS_LEN, stdin);
    return std;
}
void view_student(student_t* std_array, uint64_t current_counter){
    uint64_t i;
    for(i = 0; i < current_counter; i++){
        printf("Student ID: %s\n", std_array[i].id);
        printf("    Name: %s\n", std_array[i].name);
        printf("    DoB: %s\n", std_array[i].dob);
        printf("    Email: %s\n", std_array[i].email);
        printf("    Phone: %s\n", std_array[i].phone);
        printf("    Address: %s\n", std_array[i].address);
    }
}
uint64_t search_student(student_t* student_array, uint64_t current_counter){
    uint16_t i;
    char id[ID_LEN];
    printf("Enter ID.\n");
    fgets(id, ID_LEN, stdin);
    for(i = 0; i < current_counter; i++){
        if(student_array[i].id && id){
            return i;
        }
    }
    if (i == current_counter)
        printf("ID not found.\n");
}
void print_student(student_t* student_array, uint64_t i){
    printf("Information for student ID %s\n", student_array[i].id);
    printf("Name: %s\n", student_array[i].name);
    printf("DoB: %s\n", student_array[i].dob);
    printf("Email: %s\n", student_array[i].email);
    printf("Phone: %s\n", student_array[i].phone);
    printf("Address: %s\n", student_array[i].address);
}
void delete_student(student_t* student_array, uint64_t current_counter){
    uint64_t i = search_student(student_array, current_counter);
    for(i; i < current_counter; i++){
        strcpy(student_array[i].id, student_array[i+1].id);
        strcpy(student_array[i].name, student_array[i+1].name);
        strcpy(student_array[i].email, student_array[i+1].id);
        strcpy(student_array[i].dob, student_array[i+1].dob);
        strcpy(student_array[i].phone, student_array[i+1].phone);
        strcpy(student_array[i].address, student_array[i+1].address);
    }
    printf("Delete successful\n");
}
void update_student(student_t* student_array, uint64_t current_counter){
    uint64_t i = search_student(student_array, current_counter);
    student_t temp = add_student();
    strcpy(student_array[i].id, temp.id);
    strcpy(student_array[i].name, temp.name);
    strcpy(student_array[i].dob, temp.dob);
    strcpy(student_array[i].email, temp.email);
    strcpy(student_array[i].phone, temp.phone);
    strcpy(student_array[i].address, temp.address);
    printf("Update successful\n");
}
int main()
{
    static uint64_t student_counter = 0;
    uint64_t index;
    char task[1];
    static student_t students[MAX_STUDENT];

    while(1){
        welcome();
        gets(task);     //cannot use scanf because it leaves \n in input stream
        switch(task[0]){
        case '1':
            students[student_counter] = add_student();
            student_counter++;
            break;
        case '2':
            view_student(students, student_counter);
            break;
        case '3':
            index = search_student(students, student_counter);
            print_student(students, index);
            break;
        case '4':
            delete_student(students,student_counter);
            student_counter--;
            break;
        case '5':
            update_student(students,student_counter);
            break;
        case '6':
            printf("See you!\n");
            getchar();
            return 0;
        default:
            printf("Invalid task! Enter again\n");
            break;
        }
    }
    return 0;
}

#include<stdlib.h>
#include<string.h>
#include<stdio.h>


struct Student//stucture of node
{
    int rollnumber;
    char name[100];
    char course[100];
    float marks;
    struct Student *next;
    
}* head;
void insert(int rollnumber, char* name, char* course, float marks)//insert function for inserting data
{
    
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));//memory allocation
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->course, course);
    student->marks = marks;
    student->next = NULL;
    
    if(head==NULL){
        // if head is NULL
        // set student as the new head
        head = student;
    }
    else{
        // if list is not NULL
        // insert student in beginning of head
        student->next = head;
        head = student;
    }
    
}
void search(int rollnumber)//function to search detail using rollnumber
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){ 
            printf("--------------------------------------------------------------------------------------------------");
            printf("\nRoll Number: %d\n", temp->rollnumber);
            printf("Name: %s\n", temp->name);
            printf("Course: %s\n", temp->course);
            printf("Total Marks: %0.2f\n", temp->marks);
             printf("--------------------------------------------------------------------------------------------------");
            return;
           
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is NOT found !!!\n", rollnumber);
}

void Delete(int rollnumber)//Deleting student detail using rollnumber
{
    struct Student * temp1 = head;
    struct Student * temp2 = head; 
    while(temp1!=NULL){
        
        if(temp1->rollnumber==rollnumber){
              printf("\n--------------------------------------------------------------------------------------------------");
            printf("\nRecord with roll number %d Found !!!\n", rollnumber);
            
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1); 
            }
              
            printf("Record Successfully Deleted !!!\n");
              printf("--------------------------------------------------------------------------------------------------");
            return;
            
        }
        temp2 = temp1;
        temp1 = temp1->next;
        
    }
    printf("Student with roll number %d is NOT found !!!\n", rollnumber);//if record not found
    
}
void display()
{printf("\nAll Student's Details :\n");
    struct Student * temp = head;
    while(temp!=NULL){
         printf("\n--------------------------------------------------------------------------------------------------");
        printf("\nRoll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("Course: %s\n", temp->course);
        printf("Total Marks: %0.2f\n", temp->marks);
         printf("--------------------------------------------------------------------------------------------------");
        temp = temp->next;
        
    }
}
int main()//main function
{
    head = NULL;
    int choice;
    char name[100];
    char course[100];
    int rollnumber;
    float marks;
  printf("                                                  STUDENT MANAGEMENT SYSTEM");
    do//do loop for entering choice 
    {   printf("\n        MENU\n");
        printf("1 Insert student details\n2 Search for student details\n3 Delete student details\n4 Display all student details\n5 Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)//switch for chosing the options
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter course : ");
                scanf("%s", course);
                printf("Enter total marks: ");
                scanf("%f", &marks);
                insert(rollnumber, name, course, marks);
                break;
            case 2:
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                break;
            case 4:
                display();
                break;
            case 5:  system("clear");
            printf("--------------------------------------------------------------------------------------------------");
            printf("\nProgram Session Terminated Successfully\n");
            printf("\nProgram made by : \n>> Jayesh(094)\n>> Mukund(086)\n>> Pranav(079)");
             printf("--------------------------------------------------------------------------------------------------");
            exit(0);
            
            break;
            default:printf("\nEnter a valid choice.\n");
            break;
        }
        
    } while (choice != 0);
}


// Stack: A data structure that follows the LIFO principle (Last In, First Out)
// The last element added is the first one to be removed.
// Stacks are used in:
// - Function calls (Call Stack)
// - Undo operations in applications
// - Checking matching parentheses in expressions
#include <stdio.h>
#include <stdlib.h>
typedef struct person {
char name[7];
int age;
struct person *next;
}person;
// push: Function to add a new element to the Stack
// The operation is performed at the beginning of the Linked List
// The new element becomes the Top of the stack
// Steps:
// 1- Allocate memory for a new node
// 2- Read element data (name and age) from the user
// 3- Link the new node to the current list
// 4- Update the head pointer to point to the new node
void puch (person **head) {
person *temp=NULL,*temp_I=NULL;
if (*head == NULL) {
printf("Stack is empty!\n");
}
else {
temp=(person*)(malloc(sizeof(person)));
printf("Enter name n°? : ");
scanf("%s",&temp->name);
printf("Ente age n°?   : "); 
scanf("%d",&temp->age);
temp->next=*head;
*head=temp;
}
}
// pop: Function to remove the top element from the Stack
// The operation is performed at the beginning of the Linked List
// Steps:
// 1- Check if the stack is not empty
// 2- Store a pointer to the current node (Top)
// 3- Update head to point to the next element
// 4- Free the memory of the removed node
void pop (person **head) {
person *temp=NULL,*temp_I=NULL;
if (*head == NULL) {
printf("Stack is empty!\n");
}
else {
temp=*head;
temp_I=temp->next;
*head=temp_I;
free(temp);
}
}
// disp: Function to display all elements in the Stack
// Traverses the list from beginning to end
// Prints the name and age of each element with its number
// Helps to see the stack contents after push and pop operations
void disp (person *head) {
person *temp=NULL;
temp=head;
int i=0;
while(temp!=NULL){
printf("Enter name n°%d : %s\n",i+1,temp->name);
printf("Enter age n°%d  : %d\n",i+1,temp->age); 
i++;
temp=temp->next;
}
}
// This program implements a Stack using a Linked List
// The user can enter elements (name + age)
// New elements can be added using push
// The top element can be removed using pop
// All elements can be displayed using disp
// Demonstrates how to manage data dynamically using a stack
int main () {
person *head=NULL,*temp=NULL;
int i,n;
printf("Enter the number of nodes : ");
scanf("%d",&n);
head=(person*)(malloc(sizeof(person)));
temp=head;
printf("----------------------------\n");
for(i=0;i<n;i++){
printf("Enter name n°%d : ",i+1);
scanf("%s",&temp->name);
printf("Enter age n°%d  : ",i+1); 
scanf("%d",&temp->age);
if(i+1<n) {
temp->next=(person*)(malloc(sizeof(person)));
temp=temp->next;
}
else {
temp->next=NULL;
}
}
pop(&head);puch(&head);
printf("----------------------------\n");
disp(head);
return 0;
}
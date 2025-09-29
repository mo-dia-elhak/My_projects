// Queue: A data structure that follows the FIFO principle (First In, First Out)
// The first element added is the first one to be removed.
// Queues are used in:
// - Task scheduling
// - Print spooling
// - Handling requests in servers
#include <stdio.h>
#include <stdlib.h>
typedef struct person {
char name[7];
int age;
struct person *next;
}person;
// dequeue: Function to remove the front element from the Queue
// The operation is performed at the beginning (front) of the Linked List
// Steps:
// 1- Check if the queue is not empty
// 2- Store a pointer to the current front node
// 3- Update front to point to the next node
// 4- If the queue becomes empty, update rear to NULL
// 5- Free the memory of the removed node
void dequeue (person **head) {
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
// enqueue: Function to add a new element to the Queue
// The operation is performed at the end (rear) of the Linked List
// Steps:
// 1- Allocate memory for a new node
// 2- Read element data (name and age) from the user
// 3- Set the next pointer of the new node to NULL
// 4- Link the new node at the end of the list
// 5- Update the rear pointer to point to the new node
void enquene (person *head) {
person *temp=NULL;
temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=(person*)(malloc(sizeof(person)));
printf("Enter name : ");
scanf("%s",temp->next->name);
printf("Enter age  : ");
scanf("%d",&temp->next->age);
temp->next->next=NULL;
}
// disp: Function to display all elements in the Queue
// Traverses the list from front to rear
// Prints the name and age of each element with its number
// Helps to visualize the queue contents after enqueue and dequeue operations
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
// This program implements a Queue using a Linked List
// The user can enter elements (name + age)
// New elements can be added to the rear using enqueue
// The front element can be removed using dequeue
// All elements can be displayed using disp
// Demonstrates how to manage data dynamically using a queue
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
dequeue(&head);enquene(head);
printf("----------------------------\n");
disp(head);
return 0;
}
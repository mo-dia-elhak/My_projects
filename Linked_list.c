#include <stdio.h>
#include <stdlib.h>
typedef struct person {
char name[10];
int age;
struct person *next;
}person;
void disp(person *head) {
person *temp=NULL;
int i=0;
temp=head;
while(temp!=NULL){
printf(" Name %d is        : %s\n",i+1,temp->name);
printf("Person %d's age is : %d\n",i+1,temp->age);
temp=temp->next;
i++;
}
}
void addf(person **head) {
person *temp_I=NULL;
temp_I=(person*)(malloc(sizeof(person)));
printf("Enter name : ");
scanf("%s",temp_I->name);
printf("Enter age : ");
scanf("%d",&temp_I->age);
temp_I->next=*head;
*head=temp_I;
}
person *Search(person *head) {
person *temp=head,*temp_I=NULL;
int a,i=0;
printf("Enter the item you want to search for:");
scanf("%d",&a); 
do{
i++;
if(a==i){
temp_I=temp;
}
temp=temp->next;
}while(temp!=NULL);
return temp_I;
} 
void addm(person *head) {
person *temp=NULL,*temp_I=NULL,*temp_II=NULL;
temp_I=Search(head);
temp_II=(person*)(malloc(sizeof(person)));
printf("Enter name : ");
scanf("%s",temp_II->name);
printf("Enter age : ");
scanf("%d",&temp_II->age);
temp_II->next=temp_I->next;
temp_I->next=temp_II;
}
void adde(person *head) {
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
void delf(person **head) {
person *temp=NULL,*temp_II=NULL;
temp=*head;
temp_II=temp->next;
*head=temp_II;
free(temp);
}
void delm(person *head) {
person *temp=head,*temp_I=NULL;
temp_I=Search(head);
while(temp->next!=NULL) {
if(temp->next==temp_I){
temp->next=temp_I->next;
free(temp_I);
}
temp=temp->next;
}
}
void dele(person *head) {
person *temp=head;
while(temp->next!=NULL){
temp=temp->next;
if(temp->next->next== NULL) {
free(temp->next);
temp->next=NULL;
}
}
}
int main() {
person *head = (person*)(malloc(sizeof(person)));
person *temp = head;
int n,i;char c;
printf("enter number : ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter name %d : ",i+1);
scanf("%s",temp->name);
printf("Enter age %d  : ",i+1);
scanf("%d",&temp->age);
if(i==n-1){
temp->next=NULL;
}else{
temp->next=(person*)(malloc(sizeof(person)));
temp=temp->next;
}
}
printf("Do you want to add (y/n):"); 
scanf("%s",&c);
if(c=='y') {
printf(" Choose where to add\n");
printf(" 1 : first, 2: Middle, 3: End\n");
printf("enter number :"); 
scanf("%d",&n);
switch(n) {
case 1 : addf(&head);break;
case 2 : addm(head);break;
case 3 : adde(head);break;
default : printf("Error");break; 
}
}
printf("Do you want to delete (y/n):"); 
scanf("%s",&c);
if(c=='y') {
printf("Choose where to delete\n"); 
printf(" 1 : first, 2: Middle, 3: End\n");
printf("enter number : ");
scanf("%d",&n);
switch(n) {
case 1 : delf(&head);break;
case 2 : delm(head);break;
case 3 : dele(head);break;
default : printf("Error");break; 
}
}
disp(head);
return 0;
}
/*Q. Consider a student database of SEIT class (at least 15 records). Database 
contains different fields of every student like Roll No, Name and SGPA.(array of 
structure) 
a) Design a roll call list, arrange list of students according to roll numbers in ascending order 
(Use Bubble Sort)*/

#include <iostream>
#include <string.h>
int const size=5;
using namespace std;
struct student
{
 int rollno;
 char name[20];
 float SGPA;
};
void accept(struct student list[size]); 
void display(struct student list[80]); 
void bubblesort(struct student list[size]); 
int main() 
{
 struct student data[20];
 accept(data);
 cout<<"\n Bubble Sort";
 bubblesort(data);
 display(data);
}
void accept(struct student list[size]) 
{
 int i;
 for (i=0;i<size;i++)
 {
 cout<<"Enter roll no.,name and SGPA:";
 cin>>list[i].rollno>>list[i].name>>list[i].SGPA;
 }
}
void display(struct student list[80])
{
 int i;
 cout<<"\n roll no.\tname\tSGPA\n";
 for(i=0;i<size;i++)
 {
 cout<<"\n"<<list[i].rollno<<"\t"<<list[i].name<<"\t"<<list[i].SGPA;
 }
}
void bubblesort(struct student list[size])
{
 int i,j;
 struct student temp;
 for(i=0;i<size-1;i++)
 {
 for(j=0;j<(size-1-i);j++)
 {
 if(list[j].rollno>list[j+1].rollno)
 {
 temp=list[j];
 list[j]=list[j+1];
 list[j+1]=temp;
 }
 }
 }
}


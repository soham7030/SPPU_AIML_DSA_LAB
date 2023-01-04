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
void search(struct student list[size]); 
int main() 
{
 struct student data[20];
 accept(data);
 cout<<"\n Linear Search";
 search(data);
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
void search(struct student list[size])
{
 float SGPA;
 int i;
 cout<<"\n Enter SGPA:";
 cin>>SGPA;
 
 cout<<"\n Roll No.\t Name \t SGPA\n";
 for(i=0;i<size;i++)
 {
 if(SGPA==list[i].SGPA)
 {
 cout<<"\n"<<list[i].rollno<<"\t"<<list[i].name<<"\t"<<list[i].SGPA;
 }
 }
}
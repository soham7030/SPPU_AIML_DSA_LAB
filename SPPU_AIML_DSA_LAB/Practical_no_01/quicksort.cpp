#include<iostream> 
using namespace std;
struct student 
{ 
int roll; 
string name; 
float sgpa; 
}; 
void show1(student *a[], int n)
{ 
for (int i=0;i<n;i++) 
{ 
 cout<<a[i]->roll<<" "; 
 cout<<a[i]->name<<" "; 
 cout<<a[i]->sgpa<<"\n"; 
} 
} 
void show2(student *a[], int n) 
{ 
for (int i=n-1;i>n-11;i--) 
{ 
 cout<<a[i]->roll<<" "; 
 cout<<a[i]->name<<" "; 
 cout<<a[i]->sgpa<<"\n"; 
} 
} 
int partition (student *a[], int l, int u) 
{ 
student *t; 
float p=a[l]->sgpa; 
int start=l,end=u; 
{ 
 while(a[start]->sgpa <= p && start<u) 
 { 
 start++; 
 } 
 while (a[end]->sgpa>p) 
 { 
 end--; 
 } 
 if(start < end) 
 { 
 swap(a[start],a[end]); 
 } 
 else 
 { 
 t=a[end]; 
 a[end]=a[l]; 
 a[l]=t; 
 return end--; 
 } 
} 
return 0; 
} 
void quickSort(student *a[], int l, int u) 
{ 
if (l< u) 
{ 
 int loc = partition(a, l, u); 
 quickSort(a, l, loc - 1); 
 quickSort(a, loc + 1, u); 
} 
} 
int main()
{ 
int i=0,n,ch; 
float m; 
student *s[5]; 
loop1: 
cout<<"1. INSERT RECORDS:"; 
cout<<"\n2. FIRST TEN TOPPERS OF THE CLASS: \n"; 
cout<<"ENTER YOUR CHOICE:"; 
cin>>n; 
if(n==1) 
{ 
 cout<<"ENTER DETAILS: \n"; 
 do 
 { 
 cout<<"STUDENT "<<i+1<<" RECORD:\n"; 
 s[i]=new student; 
 cout<<"Roll no :"; 
 cin>>s[i]->roll; 
 cout<<"Name: "; 
 cin>>s[i]->name; 
 cout<<"SGPA: "; 
 cin>>s[i]->sgpa; 
 cout<<"DO YOU WANT TO INPUT MORE RECORDS (enter 1 if yes) \n"; 
 cin>>ch; 
 i++; 
 } while(ch==1); 
} 
 cout<<"FIRST TEN TOPPERS"<<"\n"<<"\n"; 
 quickSort(s,0,i-1); 
 show2(s,i); 
 return 0;
}
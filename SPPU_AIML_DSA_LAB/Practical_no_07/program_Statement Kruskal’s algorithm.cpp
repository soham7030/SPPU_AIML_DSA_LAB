
/* Q. Represent a graph of your college campus using adjacency list /adjacency 
matrix. Nodes should represent the various departments/institutes and links 
should represent the distance between them. Find minimum spanning tree.

a) Using Kruskal’s algorithm

*/

#include<iostream> 
#define MAX 30 
struct edge
{ 
int u,v,w; 
}; 
using namespace std;
class edgelist
{ 
edge data [MAX]; 
int n;
public:
friend class graph; 
edgelist()
{
n=0;
}
void sort(); 
void print();
}; 
void edgelist::sort() 
{
int i,j; edge temp;
for(i=1;i<n;i++) 
for(j=0;j<n-i;j++) 
if(data[j].w>data[j+1].w) 
{ temp=data[j];
data[j]= data[j+1]; 
data[j+1]=temp;
}
}
void edgelist::print()
{
int i; int cost=0; for(i=0;i<n;i++)
{ 
cout<<"\n"<<data[i].u<<" "<<data[i].v<<" "<<data[i].w;
cost=cost+data[i].w;
} 
cout<<"\ncost of the spanning tree = "<<cost; 
}
//edgelist elist; 
class graph
{ 
int G[MAX][MAX]; 
int n;
public:
graph()
{
n = 0 ;
}
void readgraph();
void printgraph(); 
void kruskal(edgelist&spanlist);
};
void graph:: readgraph()
{ 
int i,j;
cout<<"\nEnter No. of department: "; 
cin>>n;
cout <<"\nEnter the adjacency matrix : ";
for(i=0;i<n;i++)
for(j=0;j<n;j++) 
cin>>G[i][j];
}
void graph:: printgraph()
{
int i,j;
for(i=0;i<n;i++)
{
 cout <<"\n";
for(j=0;j<n;j++)
cout<<" "<<G[i][j];
}
}
int find(int belongs [], int vertexno); // component no. of vertexno 
void union1 (int belongs[], int c1, int c2, int n); // combining two components
int main()
{
edgelist spanlist;
graph gl;
gl.readgraph();
gl.kruskal(spanlist);
spanlist.print();
//getch();
}
void graph::kruskal(edgelist&spanlist)
{
int belongs [MAX],i,j,cnol,cno2; 
edgelist elist;
for(i=1;i<n;i++) 
for(j=0;j<i;j++)
{
if(G[i][j]!=0) 
{
elist.data[elist.n].u=i; 
elist.data[elist.n].v=j; 
elist.data[elist.n].w=G[i][j];
elist.n++;
}
}
elist.sort();
for(i=0;i<n;i++)
belongs[i]=i;
for(i=0;i<elist.n;i++)
{
cnol=find(belongs,elist.data[i].u);
cno2=find(belongs,elist.data[i].v);
if(cnol!=cno2)
{
spanlist.data[spanlist.n]=elist.data[i];
spanlist.n=spanlist.n+1;
union1(belongs,cnol,cno2,n);
}
}
}
int find(int belongs[],int vertexno)
{
return(belongs [vertexno]);
}
void union1(int belongs[], int cl,int c2,int n)
{
int i;
for(i=0;i<n;i++)
if(belongs[i]==c2) 
belongs[i]=cl;
}
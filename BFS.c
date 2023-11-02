#include<stdio.h> #include<conio.h> #define TRUE 1
#define FALSE 0
int g[20][20],visit[20],q[20],front,rear,n; void main()
{
int v1,v2,ans1; char ans='Y'; void create(); void bfs(); create();
{
printf("\nThe adjacency matrix for graph is:\n"); for(v1=0;v1<n;v1++)
{
for(v2=0;v2<n;v2++) printf("%d",g[v1][v2]);
 
printf("\n");
}
do
{
for(v1=0;v1<n;v1++) visit[v1]=FALSE;
printf("\nEnter the vertex from which you want to traverse"); scanf("%d",&v1);
if(v1>=n) printf("\nInvalid vertex"); else
{
printf("\nThe BFS of the graph is:\n"); bfs(v1);
}
printf("\nDo you want to traverse from any node?"); scanf("%d",&ans1);
}
while(ans1==1);
}
getch();
}
/*SUBFUNCTION TO CREATE A GRAPH*/
void create()
{
int v1,v2; char ans; clrscr();
printf("\nEnter no.of nodes:"); scanf("%d",&n); for(v1=0;v1<n;v1++) for(v2=0;v2<n;v2++) g[v1][v2]=FALSE;
printf("\nEnter the vertices starting from zero:"); do
{
printf("\nEnter the vertices v1&v2:"); scanf("%d%d",&v1,&v2); if(v1>n||v2>n)
printf("\nInvalid vertex"); else
{
g[v1][v2]=TRUE;
g[v2][v1]=TRUE;
}
printf("\nAdd move edge?[Y/N]:"); ans=getch();
}
while(ans=='Y'||ans=='y');
}
/*SUBFUNCTION TO PERFORM BREADTH FIRST TRAVERSAL*/
 
void bfs(int v1)
{
int v2; visit[v1]=TRUE; front=rear=-1; q[++rear]=v1; while(front!=rear)
{
v1=q[++front]; printf("\n%d",v1); for(v2=0;v2<n;v2++)
{
if(g[v1][v2]==TRUE&&visit[v2]==FALSE)
{
 



}
}

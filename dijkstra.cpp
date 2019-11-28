
#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int *distance, bool *visited, int n)
{
  int i, minv=-1;
  for(i=0; i<n; i++)
  {
    if(!visited[i] && (minv==-1 || distance[i]< distance[minv]))
    {
      minv=i;
    }
  }
  return minv;
}

void dijkstra(int **edges, int n)
{
int *distance=new int[n];
bool *visited=new bool[n];
int i, j;
for(i=0; i<n; i++)
{
distance[i]=INT_MAX;
visited[i]=false;
}
distance[0]=0;

for(i=0; i<n-1; i++)
{
int minvertex=findMinVertex(distance, visited, n);
visited[minvertex]=true;
 for(j=0; j<n; j++)
 {
   if( edges[minvertex][j]!=0 && !visited[j])
   {
    int d =distance[minvertex]+edges[minvertex][j];
    if(d < distance[j])
     distance[j]=d;
   }
 }
}

for(i=1; i<n; i++)
cout<<i<<"-"<<distance[i]<<endl;
}

int main()
{
int **edges, v, i, j;

cout<<"Enter the number of vertices: ";
cin>>v;

edges=new int*[v];
for(i=0; i<v; i++)
 edges[i]=new int[v];
 
cout<<"Enter the edge matrix: \n";
for(i=0; i<v; i++)
 for(j=0; j<v; j++)
  cin>>edges[i][j];
 
dijkstra(edges, v);
}

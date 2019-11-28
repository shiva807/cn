#include<iostream>
using namespace std;

struct node
{
 int dist[20];
 int from[20];
}rt[10];

int main()
{
int n, cost[20][20], i, j, k, count;
 cout<<"Enter the number of nodes: ";
 cin>>n;
 cout<<"Enter the cost matrix: ";
 for(i=0; i<n; i++)
{
 for(j=0; j<n; j++)
{
  cin>>cost[i][j];
  rt[i].dist[j]=cost[i][j];
  rt[i].from[j]=j;
}
}

do{
count=0;
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
{
for(k=0; k<n; k++)
{
if(rt[i].dist[j] >cost[i][k]+rt[k].dist[j])
{
rt[i].dist[j]=cost[i][k]+rt[k].dist[j];
rt[i].from[j]=k;
count++;
}
}
}
}
}while(count!=0);

for(i=0; i<n; i++)
{
cout<<"For router "<<i<<endl;
for(j=0; j<n; j++)
{
 cout<<"node "<<j<<" via "<<rt[i].from[j]<<" distance "<<rt[i].dist[j]<<endl;
}
}
cout<<endl;
}

/*
Enter the number of nodes: 4
Enter the cost matrix: 0 2 7 3
2 0 1 4
7 1 0 6
3 4 6 0
For router 0
node 0 via 0 distance 0
node 1 via 1 distance 2
node 2 via 1 distance 3
node 3 via 3 distance 3
For router 1
node 0 via 0 distance 2
node 1 via 1 distance 0
node 2 via 2 distance 1
node 3 via 3 distance 4
For router 2
node 0 via 1 distance 3
node 1 via 1 distance 1
node 2 via 2 distance 0
node 3 via 1 distance 5
For router 3
node 0 via 0 distance 3
node 1 via 1 distance 4
node 2 via 1 distance 5
node 3 via 3 distance 0

*/

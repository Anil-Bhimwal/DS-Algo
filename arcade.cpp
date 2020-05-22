#include<bits/stdc++.h>
using namespace std ;

bool ar[21][21];
bool visited[21][21];
int ans[21][21];
int xa[]={0,-1,0,1};
int yb[]={1,0,-1,0};
int n;

typedef struct Point{
int x,y;
}P;

typedef struct C
{
int x,y;
int dis;
} C;

bool issafe(int x,int y)
{
return (x>=0 && x<n && y>=0 && y<n && ar[x][y] && !visited[x][y]);
}

void bfs(int x,int y)
{
queue q;
C in;
in.x=x;
in.y=y;
in.dis=0;
q.push(in);
visited[x][y]=1;

while(!q.empty())
{
    C c=q.front();
    q.pop();
    int a=c.x;
    int b=c.y;
    int d=c.dis;
    ans[a]**=d;

    for(int i=0;i<4;i++)
    {

        int nx=a+xa*;
        int ny=b+yb*;
        if(issafe(nx,ny))
        {
            visited[nx][ny]=1;
            in.x=nx;
            in.y=ny;
            in.dis=d+1;
            q.push(in);
        }
 }

}
}

int main()
{

cin>>n;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cin>>ar*[j];
    }
}

int q;
cin>>q;

P rare[q];

int fans=10000;
int mx=-1;


for(int i=0;i<q;i++)
{

    int a,b;
    cin>>a>>b;

    rare*.x=a;
    rare*.y=b;
}


for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        memset(ans,10000,sizeof(ans));
        int flag=0;
        memset(visited,0,sizeof(visited));
        mx=-1;
        if(ar*[j])
        {
            bfs(i,j);
            for(int k=0;k<q;k++)
            {
                if(ans[rare[k].x][rare[k].y]==10000)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                for(int k=0;k<q;k++)
                {
                    mx=max(mx,ans[rare[k].x][rare[k].y]);
                }
            }
            fans=min(fans,mx);
        }
    }
}

cout<<fans<<endl;
}

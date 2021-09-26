#include<bits/stdc++.h>
using namespace std; 
bool visited[100][100]; 
int mini = INT_MAX; 
void dfs(int t1, int t2, int N,int i,int j,int count) 
{
    if(i<0||j<0||i>=N||j>=N)
      {
      return;
      
      }
      if(visited[i][j]==true){
          return; 
      }
    	if(i==t1-1 && j==t2-1)
       {
        mini= min(mini, count);
         memset(visited,false,sizeof(visited)); 
    //    cout<<mini<<" "; 
       return;
       }

       visited[i][j]=true;

    	dfs(t1,t2,N,i+1,j+2,count+1);
        //  visited[i][j]=false;
     	dfs(t1,t2,N,i+1,j-2,count+1);
        //    visited[i][j]=false;
     	dfs(t1,t2,N,i-1,j-2,count+1);
        // visited[i][j]=false;
     	dfs(t1,t2,N,i-1,j+2,count+1);
        //   visited[i][j]=false;
     	dfs(t1,t2,N,i+2,j-1,count+1);
    //    visited[i][j]=false;
     	dfs(t1,t2,N,i+2,j+1,count+1);
        //    visited[i][j]=false;
     	dfs(t1,t2,N,i-2,j+1,count+1);
        //    visited[i][j]=false;
     	dfs(t1,t2,N,i-2,j-1,count+1);
         
          visited[i][j]=false;
}
int main()
{
  memset(visited,false,sizeof(visited)); 
   dfs(1,1,6,4,5,0);
   cout<<mini;
}
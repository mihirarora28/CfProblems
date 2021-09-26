#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
 void solve(){
    int n; 
    cin>>n; 
    int arr[n][5]; 
    map<int,int>mapp; 
    for(int  i = 0 ; i < n; i ++ ){
        for(int j = 0 ;j < 5; j ++ ){
            cin>>arr[i][j]; 
        }
    }
    if(n == 1){
        cout<<1; 
        return; 
    }
    if(n == 2)
    {
    int ans111 = 0 ;
      for(int j = 0 ; j < 5 ; j ++ )
      if(arr[0][j]>arr[1][j])
      ans111++; 

      if(ans111>=3){
          cout<<2; 
          return; 
      }
      else{
          cout<<1; 
          return; 
      }
    }
   
    vector<int>ans; 
    for(int i = 0 ; i < 5 ; i ++ ){
        vector<pair<int,int>>v; 
        for(int j = 0 ;  j < n ; j ++ ){
        
            v.push_back({arr[j][i],j + 1}); 
        }
        sort(v.begin(),v.end()); 
      

      int c  = (v[n-3].first); 
      ans.push_back(c); 

    }

     

    
    ///
    for(int i = 0 ; i < n ; i ++ ){
        bool ans1 = true; 
        for(int j = 0 ; j < 5 ; j ++ )
        {
            if(arr[i][j] == ans[j])
            continue; 

            if(arr[i][j]  < ans[j])
            {
               mapp[i]++; 
             continue;
            }
    
        }
    }
        
  
  for(auto i : mapp){
      cout<<i.first<<" "<<i.second<<"\n"; 
  }


 }
 
 int main()
 {

     int t = 1; 
  scanf("%d",&t);
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }
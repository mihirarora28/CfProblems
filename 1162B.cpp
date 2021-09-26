#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
long long int mod = 1000000007;
void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true) 
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (ll p = 2; p <= n; p++)
        if (prime[p])
        primes.push_back(p); 
}
int dp[100][100];
ll power(ll x,  ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2)%mod) * (power(x, y / 2)%mod))%mod;
    else
        return ((((x  %mod) * ((power(x, y / 2)%mod)))%mod * (power(x, y / 2)%mod))%mod)%mod;
}
 int arr[100][100]; 
 int brr[100][100]; 
 void solve(){
     int n,m;
     cin>>n>>m; 
    
     for(int i = 0 ; i  < n ; i ++ ){
         for(int  j = 0 ; j < m ; j ++ )
         cin>>arr[i][j]; 
     }
     
      for(int i = 0 ; i  < n ; i ++ ){
         for(int  j = 0 ; j < m ; j ++ )
         cin>>brr[i][j]; 
     
      }

      for(int i = 0 ; i < n; i ++ ){
          for(int j = 0; j  < m ; j ++ ){

              if(arr[i][j] > brr[i][j])
                  swap(arr[i][j],brr[i][j]); 
              // normal;
              bool check = true; 
              for(int i1= 0 ; i1<=i; i1++ ){
                  for(int j1 = 0 ; j1+1<=j; j1++){
                      if(arr[i1][j1+1] > arr[i1][j1]){
                          ; 
                      }
                      else{
                          check = false; 
                      }
                  }
              }
              //
                 for(int j1= 0 ; j1<=j; j1++ ){
                  for(int i1 = 0 ; i1+1<=i; i1++){
                      if(arr[i1+1][j1] > arr[i1][j1]){
                          ; 
                      }
                      else{
                          check = false; 
                      }
                  }
              }
              ///
              for(int i1= 0 ; i1<=i; i1++ ){
                  for(int j1 = 0 ; j1+1<=j; j1++){
                      if(brr[i1][j1+1] > brr[i1][j1]){
                          ; 
                      }
                      else{
                          check = false; 
                      }
                  }
              }
              //
                 for(int j1= 0 ; j1<=j; j1++ ){
                  for(int i1 = 0 ; i1+1<=i; i1++){
                      if(brr[i1+1][j1] > brr[i1][j1]){
                          ; 
                      }
                      else{
                          check = false; 
                      }
                  }
              }
              ///////////////////////////////////////////
            //   if(check == false){
              
            //       bool check1 = true; 
            //   for(int i1= 0 ; i1<=i; i1++ ){
            //       for(int j1 = 0 ; j1+1<=j; j1++){
            //           if(arr[i1][j1+1] > arr[i1][j1]){
            //               ; 
            //           }
            //           else{
            //               check1 = false; 
            //           }
            //       }
            //   }
            //   //
            //      for(int j1= 0 ; j1<=j; j1++ ){
            //       for(int i1 = 0 ; i1+1<=i; i1++){
            //           if(arr[i1+1][j1] > arr[i1][j1]){
            //               ; 
            //           }
            //           else{
            //               check1 = false; 
            //           }
            //       }
            //   }
            //   ////////
            //    for(int i1= 0 ; i1<=i; i1++ ){
            //       for(int j1 = 0 ; j1+1<=j; j1++){
            //           if(brr[i1][j1+1] > brr[i1][j1]){
            //               ; 
            //           }
            //           else{
            //               check1 = false; 
            //           }
            //       }
            //   }
            //   //
            //      for(int j1= 0 ; j1<=j; j1++ ){
            //       for(int i1 = 0 ; i1+1<=i; i1++){
            //           if(brr[i1+1][j1] > brr[i1][j1]){
            //               ; 
            //           }
            //           else{
            //               check1 = false; 
            //           }
            //       }
            //   }
              if(check == false){
                  cout<<"Impossible";
                  return; 
              }
            //   }


          }
      }
      cout<<"Possible"; 
       
    

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
#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
 ll mod = 1000000007;
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
ll power(ll x,  ll y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2)%mod) * (power(x, y / 2)%mod))%mod;
    else
        return ((((x  %mod) * ((power(x, y / 2)%mod)))%mod * (power(x, y / 2)%mod))%mod)%mod;
}
bool sortbysecdesc(const pair<int,pair<int,int>> &a,
                   const pair<int,pair<int,int>> &b)
{
       return a.second<b.second;
}
 
 void solve(){
     int n,m; 
     cin>>n>>m; 
     int arr[n]; 
     int arr1[m]; 
     for(int i = 0 ; i < n ; i ++ )
     cin>>arr[i]; 
     for(int i = 0 ; i < m ; i ++ )
     cin>>arr1[i]; 
     int mat[n][m]; 
     memset(mat,-1,sizeof(mat)); 
     for(int i = 0 ; i < n; i ++ ){
         int aa = arr[i]; 
         for(int j = 0 ; j < m; j ++){
            //  if(mat[i][j] == 0){
            //      cout<<0;    
            //      return; 
            //  }
             if(mat[i][j]!=-1)
             continue; 
             if(aa == -1)
             continue; 
             mat[i][j] = aa; 
             aa--; 
         }
     }
     ///
    
       for(int i = 0 ; i < m; i ++ ){
         int aa = arr1[i]; 
         for(int j = 0 ; j < n; j ++){
             if((mat[j][i] == 0 && aa > 0) || (mat[j][i] > 0 && aa == 0)) {
                 cout<<0;
                //  cout<<i<<" "<<j<<"\n"; 
                //  cout<<"n" ;
                 return; 
             }
             if(aa == -1)
             continue; 
           
             mat[j][i] = aa; 
             aa--; 
         }
     }
     ll p = 0; 
           for(int i = 0 ; i < n; i ++ ){
         for(int j = 0 ; j < m; j++){
            //  cout<<mat[i][j]<<" "; 
          if(mat[i][j] == -1)
          p++; 
                     }
                    //  cout<<"\n"; 
                    
     }
     cout<<power(2,p);
   
 }
 int main()
 {

     int t = 1; 
    //   scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }
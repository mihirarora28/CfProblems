#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
 ll mod = 10000000000007;
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
     int n; 
     cin>>n; 
     int arr[n]; 
     int arr1[n]; 
     vector<pair<int,int>>v; 
     vector<pair<int,int>>v1; 
     for(int i = 0 ; i < n; i ++)
     {
      cin>>arr[i]; 
      v.push_back({arr[i],i});
     }
     int ans = 1e9; 
           for(int i = 0 ; i < n; i ++)
           {
      cin>>arr1[i]; 
            v1.push_back({arr1[i],i});
           }
           sort(v.begin(),v.end());
           sort(v1.begin(),v1.end());
           int mined[n]; 
           int mini = 1e9; 
           for(int i = n-1 ; i>=0;i--){
               mini = min(mini,v1[i].second); 
               mined[i] = mini; 
           }
           for(int  i = 0; i  < n; i ++ ){
               int c = v[i].second + mined[i]; 
               ans = min(ans,c);
           }
      cout<<ans; 
}
 int main()
 {
     cin.tie(NULL);
     int t = 1; 
      scanf("%d",&t); 

        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }
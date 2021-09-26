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
 void solve(){
     int n;
     cin>>n; 
     int p; 
     cin>>p; 
     int k; 
     cin>>k;
      ll arr[n]; 
      for(int  i = 0 ; i < n ; i ++ )
      cin>>arr[i]; 
      vector<ll>v; 
      for(int  i = 0 ;i+1  <n ; i ++ ){
          v.push_back(arr[i+1]-arr[i]); 
      }
      sort(v.begin(),v.end(),greater<int>()); 
      int ans = arr[n-1] - arr[0] + 1; 
      for(int i = 0 ; i <k-1; i ++ ){
          ans-=v[i] - 1; 
      }
      cout<<ans ;

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
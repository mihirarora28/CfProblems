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
ll n,m; 
cin>>n>>m; 
ll arr[n];
ll fr[m];  
for(int i = 0 ; i < n ; i ++ )
cin>>arr[i]; 
for(int i = 0 ; i < m ; i ++ )
cin>>fr[i]; 
sort(arr,arr+n); 
sort(fr,fr+m); 
 ll dec = n - 1; 
 ll inc = 0; 
 ll ff = 0 ;
 ll ans = 0 ;
 while(ff<m){
     ans+=arr[dec]; 
      if(fr[ff] == 1)
     ans+=arr[dec]; 
     dec--; 
     if(fr[ff]-2>=0)
     ans+=arr[inc]; 
     inc+=fr[ff]-1;
    
     ff++; 
    //  cout<<ans<<"\n";
 }

 cout<<ans; 
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
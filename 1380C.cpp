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
     cin>>n ;
     ll x; 
     cin>>x; 
     int arr[n] ;
     ll ans = 0 ;
     vector<ll>v; 
     for(int  i = 0; i < n ; i ++){
         cin>>arr[i]; 
         if(arr[i]>=x){
             ans++; 
         }
         else{
             v.push_back(arr[i]); 
         }
     }

     sort(v.begin(),v.end(),greater<int>()); 
     ll mini = 2e9; 
     ll ctr =0 ;
     for(auto i : v) {
         mini = min(mini,i);
         ctr++; 
         if(mini*ctr >= x){
             ans++; 
             ctr =0 ; 
             mini = 2e9; 
         }
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
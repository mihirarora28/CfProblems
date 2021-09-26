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
    ll n; 
    cin>>n; 
    ll arr[n]; 
    map<ll,ll>mapp; 
    vector<ll>v; 
    for(int i  = 0 ; i < n; i ++ )
    {
    cin>>arr[i]; 
    mapp[arr[i]]++; 
    }
    for(auto i : mapp){
        v.push_back(i.second); 
    }
    sort(v.begin(),v.end(),greater<ll>()); 
    ll prev = 1e12;
    ll sum = 0 ; 
    for(auto i : v){
        // cout<<sum<<"\n"; 
        if(prev == 0)
        break; 
        sum+=min(prev-1,i); 
        
        prev = min(prev-1,i) ; 
    }
    cout<<sum; 

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
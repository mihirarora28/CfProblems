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
     set<ll>s; 
     for(int  i = 1; i <=sqrt(n); i ++ ){
         if(n%i == 0){
             {
             ll c  = n/ i ; 
             ll ans = c + ((c*(c-1))/2)*i; 
            //   cout<<ans<<" ";
            s.insert(ans); 
         }
             {
             ll i1 = n/i; 
               ll c  = n/ i1 ; 
             ll ans = c + ((c*(c-1))/2)*i1; 
            //   cout<<ans<<' '; 
               s.insert(ans); 
         }
         }
        
         
     }
     for(auto i : s){
         cout<<i<<" ";
     }
     

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
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
   ll n,m,q; 
   cin>>m>>n>>q; 
   ll c = __gcd(m,n); 
   ll a1 = m/c; 
   ll a2 = n/c; 
   while(q--){
       ll a,b,c,d; 
       cin>>a>>b>>c>>d; 
       ll circle = 0; 
       ll circle2 = 0; 
       if(a == 1){
           circle = (b-1)/a1; 
       }
        if(a == 2){
           circle = (b-1)/a2; 
       }
         if(c == 1){
           circle2 = (d-1)/a1; 
       }
        if(c == 2){
           circle2 = (d-1)/a2; 
       }
       string c1 = (circle == circle2) ? "YES":"NO"; 
       cout<<c1<<"\n"; 
   }
 }
 int main()
 {

     int t = 1; 
    //  scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }
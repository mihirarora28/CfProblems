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
bool sortbysecdesc(const pair<int,pair<int,int>> &a,
                   const pair<int,pair<int,int>> &b)
{
       return a.second<b.second;
}
 
 void solve(){
     ll a; 
     cin>>a; 
     ll c = sqrt(a); 
     if(a == 1){
         cout<<1<<" "<<1; 
         return; 
     }
     for(int  i = c ; i>=1; i -- ){

         if(a%i == 0)
         {
         ll c1 = i; 
         ll c2 = a/i; 
         if(c1 !=c2 &&  c1*c2/__gcd(c1,c2) == a){
             cout<<c1<<" "<<c2<<"\n";
             return; 
         }
         }
     }
}
 int main()
 {
   
     int t = 1; 
    //   scanf("%d",&t); 
        
         while(t--){
             solve(); 
            // cout<<"\n"; 
         }
 }
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
     cin>>n;
    int k; 
    cin>>k; 
    cout<<0<<"\n"; 
    int c; 
    cin>>c; 
    if(c == -1){
        exit(0); 
    }
    if(c == 1){
        return; 
    }
    for(int i = 1 ; i <= n-1 ; i ++ ){
        int g = i ^ (i-1); 
        cout<<g<<"\n"; 
        int c1; 
        cin>>c1; 
        if(c1 == -1){
            exit(0); 
        }
        if(c1 == 1){
            return; 
        }
        continue; 
    }
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
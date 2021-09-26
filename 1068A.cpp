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
int factorial( int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res = ((res)%mod * (i)%mod)%mod;
    return res%mod;
}
bool sortbysec(const pair<ll,vector<ll>> &a,
              const pair<ll,vector<ll>> &b)
{
    return (a.first < b.first);
}
 void solve(){
     ll n,m,k,l;
     cin>>n>>m>>k>>l; 
     if(m>n){ /// more friends; 
         cout<<-1; 
         return; 
     }
     ll  c = n/m; 
     c =c * m; 
    //  if(n-k < l){
    //      cout<<-1; 
    //      return;
    //  }
     if(c - k >= l){
        //  cout<<-1; 
          cout<< (ll)(ceil((l+k)/(long double)m))<<"\n"; 
         return; 
     }
     else{
         cout<<-1; 
         return; 
     }
    //  if(c<l){
    //      cout<<-1; 
    //      return; 
    //  }
   

}

 int main()
 {   int t = 1; 
    //    scanf("%d",&t);    
    while(t--){
solve(); 
// cout<<"\n"; 
 }
}
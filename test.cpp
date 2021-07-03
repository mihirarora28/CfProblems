#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
 vector<ll>ans; 
 ll ff = 1;
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
      int len = ans.size(); 
      ll ff1 = ff; 
      ll  answer = 0 ; 
      ff1 = ff1/ans[len-1]; 
       ff1 = ff1/ ans[len-2]; 
      for(int i = len-2;i>=0;i--){
          answer+=(n/ff1)*(ans[i]); 
  cout<<answer<<" "<<ff1<<" " <<ans[i]<<"\n"; 
          ff1 = ff1 / ans[i - 1]; 
        
      }
      cout<<answer + (n/2)*2; ; 
        
 }
 int main()
 {
      SieveOfEratosthenes(1000000); 
       ff = 1; 
for(int i = 0 ; i < primes.size(); i ++)
{
    // cout<<ff<<"\n"; 
     ff = ff*primes[i]; 
      if(ff <= 1e16){
     ans.push_back(primes[i]); 
         }
         else
         {
         break; 
         }
}
     int t = 1; 
      scanf("%d",&t); 
        
         while(t--){
             solve(); 
            cout<<"\n"; 
         }
 }
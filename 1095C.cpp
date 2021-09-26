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
      int n,k; 
      cin>>n>>k; 
      ll c = n; 
      int low =0; 
      while(c!=0){
          int g = c & 1; 
          if(g == 1){
              low++; 
          }
          c = c / 2; 
      }
      if(k >= low && k <= n){
          cout<<"YES\n"; 
          queue<int>q; 
          int ones = 0 ;
          int c = 1; 
          while(n!=0){
              int gg = n & 1; 
              if(gg == 1){
                  q.push(c); 
              }
              c = c * 2; 
              n = n / 2; 
             
          }
          int ans = low; 
           while(!q.empty()){
               int g = q.front(); 

               if(ans + ones == k){
                   break; 
               }
                if(g!=1){
                    int cc = g/2; 
                    q.push(cc); 
                      q.push(cc); 
                      q.pop(); 
                  ans++; 
                }
                else{
                     q.pop(); 
                     q.push(1);
                }
                
              }
              while(!q.empty()){
                  cout<<q.front()<<" "; 
                  q.pop(); 
              }

      } 
      else{
          cout<<"NO"; 
          return; 
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
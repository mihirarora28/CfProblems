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
    int n,m; 
    cin>>n>>m; 
    int friends[n+1] = {0}; 
    int nobel = n; 
    for(int i = 0 ; i < m; i ++ ){
        int a,b; 
        cin>>a>>b;
        if(a>b){
            swap(a,b); 
        } 
        if(friends[a] == 0)
        nobel -- ;
        friends[a] ++ ;
    }
    int q; 
    cin>>q; 
    while(q--)
    {
        int c; 
        cin>>c; 
        if(c==3)
        {
            cout<<nobel<<"\n"; 
        }
      else  if(c == 1){
            int a,b; 
            cin>>a>>b;
            if(a>b){
                swap(a,b); 
            }
            if(friends[a] == 0){
                nobel--; 
            }
            friends[a]++; 
        }
        else{
              int a,b; 
            cin>>a>>b;
            if(a>b){
                swap(a,b); 
            }
                friends[a]--; 
                 if(friends[a] == 0){
                nobel++;  
            }

        }
        // cout<<nobel<<"\n"; 
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
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
     int blocked = 0 ;
      int n; 
      cin>>n; 
    int q; 
    cin>>q; 
    set<pair<int,int>>s; 
     while(q--){
         int a,b; 
         cin>>a>>b;
         auto cc = s.find({a,b}); 
         if(cc == s.end())
         {
            //  cout<<"fer"; 
         auto c1 = s.find({3-a,b}); 
         if(c1 == s.end()){
          ;
         }
         else{
             blocked++; 
         }
           auto c2 = s.find({3-a,b-1}); 
         if(c2 == s.end()){
           ;
         }
         else{
             blocked++; 
         }
           auto c3 = s.find({3-a,b+1}); 
         if(c3 == s.end()){
          ;
         }
         else{
             blocked++; 
         }
         s.insert({a,b}); 
         }
         else{
             auto c1 = s.find({3-a,b}); 
         if(c1 == s.end()){
           ;
         }
         else{
             blocked--; 
         }
           auto c2 = s.find({3-a,b-1}); 
         if(c2 == s.end()){
            ;
         }
         else{
             blocked--; 
         }
           auto c3 = s.find({3-a,b+1}); 
         if(c3 == s.end()){
           ;
         }
         else{
             blocked--; 
         }
         s.erase({a,b}); 
         }

         ////////////
         if(blocked == 0){
             cout<<"Yes\n"; 
         }
         else{
             cout<<"No\n"; 
         }
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
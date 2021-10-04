#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
 ll mod = 10000000000007;
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
     map<string,int>mapp;
     int n; 
     cin>>n; 
     vector<string>v; 
     vector<string>s1; 
     int ctr  = 0 ;
     for(int  i = 0 ; i < n; i ++)
     {
         string ss; 
         cin>>ss; 
         s1.push_back(ss);
         
     mapp[ss] ++; 
     }
     for(int  i = 0; i < n; i ++ )
     {
         string s = s1[i]; 
         if(mapp[s] > 1){
             ctr++; 
             char ccc = '0'; 
             for(int i = 0; i <= 9; i ++ ){
                 char ccc1 = (char)(ccc + i); 
                 string c = s.substr(0,3);
                 c = c + ccc1; 
                 if(mapp[c] == 0){
                     mapp[c]++;
                     v.push_back(c);
                     break; 
                 }
             }
             mapp[s]--; 

         }
         else{
             v.push_back(s); 
         }
     }
     cout<<ctr<<"\n"; 
     for(auto i :v){
         cout<<i<<"\n"; 
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
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
     map<int,char>mapp;
     map<int,int>index; 
     vector<int>Ls(200003); 
     vector<int>Rs(200003); 
     Ls[0] = 0 ; 
     Rs[0] = 0 ; 
     int i = 1 ;
     while(n--){
         char c; 
         int k; 
         cin>>c>>k; 
         if(c == '?'){ 
             if(mapp[k] == 'L'){
                 int c = Ls[i-1] - Ls[index[k]]; 
                 int c1 = (Rs[i-1] - Rs[index[k]]) + index[k] - 1;
                //  cout<<c<<" "<<c1<<"\n"; 
                 cout<<min(c,c1)<<"\n";  
             }
             else{
                    int c = Rs[i-1] - Rs[index[k]]; 
                 int c1 = (Ls[i-1] - Ls[index[k]]) + index[k] - 1;
                 cout<<min(c,c1)<<"\n";  
             }
         }
         else{
              index[k] = i; 
              mapp[k] = c; 
              if(c == 'L')
              {
                  Ls[i] = Ls[i-1] + 1; 
                  Rs[i] = Rs[i-1] ; 
              }
              else{
                  Rs[i] = Rs[i-1] + 1; 
                  Ls[i] = Ls[i-1] ; 
              }
              i++;
         }
        
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
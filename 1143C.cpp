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
    int n1 = n; 
    bool visited[n+1]; 
    bool out[n+1]; 
    memset(visited,true,sizeof(visited)); 
    memset(out,true,sizeof(out)); 


        int ctr= 1; 

    while(n--){
        int a,b; 
        cin>>a>>b; 
        out[ctr] = b;
        ctr++; 
        if(a == -1){
            continue; 
        } 
        visited[a] = visited[a] & b;
    }

    int ctrrr = -1; 
    //  
    for(int i = 1 ; i  <=n1 ; i ++ ){
        // cout<<"fe";
        if(visited[i] == true && out[i] == true){
            ctrrr = 1; 
            cout<<i<<" "; 
        }
        // cout<<visited[i] << " "<<out[i] <<"\n"; 
    }
    if(ctrrr == -1){
        cout<<-1; 
        return; 
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
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
    string s; 
    cin>>s; 
    int m = 0 ; 
    int mm = 0 ;
    for(int i = 0 ; i  < s.length() ; i ++ ){
        if(s[i] == '0'){
            m++; 
            if(m == 5)
            m = 1;
            cout<<3<<" "<<m<<"\n"; 
        }
        else{
            if(mm %2 ==0)
            {
                cout<<1<<" "<<1<<"\n"; 
            }
            else{
                cout<<1<<" "<<3<<"\n";
            }
            mm++; 
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
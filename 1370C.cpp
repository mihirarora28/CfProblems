#include<bits/stdc++.h>
// 54   18/6   5/2   >1 AshishGup
/// 6 2
///  3 4 4 = 48
// 2 2 3 3 = 36
//  4 
///  3  3 2  ==  6 
/// 3 2 == 6
// 18     3 3 2 // 6 //  2 // 
//        3 
/// 3 3 4 = 36 - 12 - 4 
using namespace std; 
typedef long long int ll; 
vector<ll>primes;
vector<int>Graph[2005]; 
bool visited[2005]; 
long long int mod = 1000000007;
bool isPrime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}
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
     ll n; 
     cin>>n; 
     if(n == 1){
         cout<<"FastestFinger";
         return; 
     }
     if(n%2!=0){
         cout<<"Ashishgup"; 
         return; 
     }
     if(n == 2){
         cout<<"Ashishgup";
         return ;
     }
     double c = log2(n); 
     if(ceil(c) == (int)c){
         cout<<"FastestFinger"; 
         return; 
     }
     int c1 = n / 2; 

     if(c1%2!=0){
       if(isPrime(c1))
       {
         cout<<"FastestFinger"; 
         return; 
       }
       else{
           cout<<"Ashishgup"; 
       }
     }
     else{
         cout<<"Ashishgup"; 
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
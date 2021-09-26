#include <bits/stdc++.h>

using namespace std;
long long power(int b){
	long long c = 1; 
	while(b--){
		c = c*2; 
	}
	return c; 
}
long long values(int aa[]){
	long long answer = 0 ;
	for(int i = 1 ; i < 64; i ++ ){
		answer+= (aa[64-i]*power(i-1)); 
	}
}
int main() {
	 int t; 
	 cin>>t; 
pol:	 while(t--){
		 long long a,b,c; 
		 cin>>a>>b>>c; 
	// 	 long long d = power(c) - 1; 
	// 	if(b < d){
	// 		cout<<-1<<"\n"; 
	// 		continue; 
	// 	}
	
	//   long long cc = power(c) - 1; 
	//   if(cc>=a && cc<=b){
	// 	  cout<<cc<<"\n"; 
	// 	  continue; 
	//   }
	  for(long long i = a ; i <= b ; i ++ ){
		  long long cd = __builtin_popcountll(i); 
		  if(cd == c){
			  cout<<i<<"\n"; 
			  goto pol; 
			//   continue; 
		  }
	  }
	  cout<<-1; 
	  cout<<"\n"; 
		// long long cc = a; 
		// int dd = __builtin_popcount(cc); 
		// int diff = c - dd; 
		// vector<int>q; 
		// while(diff!=0){
		// 	int g = cc & 1; 
		// 	if(g == 0){
		// 		diff -- ;
		// 	}
		// }
		
	 }
}

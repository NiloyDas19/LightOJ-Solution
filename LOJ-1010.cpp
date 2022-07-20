#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nn "\n"


int main(){
	ll t=1,j=0;
	cin >> t;
	while(t--){
		ll row,col,div,ans=0,div1,re; 
		cin >> row >> col;
		cout << "Case " << ++j << ": ";
		if(row==1 || col==1){
			ans =  max(row,col);
		}
		else if(row==2 || col==2){
			if(col<row) swap(row,col);
			div = col/4;
			re = col%4;
			ans = 4*div + min(2LL,re) * 2;
		}
		else {
			div = (col-1)/2+1;
			div1 = (row-1)/2+1;
			ans+=(div*div1);
			ans+=((col/2)*(row/2));
		}
		cout << ans << nn;
	}
	return 0;
}
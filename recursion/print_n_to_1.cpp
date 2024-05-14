#include<bits/stdc++.h>
using namespace std;

void print_1_to_n(int n){
	if(n==1 || n==0){
		cout<<1;
		return ;
	}
	cout<<n<<" ";
	print_1_to_n(n-1);
	
}
int main(){
	int n;
	cin>>n;
	print_1_to_n(n);
}
//Problem Statement





// Compilation Completed
// For Input: 
// 291001
// Your Output: 
// -304440980
// Expected Output: 
// 21170395500

//for tackle this i need to use unsigned 
//long long so it can handle 10^9 value




#include<bits/stdc++.h>
using namespace std;



unsigned  long long maxProduct(int n) {
        // code here
        unsigned long long ans=0;
        if(n%2==0){
            ans = (n/2ll)*(n/2ll);
            
        }else{
            cout<<"n: "<<n<<endl;
            cout<<(n/2ll)<<endl;
        
            ans = (n/2ll)*(n/2ll+1);
        }
        
        return ans;
    }

int main(){
    int n;
    cin>>n;
	cout<<maxProduct(n);
}
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v,int temp){
	if(v.size()==0 || v[v.size()-1]<=temp){
		v.push_back(temp);
		return;
	}

	int val = v[v.size()-1];
	v.pop_back();
	insert(v,val);
}

void sortAnArrayUsingRecursion(vector<int> &v){

	 cout<<"saurav"<<endl;
	if(v.size()==1){
		return ;
	}
	int temp = v[v.size()-1];
	v.pop_back();
	sortAnArrayUsingRecursion(v);
	insert(v,temp);


}



int main(){
	int n;
	cin>>n;
	vector<int> sortedVectorArray;

	for(int i=0;i<n;i++){
		int item ;
		cin>>item;
		sortedVectorArray.push_back(item);
	}

	

	sortAnArrayUsingRecursion(sortedVectorArray);

	for(int i=0;i<sortedVectorArray.size();i++){
		cout<<sortedVectorArray[i]<<" ";
	}
}
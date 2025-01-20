#include<bits/stdc++.h>
using namespace std;

//input 
//3 alice 05-06-2000 3 12345678 empty (022)-2456-7890 5 
//BobParson empty 1+9156728192 10 
//AliceWeasley empty 2 12345678 98765432 20"
vector<string> split(string str,char breaker){
	vector<string> splitString;
	int i=0;
	string s="";
	while(str[i]!='\0'){
		if(str[i]==' '){
			splitString.push_back(s);
			s="";
		}else{
			s=s+str[i];
		}
		i++;
	}
	splitString.push_back(s);
	return splitString;
}

string findNameOfMaxContactUpdateTime(vector<string> duplicatePhonesNames,unordered_map<string,string>& updateContactTime,unordered_map<string, int>& result_name_taken){

	//find max contact updated time
	string finalName = "";
	int max_m=INT_MIN;

	for(auto n:duplicatePhonesNames){
		result_name_taken[n]=1;
		cout<<updateContactTime[n]<<endl;

		// if(updateContactTime[n]>max_m){
		// 	max_m=updateContactTime[n];
		// 	finalName=n;
		// }

	}
	return finalName;
}
int main(){
	//cout<<"Welcome Back! Saurav";
	string str;
	getline(cin,str);
	//cout<<str<<endl;

	vector<string> splitString=split(str, ' ');
	unordered_map<string,string> dob;
	unordered_map<string,vector<string>> phones;
	unordered_map<string,string> update_time_for_contact;
	unordered_map<string,vector<string>> namephonemapping;
	unordered_map<string ,int> resultnameTaken;

	int i=1;
	vector<string> names;
	while(i<splitString.size()){
		string name = splitString[i++];
		cout<<"name: "<<name;
		names.push_back(name);
		dob[name]=splitString[i++];
		cout<<" dob[name]: "<<dob[name];
		int p=stoi(splitString[i++]);
		cout<<" p: "<<p;
		while(p--){
			string mob=splitString[i++];

			phones[name].push_back(mob);
			if(mob=="empty") continue;
			//here we are storing mobile as a key, And on that key we are 
			//storing array of string name which contain same this phone no.
			//basically we are finding name which have same phone number
			namephonemapping[mob].push_back(name);
			
		}
		update_time_for_contact[name]=splitString[i++];
		cout<<" update_time: "<<update_time_for_contact[name]<<endl;
	}

	//this is only for print statement 
	//printing duplicate phone against different name.
	for (auto& it: namephonemapping) {
      // Do stuff
      cout << it.first<<" ";
      for(auto n:it.second){
      	cout<<n<<" ";
      }
      cout<<endl;
    }

    //now we are chcking for phone key, which contains 
    //more than one name.
    //and after that we find maximum contact updated time
    //because we have to take that name for our final result
    for(auto& it:namephonemapping){
    	if(it.second.size()>1){
    		string finalName = findNameOfMaxContactUpdateTime(it.second,update_time_for_contact,resultnameTaken);
    		cout<<"finalName: "<<finalName;
    	}
    }


}
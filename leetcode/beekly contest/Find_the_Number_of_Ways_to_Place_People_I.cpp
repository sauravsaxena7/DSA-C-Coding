#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool findAllCoordinatesOfRectangleAndValidate(int fullGraph[51][51],int a,int b,int c,int d){

        bool isValidRectangle=true;
        //cout<<"lola pola"<<endl;


        if(a<=c && b>=d){
            // cout<<a<<","<<b<<"  "<<c<<","<<d<<endl;
            for(int i=a;i<=c;i++){
                int flag=0;
                for(int j=b;j>=d;j--){
                    //cout<<i<<" "<<j<<endl;
                    if((i==a && j==b) ||(i==c&&j==d))
                    {   //cout<<"lolaa"<<i<<" "<<j<<endl;
                        continue;
                    }else{
                        if(fullGraph[i][j]==1){
                            isValidRectangle=false;
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag==1){
                    break;
                }
            }
        }else{
            isValidRectangle=false;
        }

        return isValidRectangle;

    }


    int numberOfPairs(vector<vector<int>>& points) {
        int arr[51][51];
        int finalCount=0;
        
        
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                arr[i][j]=0;
            }
        }
        
        for(int i=0;i<points.size();i++){
            int a=points[i][0];
            int b=points[i][1];
            //cout<<a<<" "<<b<<endl;
            arr[a][b]=1;
            
        }

        for(int i=0;i<points.size();i++){
            int a=points[i][0];
            int b=points[i][1];

            for(int j=0;j<points.size();j++){
                if(i!=j){
                    int c=points[j][0];
                    int d=points[j][1];
                     //cout<<"a "<<a<<" b "<<b<<" c "<<c<<" d "<<d<<endl;
                    if(findAllCoordinatesOfRectangleAndValidate(arr,a,b,c,d)){
                        finalCount++;
                    }
                }
                
            }
        }

        // for(int i=0;i<=10;i++){
        //     for(int j=0;j<=10;j++){
        //         cout<<arr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return finalCount;
        
    }

};

int main(){
    Solution ob;
    int n;
    cin>>n;

    vector<vector<int>> points;
    for(int i=0;i<n;i++){
        vector<int> item;
        int a,b;
        cin>>a>>b;
        item.push_back(a);
        item.push_back(b);
        points.push_back(item);

    }
    cout<<ob.numberOfPairs(points);
}

//[[6,2],[4,4],[2,6]]
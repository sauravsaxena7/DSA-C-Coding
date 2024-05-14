//Maximum Good Subarray Sum--leetcode
// You are given an array nums of length n and a positive integer k.

// A subarray of nums is called good if the absolute difference between its first and last element is exactly k, in other words, the subarray nums[i..j] is good if |nums[i] - nums[j]| == k.

// Return the maximum sum of a good subarray of nums. If there are no good subarrays, return 0.

// Input: nums = [1,2,3,4,5,6], k = 1
// Output: 11
// Explanation: The absolute difference between the first and last element must be 1 for a good subarray. All the good subarrays are: [1,2], [2,3], [3,4], [4,5], and [5,6]. The maximum subarray sum is 11 for the subarray [5,6].


// Constraints:

// 2 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 1 <= k <= 109

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

    	long long finalSum=-999999999;
    	//cout<<"saurv"<<endl;
    	int i=0,j=0;

    	int f=nums[i];
    	int l=nums[j];
    	long long sum=0;

    	while(i<nums.size() && j<nums.size()){
    		sum=sum+nums[j];
    		cout<<f<<" "<<l<<" "<<sum<<"  abs(f-l) "<<abs(f-l)<<" finalSum "<<finalSum<<endl;
    		if(abs(f-l)==k && finalSum<sum){
    			
    				finalSum=sum;
    				sum=sum-nums[i];
    			i=i+1;
    			f=nums[i];	
    		}else if(abs(f-l)<k && finalSum>sum){
    			sum=sum-nums[i];
    			i=i+1;
    			f=nums[i];
    		}
    		j=j+1;
    		l=nums[j];
    	}

    	return finalSum;
        
    }
};

int main()
{
	vector<int> arr;
	int n,k;
	cin>>n>>k;

	for(int i=0;i<n;i++){
		int item;
		cin>>item;
		arr.push_back(item);
	}
	Solution obj;
	cout<<obj.maximumSubarraySum(arr,k);
	return 0;
}
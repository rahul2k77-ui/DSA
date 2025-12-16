#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> twosum(vector<int>& num,int target){
        int n= num.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(num[i]+num[j]==target){
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++){
        cin >>nums[i];
    }
    int target;
    cout<<"Enter target: ";
    cin >> target;

    Solution sol;
    vector<int> result= sol.twosum(nums,target);

    if(!result.empty()){
        cout<<"Indices: ["<<result[0]<<", "<<result[1]<<"]"<<endl;
    }
    else{
        cout<<"No two numbers add up to the target."<<endl;
    }

    return 0;
}
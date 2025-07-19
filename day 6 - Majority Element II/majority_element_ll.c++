class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        vector<int>ans;
        
        // making variables for storing elements with majority elements
        int ele1 = 0, ele2 = 0;
        int count1 = 0, count2 = 0;
        
        // to find out the elements with majority elements
        for(int i = 0;i < arr.size();i++){
            if(count1 == 0 and arr[i] != ele2){
                ele1 = arr[i];
                count1 = 1;
            }
            else if(count2 == 0 and arr[i] != ele1){
                ele2 = arr[i];
                count2 = 1;
            }
            else if(ele1 == arr[i]) count1++;
            else if(ele2 == arr[i]) count2++;
            else{
                count1--;
                count2--;
            }
        }
        
        
        // then to count number of occurence of majority elements
        count1 = 0, count2 =0;
        for(int i = 0;i < arr.size();i++){
            if(ele1 == arr[i]) count1++;
            else if(ele2 == arr[i]) count2++;
        }
        
        // if they are occur more than n/3 times push them in answer
        int max_occur = (int)(arr.size()/3) + 1;
        if(count1 >= max_occur){
            ans.push_back(ele1);
        }
        if(count2 >= max_occur){
            ans.push_back(ele2);
        }
        
        // sort the answer as per the question
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

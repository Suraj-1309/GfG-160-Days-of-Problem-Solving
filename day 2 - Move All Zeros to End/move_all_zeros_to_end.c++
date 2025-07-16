// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int low = 0 , high = 0;
        while(high < arr.size()){
            if(arr[low] != 0 and arr[high] != 0){
                low++;
                high++;
            }
            else if(arr[low] == 0 and arr[high] != 0){
                swap(arr[low], arr[high]);
                low++;
            }
            else{
                high++;
            }
        }
    }
};

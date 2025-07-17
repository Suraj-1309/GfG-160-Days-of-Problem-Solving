class Solution {
  public:
    void reverseArr(vector<int>& arr, int low , int high){
        while(low < high){
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        d = d%arr.size();
        
        int low = 0, high = d-1;
        reverseArr(arr, low, high);
        
        low = d, high = arr.size()-1;
        reverseArr(arr, low, high);
        
        low = 0, high = arr.size()-1;
        reverseArr(arr, low, high);
    }
    
};

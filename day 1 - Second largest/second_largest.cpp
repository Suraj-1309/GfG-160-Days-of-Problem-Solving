class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int lar = -1 , sec_lar  = -1;
        for(int i = 0; i < arr.size() ;i++){
            if(lar < arr[i]){
                sec_lar = lar;
                lar = arr[i];
            }
            else if(sec_lar < arr[i] and arr[i] < lar){
                sec_lar = arr[i];
            }
        }
        return sec_lar;
    }
};

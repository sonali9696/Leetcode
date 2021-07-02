class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
        int index, n = arr.size(), i, j;
        vector<int> kClosestElements;
        
        if(x < arr[0]) {
            index = -1;
            i = -2; 
            j = 0;
        }
        else if(x > arr[n-1]){
            index = n;
            i = n-1;
            j = n+1;
        }
        else{
            int lowerindex = lower_bound(arr.begin(), arr.end(), x) - arr.begin(); //=x or right after x
            if(arr[lowerindex] == x) { //x present in array
                kClosestElements.push_back(x);
                i = lowerindex-1;
                j = lowerindex+1;
            }
            else{
                i = lowerindex-1;
                j = lowerindex;
            }
        }
        
        if(kClosestElements.size() == k) return kClosestElements;
            
        while(i >= 0 && j < n)
        {
            if((x - arr[i]) < (arr[j] - x) || (x - arr[i]) == (arr[j] - x)){
                kClosestElements.insert(kClosestElements.begin(),arr[i]);
                i--;
            }
            else{
                kClosestElements.push_back(arr[j]);
                j++;
            }
            if(kClosestElements.size() == k) return kClosestElements;
        }
        
        while(i >= 0)
        {
            kClosestElements.insert(kClosestElements.begin(),arr[i]);
            i--;
            if(kClosestElements.size() == k) return kClosestElements;
        }
        
        while(j < n){
            kClosestElements.push_back(arr[j]);
            j++;
            if(kClosestElements.size() == k) return kClosestElements;
        }
        
        return kClosestElements;
    }
};
class Solution {
public:
    int search(vector<int>& n, int target) {
        int low = 0;
        int high = n.size()-1;
        while(low <= high){
            int mid = low+(high-low)/2;
            if(n[mid] == target){
                return mid;
            }
            else if(n[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int n=matrix.size(),m=matrix[0].size();
        int low = 0;
        int high = n-1;
        int s=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid][0]>t){
                high=mid-1;
            }
            else{
                s=mid;
                low=mid+1;
            }

        }
        if (s ==-1) return false;
        // for(int i=0;i<n;i++){
        //     if(matrix[i][low] == t){
        //         return true;
        //     }
        // }
        // return false;
        int x=0, y=m-1;
        while(x<=y){
            int mid = x+(y-x)/2;
            if(matrix[s][mid]==t){
                return true;
            }
            else if (matrix[s][mid] < t) x = mid + 1;
            else y = mid - 1;
        }
        // cout<<x<<" "<<low<<endl;
        // if(matrix[low-1][x] == t){
        //     return true;
        // }
        return false;
        // cout<<low-1<<endl;
        // return true;

    }
};
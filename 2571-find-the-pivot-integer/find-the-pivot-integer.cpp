class Solution {
public:
    int pivotInteger(int n) {
        int leftsum=0;
        int rightsum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                leftsum+=j;
            }
            for(int k=i;k<=n;k++){
                rightsum+=k;
            }
            if(leftsum==rightsum){
                return i;
            }
                leftsum=0;
                rightsum=0;
        }
        return -1;
    }
};
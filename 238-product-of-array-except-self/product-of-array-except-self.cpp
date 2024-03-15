class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        long long int pro=1;
        bool zero=false;
        int zerocount=0;
        for(int i=0;i<n.size();i++){
            if(n[i]==0){
                zero=true;
                zerocount++;
                continue;
            }
            pro=pro*n[i];
        }
        cout<<pro;
        if(zero && zerocount==1){
            for(int i=0;i<n.size();i++){
                if(n[i]!=0){
                    n[i]=0;
                }
                else{
                    n[i]=pro;
                }
            }
            return n;
        }
        if(zero && zerocount>=2){
            for(int i=0;i<n.size();i++){
                n[i]=0;
            }
            return n;
        }
        for(int i=0;i<n.size();i++){
            n[i]=pro/n[i];
        }
        return n;
    }
};
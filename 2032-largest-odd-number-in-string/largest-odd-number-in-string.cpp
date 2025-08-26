class Solution {
public:
    string largestOddNumber(string n) {
        int ans=-1;
        string ss="";
        for(int i=n.length()-1;i>=0;i--){
            if(n[i]%2!=0){
                ans=i;
                break;
            }
        }
        if(ans==-1){
            return ss;
        }
        for(int i=0;i<=ans;i++){
            ss+=n[i];
        }
        cout<<ss<<endl;
        return ss;
    }
};
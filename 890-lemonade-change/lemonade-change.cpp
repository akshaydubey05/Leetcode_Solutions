class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        if(b[0]==10 || b[0]==20){
            cout<<1;
            return false;
        }
        //sort(b.begin(),b.end());
        int a5=0,a10=0,a20=0;
        for(int i=0;i<b.size();i++){
            if(b[i]==5){
                a5++;
            }
            else if(b[i]==10){
                if(a5>0){
                    a10++;
                    a5--;
                }
                else{
                    cout<<1<<b[i];
                    return false;
                }
            }
            else{
                if((a10>0 && a5>0)){
                    a20++;
                    a10--;
                    a5--;
                }
                else if(a5>=3){
                    a5-=3;
                    a20++;
                }
                else{
                    cout<<i<<" "<<a5<<" "<<a10<<" "<<b[i];
                    return false;
                }
            }
        }
        return true;
    }
};
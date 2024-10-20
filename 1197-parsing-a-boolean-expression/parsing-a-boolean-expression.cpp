class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        int i=0;
        for(char ch:expression){
            if(ch==')'){
                vector<char>operands;
                while(!st.empty() && st.top()!='('){
                    operands.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                char result = evaluate(op,operands);
                st.push(result);
            }else if(ch!=','){
                st.push(ch);
            }
        }
        return st.top()=='t';
    }
private:
    char evaluate(char op, vector<char>& operands) {
    if (op == '&'){
        for (char c : operands) {
            if (c == 'f') {
                return 'f';
            }
        }
        return 't';
    }else if (op == '|'){
        for (char c : operands) {
            if (c == 't') {
                return 't';
            }
        }
        return 'f';
    } else if (op == '!') {
        return (operands[0] == 't') ? 'f' : 't';
    }
    return 'f'; 
}
};
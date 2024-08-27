class Solution {
public:
    vector <string> output;
    void solve(string s , int open, int close, int n)
    {
        // if number of open and close parenthesis has reached n add the string generated
        if( open == n && close == n)
        {
            output.push_back(s);
            return;
        }

        // if number of open parenthesis < n then we can add more (
        if(open < n)
        solve(s+"(", open+1, close, n);

        // if number of close parenthesis < n and number of open > close parenthesis then we can add more )
        if(close < n && open > close)
        solve(s + ")" , open, close + 1 , n );

        return ;
    }

    
    vector<string> generateParenthesis(int n) {
        string s;
        int open = 0, close = 0;

        solve(s , open , close, n);

        return output;

    }
};

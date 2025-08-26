class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder();
        int open = 0;
        // First pass: remove extra ')'
        for (char c : s.toCharArray()) {
            if (c == '(') {
                open++;
                sb.append(c);
            } else if (c == ')') {
                if (open > 0) {
                    open--;
                    sb.append(c);
                }
            } else {
                sb.append(c);
            }
        }
        StringBuilder result = new StringBuilder();
        int close=0;
        for(int i=sb.length()-1;i>=0;i--){
            char ch = sb.charAt(i);
            if(ch==')'){
                close++;
                result.append(ch);
            } else if(ch=='('){
                if(close>0){
                    close--;
                    result.append(ch);
                }
            } else{
                result.append(ch);
            }
        }
        return result.reverse().toString();
    }
}
public class solution {

    public String minRemoveToMakeValid(String s) {
        // StringBuilder is a class used to create mutable strings (strings that can be
        // changed after creation
        // StringBuilder is mutable
        // You can modify the content (append, insert, delete, reverse, etc.) without
        // creating new objects every time.
        // This makes it faster and memory-efficient when you need to do lots of
        // modifications.
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
        // Second pass: remove extra '('
        StringBuilder result = new StringBuilder();
        int close = 0;
        for (int i = sb.length() - 1; i >= 0; i--) {
            char c = sb.charAt(i);
            if (c == ')') {
                close++;
                result.append(c);
            } else if (c == '(') {
                if (close > 0) {
                    close--;
                    result.append(c);
                }
            } else {
                result.append(c);
            }
        }
        return result.reverse().toString();
    }
}
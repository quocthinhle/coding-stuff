class Solution {
    List<String> res = new ArrayList<String>();
    
    public List<String> generateParenthesis(int n) {
        int[] selections = new int[2*n];
        backtrack(0, 2*n - 1, selections);
        return res;
    }
    
    void backtrack(int Try, int sz, int[] selections) {
        for (int i = 0; i <= 1; ++i) {
            selections[Try] = i;
            if (Try == sz) {
                process(selections);
            } else {
                backtrack(Try + 1, sz, selections);
            }
        }
    }
    
    void process(int[] selections) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < selections.length; ++i) {
            if (selections[i] == 1) {
                sb.append("(");
            } else {
                sb.append(")");
            }
        }
        
        String gen = sb.toString();
        if (isLegit(gen)) {
            res.add(gen);
        }
    }
    
    boolean isLegit(String a) {
        Stack<Character> s = new Stack<Character>();
        for (int i = 0; i < a.length(); ++i) {
            char k = a.charAt(i);
            if (k == '(') {
                s.push(k);
            } else {
                if (s.empty()) {
                    return false;
                } else {
                    s.pop();
                }
            }
        }
        return s.empty();
    }
}
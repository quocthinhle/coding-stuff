class Solution {
    String[] pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<String>();
        if (digits.length() == 0) return result;
        
        int selections[] = new int[digits.length()];
        
        backtrack(0, digits.length() - 1, selections, digits, result);
        
        return result;
    }
    
    private void backtrack(int Try, int sz, int[] selections, String digits, List<String> result) {
        for (int i = 0; i < pad[digits.charAt(Try) - '0'].length(); ++i) {
            selections[Try] = i;
            if (Try == sz) {
                process(selections, digits, result);
            } else {
                backtrack(Try + 1, sz, selections, digits, result);
            }
        }
    }
    
    private void process(int[] selections, String digits, List<String> result) {
        String res = "";
        for (int i = 0; i < selections.length; ++i) {
            res += pad[digits.charAt(i) - '0'].charAt(selections[i]);
        }
        result.add(res);
    }
}

// BASE ON THE CLASSIC SOLUTION ABOVE, OPTIMIZE IT:

class Solution {
    String[] pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    List<String> result = new ArrayList<String>();
    
    public List<String> letterCombinations(String digits) {
        
        if (digits.length() == 0) return result;
    
        backtrack(0, "", digits);
        
        return result;
    }
    

    public void backtrack(int Try, String currentString, String digits) {
        if (Try == digits.length()) {
            result.add(currentString);
        } else {
            for (int i = 0; i < pad[digits.charAt(Try) - '0'].length(); ++i) {
                backtrack(Try + 1, currentString + pad[digits.charAt(Try) - '0'].charAt(i), digits);
            }
        }
    }
}
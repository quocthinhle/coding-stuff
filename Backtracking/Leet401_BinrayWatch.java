class Solution {
    
    private List<String> lstHour = new ArrayList<String>();
    private List<String> lstMinute = new ArrayList<String>();
    List<String> res = new ArrayList<String>();
    
    public List<String> readBinaryWatch(int turnedOn) {
        
        
        int selections[] = new int[10];
        int values[] = {8,4,2,1,32,16,8,4,2,1};
        
        backtrack(0, 9, turnedOn, values, selections);
        
        return res;
        
    }
    
    private void backtrack(int Try, int sz, int turnedOn, int[] nums, int[] selections) {
        for (int i = 0; i <= 1; ++i) {
            selections[Try] = i;
            if (Try == sz) {
                process(selections, nums, turnedOn);
            } else {
                backtrack(Try + 1, sz, turnedOn, nums, selections);
            }
        }
    }
    
    private void process(int[] selections, int[] nums, int turnedOn) {
        int cnt = 0;
        int hour = 0;
        int minute = 0;
        
        for (int i = 0; i < selections.length; ++i) {
            if (selections[i] != 0) {
                ++cnt;
                
                if (i <= 3) {
                    hour += nums[i];
                }
                else {
                    minute += nums[i];
                }
            }
        }
        
        if (cnt != turnedOn) return;
        
        if (minute >= 60) {
            return;
        }
        if (hour >= 12) return;
        
        String hours = String.valueOf(hour);
        String minutes = String.valueOf(minute);
        
        
        if (minutes.length() == 1) minutes = "0" + minutes;
        
        res.add(hours + ":" + minutes);
    } 

}
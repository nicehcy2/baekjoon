import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        
        for(int i=0; i<participant.length; i++) { 
            if (!map.containsKey(participant[i]))
                map.put(participant[i], 1);
            else {
                int value = map.get(participant[i]);
                map.replace(participant[i], value + 1);
                  }
        }
        
        for(int i=0; i<completion.length; i++){
            if (map.containsKey(completion[i])) {
                int value = map.get(completion[i]);
                
                if (value == 1) map.remove(completion[i]);
                else map.replace(completion[i], value - 1);
            }
        }
        
        for (String key : map.keySet()) {
            answer = key;
        }
        
        return answer;
    }
}
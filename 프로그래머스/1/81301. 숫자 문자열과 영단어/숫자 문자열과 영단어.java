import java.util.*;
import java.util.concurrent.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        
        Map<String, Integer> map = new ConcurrentHashMap<>();
        map.put("zero", 0);
        map.put("one", 1);
        map.put("two", 2);
        map.put("three", 3);
        map.put("four", 4);
        map.put("five", 5);
        map.put("six", 6);
        map.put("seven", 7);
        map.put("eight", 8);
        map.put("nine", 9);
        
        String cur ="";
        String res = "";
        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            
            if (c >= '0' && c <= '9') {
                cur ="";
                res += c;
                continue;
            } else {
                cur += c;
            }
            
            if (map.containsKey(cur)) {
                res += map.get(cur);
                cur="";
            }
        }
        
        return Integer.parseInt(res);
    }
}
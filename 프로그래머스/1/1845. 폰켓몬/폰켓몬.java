import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0, cnt = 0;
        
        Map<Integer, Integer> hash = new HashMap<>();
        
        for (int n : nums) {
            if (hash.containsKey(n) == false)
                hash.put(n, 1);
            cnt++;
        }
        
        answer = hash.size();
        if (answer > cnt / 2) {
            answer = cnt / 2;
        }
        
        return answer;
    }
}
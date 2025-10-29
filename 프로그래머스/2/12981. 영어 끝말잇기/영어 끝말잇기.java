import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        
        HashSet<String> set = new HashSet<>();
        
        char prev = words[0].charAt(words[0].length() - 1);
        set.add(words[0]);
        for (int i=1; i<words.length; i++) {
            
            String str = words[i];
            if (!set.add(str) || prev != str.charAt(0)) 
                return new int[]{ (i % n) + 1, (i / n) + 1 };
            
            prev = str.charAt(str.length() - 1);
        }

        return new int[]{0, 0};
    }
}
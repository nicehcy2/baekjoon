import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] nums) {
        Map<Integer, Long> map = Arrays.stream(nums)
            .boxed()
            .collect(Collectors.groupingBy(
                num -> num, 
                Collectors.counting()
            ));
        
        return Math.min(map.size(), nums.length/2);
    }
}
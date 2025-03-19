class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        
        long start = times[0], end = 0, mid = 0, sum = 0;
        
        for (int time : times) {
            end = Math.max(end, time);
        }
        end *= n;
        
        while (start <= end) {
            mid = (start + end) / 2;
            
            sum = 0;
            for (int time : times) {
                sum += mid / time;
            }
            
            if (sum >= n) {
                answer = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            } 
        }
        
        return answer;
    }
}
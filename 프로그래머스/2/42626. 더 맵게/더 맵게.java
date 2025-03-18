import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int s : scoville) {
            pq.offer(s);
        }
        
        while (true) {
            
            if (pq.peek() >= K) {
                return answer;
            }
            
            int newItem = 0;
            if (pq.size() >= 2) {
                int n1 = pq.poll();
                int n2 = pq.poll();
                newItem = n1 + (n2 * 2);
                pq.offer(newItem);
                answer++;
            } else {
                return -1;
            }
        }
    }
}
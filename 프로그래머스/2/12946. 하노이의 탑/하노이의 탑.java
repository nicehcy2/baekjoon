import java.util.*;

class Solution {
    
    ArrayList<int[]> list = new ArrayList<>();
    
    public int[][] solution(int n) {

        int[][] answer = {};
        
        hanoi(n, 1, 2, 3);
        return answer = list.toArray(new int[list.size()][]);
    }
    
    void hanoi(int n, int start, int mid, int end) {
        
        if (n == 1) {
            
            move(start, end);
            return;
        }
        else {
            hanoi(n - 1, start, end, mid);
            move(start, end);
            hanoi(n - 1, mid, start, end);
        }
    }
    
    void move(int start, int end) {
        list.add(new int[]{start, end});
    }
}
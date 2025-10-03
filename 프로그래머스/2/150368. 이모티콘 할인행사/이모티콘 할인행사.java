import java.util.*;

class Solution {
    public int[] discount, gEmoticons, answer;
    public int[] dx = { 10, 20, 30, 40};
    public int emotioconsSize, userSize;
    public int[][] gUsers;
    
    public int[] solution(int[][] users, int[] emoticons) {
        
        answer = new int[2];
        gUsers = users; gEmoticons = emoticons;
        emotioconsSize = emoticons.length;
        userSize = users.length;
        discount = new int[emotioconsSize];
        
        dfs(0);
        
        return answer;
    }
    
    void dfs(int idx) {
        
        if (idx == emotioconsSize) {
            
            int sellSum = 0, joinCount = 0;
            for (int i=0; i<userSize; i++) {
                
                int uSum = 0;
                int stan = gUsers[i][0];
                for (int j=0; j<emotioconsSize; j++) {
                    if (stan <= discount[j]) {
                        uSum += gEmoticons[j] * (100 - discount[j]) / 100;
                    }
                }
                
                if (uSum >= gUsers[i][1]) {
                    joinCount++;
                }
                else {
                    sellSum += uSum;
                }
            }
            
            if (answer[0] < joinCount) {
                answer[0] = joinCount;
                answer[1] = sellSum;
            }
            else if (answer[0] == joinCount && answer[1] < sellSum) {
                answer[1] = sellSum;
            }
            
            return;
        }
        
        for (int i=0; i<4; i++) {
            
            discount[idx] = dx[i];
            dfs(idx + 1);
            discount[idx] = 0;
        }
    }
}
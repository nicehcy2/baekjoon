import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        
        int answer = 0, humanCount = friends.length;
        
        // 1. 이름(String)을 번호(int)로 저장하는 MAP
        Map<String, Integer> NameToNumMap = new HashMap<>();
        for (int i=0; i<humanCount; i++) {
            NameToNumMap.put(friends[i], i);
        }
        
        // 2. 선물 이력 및 선물 지수 만들기
        int[][] record = new int[humanCount][humanCount];
        int[][] score = new int[humanCount][3];
        
        for (int i=0; i<gifts.length; i++) {
            
            String[] human = gifts[i].split(" ");
            int sender = NameToNumMap.get(human[0]);
            int receiver = NameToNumMap.get(human[1]);
            
            record[sender][receiver]++;
            score[sender][0]++;
            score[receiver][1]++;
        }
        
        // 3. 선물 지수 계산
        for (int i=0; i<humanCount; i++) {
            score[i][2] = score[i][0] - score[i][1];
            System.out.println(score[i][2]);
        }
        
        // 4. 최종 계산
        int[] count = new int[humanCount];
        
        for (int i=0; i<humanCount; i++) {
            for (int j=i + 1; j<humanCount; j++) {
                
                int sendCount = record[i][j];
                int receiveCount = record[j][i];
                
                if (sendCount > receiveCount) {
                    count[i]++;
                }
                else if (sendCount == receiveCount) {
                    
                    if (score[i][2] > score[j][2]) {
                        count[i]++;
                    }
                    else if (score[i][2] < score[j][2]) {
                        count[j]++;
                    }
                }
                else {
                    count[j]++;
                }
            }
        }
        
        // 5. 가장 큰 값 찾기
        for (int i=0; i<humanCount; i++) {
            answer = Math.max(answer, count[i]);
        }
        
        return answer;
    }
}
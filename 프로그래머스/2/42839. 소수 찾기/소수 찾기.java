import java.util.*;

class Solution {
    
    int N;
    boolean visited[];
    boolean isVisited[];
    HashMap<Integer, Boolean> map;
    int result = 0;
    
    void dfs(String num, int count, String numbers) {
        
        if (count > 0 && count <= N) {
            if (!map.containsKey(Integer.parseInt(num))) {
                isPrime(Integer.parseInt(num));
                map.put(Integer.parseInt(num), true);
            }
        }
        
        for (int i=0; i<N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(num + numbers.charAt(i), count + 1, numbers);
                visited[i] = false;
            }
        }
    }
    
    void isPrime(int num) {
        
        isVisited = new boolean[num + 1];
        int sqrt = (int) Math.sqrt(num);
        
        for (int i=0; i<num + 1; i++) 
            isVisited[i] = true;
        
        isVisited[0] = false;
        if (num > 0) isVisited[1] = false;
        
        for (int i=2; i<=sqrt; i++) {
            if (isVisited[i]) {
                for (int j=i*i; j <=num; j+=i) {
                    isVisited[j] = false;
                }
            }
        }
        
        if (isVisited[num]) {
            result++;
            System.out.println(num);
        }
    }
    
    public int solution(String numbers) {
        N = numbers.length();
        visited = new boolean[N];
        map = new HashMap<>();
        
        dfs("", 0, numbers);
        
        return result;
    }
}
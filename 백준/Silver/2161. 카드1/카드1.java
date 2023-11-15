import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.valueOf(br.readLine());

        Queue<Integer> q = new LinkedList<Integer>();
        for(int i=1; i<=n; i++){
            q.offer(i);
        }

        StringBuilder sb = new StringBuilder();
        while(!q.isEmpty()){
            sb.append(q.poll()).append(" ");
            if(q.isEmpty()){
                break;
            }
            q.offer(q.poll());
        }

        System.out.println(sb.toString());
    }
}
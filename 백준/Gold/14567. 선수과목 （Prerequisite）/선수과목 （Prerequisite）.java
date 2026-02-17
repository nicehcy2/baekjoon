import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[] indegree;
    static List<Integer>[] graph;
    static int[] result;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        indegree = new int[N + 1];
        result = new int[N + 1];
        graph = new ArrayList[N + 1];
        for (int i=1; i<=N; i++) graph[i] = new ArrayList<>();

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int S = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            graph[S].add(E);
            indegree[E]++;
        }

        topologicalSort();

        for (int i = 1; i<=N; i++) {
            sb.append(result[i]).append(" ");
        }

        System.out.println(sb);

        br.close();
    }

    static void topologicalSort() {

        Queue<int[]> q = new LinkedList<>();
        for (int i=1; i<=N; i++) {
            if (indegree[i] == 0) q.add(new int[]{i, 1});
        }

        while (!q.isEmpty()) {

            int[] cur = q.poll();
            int curVertex = cur[0];
            result[curVertex] = cur[1];

            for (int i=0; i<graph[curVertex].size(); i++) {
                indegree[graph[curVertex].get(i)]--;
                if (indegree[graph[curVertex].get(i)] == 0)
                    q.add(new int[]{graph[curVertex].get(i), cur[1] + 1});
            }
        }
    }
}

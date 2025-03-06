import java.util.*;
import java.io.*;

public class Main {

    static List<Integer>[] graph;
    static int[] visited;
    static int result = -1;

    static void bfs(int start, int end) {

        Queue<Integer> q = new LinkedList<>();
        visited[start] = 1;
        q.offer(start);

        while (!q.isEmpty()) {

            int cur = q.poll();
            if (cur == end) {
                result = visited[cur] - 1;
            }

            for (int i=0; i<graph[cur].size(); i++) {

                int next = graph[cur].get(i);

                if (visited[next] == 0) {
                    q.offer(next);
                    visited[next] = visited[cur] + 1;
                }
            }
        }
    }

    public static void solution() throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(br.readLine());

        graph = new ArrayList[n + 1];
        visited = new int[n + 1];
        for (int i=1; i<=n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i=0;i<m; i++) {
            st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[a].add(b);
            graph[b].add(a);
        }

        bfs(start, end);

        System.out.println(result);

        bw.flush();
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws IOException {
        solution();
    }
}
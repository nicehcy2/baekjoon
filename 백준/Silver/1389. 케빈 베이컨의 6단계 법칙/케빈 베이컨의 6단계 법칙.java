
import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringTokenizer st;

    private static int N, M;
    private static ArrayList<Integer>[] graph = new ArrayList[101];
    public void Input() throws Exception {

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= N; i++) graph[i] = new ArrayList<>();

        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            graph[start].add(end);
            graph[end].add(start);
        }
    }

    public void Solution() throws Exception {
        int min = 1000000000, minIdx = -1;

        for (int i=1; i<= N; i++) {
            if (bfs(i) < min) {
                min = bfs(i);
                minIdx = i;
            }
        }

        bw.write(Integer.toString(minIdx));
    }

    public static void main(String[] args) throws Exception {
        new Main().Input();
        new Main().Solution();
        bw.flush();
        bw.close();
        br.close();
    }

    static int bfs(int start) {

        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        int[] visited = new int[N + 1];
        Arrays.fill(visited, -1);
        visited[start] = 1;

        while (!q.isEmpty()) {

            int cur = q.poll();

            for (int i=0; i< graph[cur].size(); i++) {
                int next = graph[cur].get(i);

                if (visited[next] == -1) {
                    visited[next] = visited[cur] + 1;
                    q.offer(next);
                }
            }
        }

        int sum = 0;
        for (int i=1; i<= N; i++) sum += visited[i];

        return sum;
    }
}
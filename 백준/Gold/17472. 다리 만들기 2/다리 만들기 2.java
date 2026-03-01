import java.util.*;
import java.io.*;

public class Main {

    static int N, M, result, cnt = 1;
    static int[][] arr, edge;
    static int[] dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1}, parent;
    static boolean[][] visited;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        visited = new boolean[N][M];
        for (int i=0; i<N; i++) {

            st = new StringTokenizer(br.readLine());
            for (int j=0; j<M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 1. 섬 만들기
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (arr[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        edge = new int[cnt][cnt];
        for (int i=1; i<cnt; i++) {
            for (int j=1; j<cnt; j++) {
                edge[i][j] = 30000;
            }
        }

        // 2. 각 섬의 테두리에서 가로 세로에 다른 섬이 있는지 확인
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {

                if (arr[i][j] != 0) {
                    int start = arr[i][j];
                    // 테두리인지 확인 -> 테두리면 그 방향으로 섬이 있는지 확인
                    for (int d=0; d<4; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];

                        // 테두리
                        if (0 <= ny && ny < N && 0 <= nx && nx < M && arr[ny][nx] == 0) {

                            int nny = ny;
                            int nnx = nx;
                            int distance = 0;
                            while (true) {

                                if (0 > nny || nny >= N || 0 > nnx || nnx >= M) break;
                                if (arr[nny][nnx] != 0) {
                                    int end = arr[nny][nnx];
                                    if (distance >= 2 && edge[start][end] > distance) {
                                        edge[start][end] = distance;
                                    }
                                    break;
                                }
                                nny += dy[d];
                                nnx += dx[d];
                                distance++;
                             }
                        }
                    }
                }
            }
        }

        // 3. MST
        parent = new int[cnt];
        for (int i=1; i<cnt; i++) {
            parent[i] = i;
        }

        List<int[]> graph = new ArrayList<>();

        for (int i=1; i<cnt; i++) {
            for (int j=1; j<cnt; j++) {
                if (edge[i][j] != 30000) {
                    graph.add(new int[]{i, j, edge[i][j]});
                }
            }
        }
        graph.sort((a, b) -> Integer.compare(a[2], b[2]));

        int used = 0;
        for (int i=0; i< graph.size(); i++) {

            if (find(graph.get(i)[0]) != find(graph.get(i)[1])) {
                result += graph.get(i)[2];
                union(graph.get(i)[0], graph.get(i)[1]);
                used++;
            }
        }

        // 4. 안되는지 확인
        if (used != (cnt - 2)) System.out.println(-1);
        else System.out.println(result);

        br.close();
    }

    static int find(int x) {

        // 조상 노드면 return -> p[x] = x면 조상 노드
        // 조상 노드의 parent는 자기 자신이다.
        if (parent[x] == x) return x;

            // 조상 노드가 아니면 부모 노드로 올라가서 계속 조상 노드를 찾는다.
        else return parent[x] = find(parent[x]);
    }

    static void union(int x, int y) {

        x = find(x);
        y = find(y);

        // 작은 최상위 노드로 저장한다.
        // 일관성만 있으면 큰 노드로 저장해도 괜찮다.
        if (x > y) parent[x] = y;
        else parent[y] = x;
    }

    static void bfs(int y, int x) {

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{y, x});
        visited[y][x] = true;
        arr[y][x] = cnt;

        while (!q.isEmpty()) {
            int cur[] = q.poll();
            int cy = cur[0];
            int cx = cur[1];

            for (int i=0; i<4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx] && arr[ny][nx] == 1) {
                    arr[ny][nx] = cnt;
                    visited[ny][nx] = true;
                    q.add(new int[]{ny, nx});
                }
            }
        }
    }
}

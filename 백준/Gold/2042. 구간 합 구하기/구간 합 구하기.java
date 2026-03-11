import java.util.*;
import java.io.*;

public class Main {

    static int N, M, K;
    static long[] arr, tree;

    static void update(int start, int end, int node, int target, long val) {

        // target leaf node에 도달 했을 경우 값을 바꾼다.
        if (start == end) {

            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        // target node 찾기
        // target node를 찾으면서 target node가 포함된 모든 구간합을 순회
        if (target <= mid) {
            update(start, mid, node * 2, target, val);
        } else {
            update(mid + 1, end, node * 2 + 1, target, val);
        }

        // 자식 노드들을 update 한 이후,
        // 현재 node(구간합)도 업데이트해야됨.
        // 현재 노드는 왼쪽 자식과 오른쪽의 합을 더하면 되기에 다음 수식을 시행
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    /**
     *
     * 조금이라도 겹치는 부분이 있으면 계속 탐색하자.
     * 완전히 겹치는게 있으면 해당 값을 구하고 재귀로 값을 더하자.
     *
     * @param start 목표 구간합의 시작
     * @param end 목표 구간합의 끝
     * @param node
     * @param nodeL 현재 탐색하고 있는 구간합의 시작
     * @param nodeR 현재 탐색하고 있는 구합의 끝
     * @return
     */
    static long query(int start, int end, int node, int nodeL, int nodeR) {

        // 범위를 벗어난 경우
        if (end < nodeL || nodeR < start) {
            return 0;
        }
        // 범위에 완전히 포함된 경우
        if (start <= nodeL && nodeR <= end) {
            return tree[node];
        }

        int mid = (nodeL + nodeR) / 2;
        return query(start, end, node * 2, nodeL, mid)
                + query(start, end, node * 2 + 1, mid + 1, nodeR);
    }

    /**
     * 세그먼트 트리 초기화
     */
    static long init(int start, int end, int node) {

        if (start == end) return tree[node] = arr[start];

        int mid = (start + end) / 2;
        return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        arr = new long[N + 1];
        tree = new long[N * 4];

        for (int i=1; i<=N; i++) {
            arr[i] = Long.parseLong(br.readLine());
        }
        init(1, N , 1);

        for (int i=0; i<M + K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            if (a == 1) {

                arr[b] = c;
                update(1, N, 1, b, c);
            }
            else {

                sb.append(query(b, (int)c, 1, 1, N)).append("\n");
            }
        }

        System.out.println(sb);
        br.close();
    }
}
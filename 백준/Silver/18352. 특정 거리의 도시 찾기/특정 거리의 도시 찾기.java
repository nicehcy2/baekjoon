import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int N, M, K, X;
	static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
	static int[] dist;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());

		for (int i = 0; i <= N; i++) {
			graph.add(new ArrayList<>());
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());

			graph.get(start).add(end);
		}

		dist = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			dist[i] = Integer.MAX_VALUE;
		}

		PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> Integer.compare(a, b));
		q.add(X);
		dist[X] = 0;

		while (!q.isEmpty()) {
			int cur = q.poll();

			for (int i = 0; i < graph.get(cur).size(); i++) {

				int next = graph.get(cur).get(i);

				if (dist[next] > dist[cur] + 1) {
					dist[next] = dist[cur] + 1;
					q.add(next);
				}
			}
		}

		int count = 0;
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= N; i++) {
			if (dist[i] == K) {
				sb.append(i + "\n");
				count++;
			}
		}

		if (count == 0) {
			System.out.println(-1);
			return;
		}
		System.out.println(sb);
	}
}
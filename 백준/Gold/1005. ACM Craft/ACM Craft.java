import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {

	static int N, K, X, Y, W, T;
	static int[] time, indegree;
	static List<Integer>[] graph;

	static void topologySort() {

		long[] result = new long[N + 1];
		Queue<Integer> q = new LinkedList<>();

		for (int i = 1; i <= N; i++) {

			if (indegree[i] == 0) {
				q.add(i);
				result[i] = time[i];
			}
		}

		while (!q.isEmpty()) {
			int cur = q.poll();

			for (int i = 0; i < graph[cur].size(); i++) {
				result[graph[cur].get(i)] = Math.max(result[graph[cur].get(i)], result[cur] + time[graph[cur].get(i)]);
				indegree[graph[cur].get(i)]--;

				if (indegree[graph[cur].get(i)] == 0) {
					q.add(graph[cur].get(i));
				}
			}
		}

		System.out.println(result[W]);
	}

	@SuppressWarnings("unchecked")
	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());

		while (T-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			time = new int[N + 1];
			indegree = new int[N + 1];

			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= N; i++) {
				time[i] = Integer.parseInt(st.nextToken());
			}

			graph = new ArrayList[N + 1];
			for (int i = 1; i <= N; i++) {
				graph[i] = new ArrayList<>();
			}

			for (int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());

				graph[from].add(to);
				indegree[to]++;
			}

			W = Integer.parseInt(br.readLine());

			topologySort();
		}
	}
}
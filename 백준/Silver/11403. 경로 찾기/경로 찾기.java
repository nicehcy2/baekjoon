import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {

	static int N;
	static List<Integer>[] arr;
	static boolean[] visited;

	static void dfs(int cur) {

		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur].get(i);

			if (!visited[next]) {
				visited[next] = true;
				dfs(next);
			}
		}
	}

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String result = "";
		N = Integer.parseInt(br.readLine());
		arr = new ArrayList[N];

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i] = new ArrayList<>();

			for (int j = 0; j < N; j++) {
				if (Integer.parseInt(st.nextToken()) == 1) {
					arr[i].add(j);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			visited = new boolean[N];
			dfs(i);

			for (int j = 0; j < N; j++) {
				if (visited[j])
					result += "1 ";
				else
					result += "0 ";
			}
			result += "\n";
		}

		System.out.println(result);
	}
}
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

class Main {

	static int N, M;
	static int[] arr;
	static List<Integer> result;
	static Set<List<Integer>> visited = new HashSet<>();

	static void dfs(int start, int count) {

		if (count == M) {

			if (!visited.contains(result)) {
				for (int i = 0; i < M; i++) {
					System.out.print(result.get(i) + " ");
				}
				System.out.println();
			}
			visited.add(result);

			return;
		}

		for (int i = start; i < N; i++) {
			result.set(count, arr[i]);
			dfs(i + 1, count + 1);
		}
	}

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		result = new ArrayList<>();

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			result.add(0);
		}

		Arrays.sort(arr);

		dfs(0, 0);
	}
}
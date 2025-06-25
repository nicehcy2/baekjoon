import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, D, K, C;
	static int[] arr, visited;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		arr = new int[N + K - 1];
		visited = new int[D + 1];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		for (int i = 0; i < K - 1; i++) {
			arr[N + i] = arr[i];
		}

		int count = 0, result = 0;
		for (int i = 0; i < K; i++) {

			if (visited[arr[i]] == 0) {
				count++;
			}
			visited[arr[i]]++;
		}
		if (visited[C] == 0)
			result = Math.max(count + 1, result);
		else
			result = Math.max(count, result);

		for (int i = 1; i < N; i++) {

			// out 로직
			visited[arr[i - 1]]--;
			if (visited[arr[i - 1]] == 0) {
				count--;
			}

			if (visited[arr[i + K - 1]] == 0) {
				count++;
			}
			visited[arr[i + K - 1]]++;

			if (visited[C] == 0)
				result = Math.max(count + 1, result);
			else
				result = Math.max(count, result);
		}

		System.out.println(result);
	}
}
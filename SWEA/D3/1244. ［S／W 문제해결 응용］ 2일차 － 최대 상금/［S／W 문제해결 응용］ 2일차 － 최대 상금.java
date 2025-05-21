import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {

	static int T, N, M, result = 0;
	static int[] arr;

	static void dfs(int start, int count) {

		if (count >= M) {

			String str = "";
			for (int i = 0; i < N; i++) {
				str += arr[i];
			}
			result = Math.max(result, Integer.parseInt(str));

			return;
		}

		for (int i = start; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				swap(i, j);
				dfs(i, count + 1);
				swap(i, j);
			}
		}
	}

	static void swap(int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {

			StringTokenizer st = new StringTokenizer(br.readLine());
			String num = st.nextToken();
			M = Integer.parseInt(st.nextToken());
			N = num.length();
			arr = new int[N];
			result = 0;

			if (N < M) {
				M = N;
			}

			for (int i = 0; i < N; i++) {
				arr[i] = num.charAt(i) - '0';
			}

			dfs(0, 0);

			System.out.println("#" + t + " " + result);
		}
	}
}
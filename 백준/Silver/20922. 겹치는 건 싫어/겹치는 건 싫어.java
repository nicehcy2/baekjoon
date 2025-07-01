import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, K, result = 0;
	static int[] arr, cnt;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		arr = new int[N];
		cnt = new int[100_001];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int start = 0, end = 0, count = 0;
		while (end < N) {
			int next = arr[end];

			if (cnt[next] == K) {

				while (cnt[next] == K) {
					int cur = arr[start++];
					count--;
					cnt[cur]--;
				}
			}
			cnt[next]++;
			end++;
			count++;
			result = Math.max(result, count);
		}

		System.out.println(result);
	}
}
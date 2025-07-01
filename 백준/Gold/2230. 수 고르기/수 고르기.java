import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M, result = 0, min = 2_000_000_010;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		Arrays.sort(arr);

		if (N == 1) {
			System.out.println(arr[0]);
			return;
		}

		int start = 0, end = 1;
		while (start <= end && start < N && end < N) {
			int diff = arr[end] - arr[start];

			if (diff >= M && diff < min) {
				min = diff;
			}

			if (diff < M) {
				end++;
			} else if (diff > M) {
				start++;
			} else {
				System.out.println(M);
				return;
			}
		}

		System.out.println(min);
	}
}
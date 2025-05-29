import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, C;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		// 정렬
		Arrays.sort(arr);

		int start = 0, end = arr[N - 1] - arr[0], result = 0;

		while (start <= end) {
			int mid = (start + end) / 2;

			int count = 1;
			int cur = arr[0];
			for (int i = 1; i < N; i++) {
				if (arr[i] - cur >= mid) {
					count++;
					cur = arr[i];
				}
			}

			if (count >= C) {
				result = mid;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		System.out.println(result);
	}
}
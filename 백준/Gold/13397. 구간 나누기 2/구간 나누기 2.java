import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int start = 0, end = 9999, result = 10001;

		while (start <= end) {

			int mid = (start + end) / 2;

			int count = 1;

			int min = arr[0], max = arr[0];
			for (int i = 1; i < N; i++) {

				int cur = arr[i];
				if (Math.abs(cur - min) <= mid && Math.abs(max - cur) <= mid) {
					min = Math.min(min, cur);
					max = Math.max(max, cur);
				} else {
					count++;
					min = cur;
					max = cur;
				}
			}

			if (count <= M) {
				result = Math.min(result, mid);
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		System.out.println(result);
	}
}
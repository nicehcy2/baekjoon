import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, X, max = 0, days = 0;
	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());

		arr = new int[N];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		int count = 0;
		for (int i = 0; i < X; i++) {
			count += arr[i];
		}

		max = count;
		days = 1;
		for (int i = X; i < N; i++) {
			count -= arr[i - X];
			count += arr[i];

			if (count > max) {
				max = count;
				days = 1;
			} else if (count == max) {
				days++;
			}
		}

		if (max == 0) {
			System.out.println("SAD");
			return;
		}
		System.out.println(max);
		System.out.println(days);
	}
}
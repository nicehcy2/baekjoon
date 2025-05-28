import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] arr;
	static HashMap<Integer, String> map = new HashMap<>();

	static int lowerBound(int power) {

		int start = 0, end = N - 1, result = 0;

		while (start <= end) {

			int mid = (start + end) / 2;

			if (arr[mid] >= power) {
				result = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		return result;
	}

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			int power = Integer.parseInt(st.nextToken());
			arr[i] = power;

			// 칭호 하나만 하는 로직(먼저)
			map.put(i, str);
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < M; i++) {
			int power = Integer.parseInt(br.readLine());

			int key = lowerBound(power);
			sb.append(map.get(key) + "\n");
		}

		System.out.println(sb);
	}
}
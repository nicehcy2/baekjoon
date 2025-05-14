import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Solution {

	static int T;
	static List<Integer> arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());

		for (int i = 1; i <= T; i++) {

			StringTokenizer st = new StringTokenizer(br.readLine());
			int max = 0, min = 10001, result = 0, maxIdx = 0, minIdx = 0;
			arr = new ArrayList<>();

			for (int j = 0; j < 10; j++) {

				arr.add(Integer.parseInt(st.nextToken()));

				if (max < arr.get(j)) {
					max = arr.get(j);
					maxIdx = j;
				}

				if (min > arr.get(j)) {
					min = arr.get(j);
					minIdx = j;
				}
			}

			double sum = 0;
			for (int j = 0; j < 10; j++) {
				if (j != maxIdx && j != minIdx) {
					sum += arr.get(j);
				}
			}

			System.out.printf("#%d %.0f\n", i, sum / 8);
		}
	}
}
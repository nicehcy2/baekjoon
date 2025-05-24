import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;;

class Solution {

	static int[] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t <= 10; t++) {
			int N = Integer.parseInt(br.readLine());
			arr = new int[100];

			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 100; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}

			int count = 0;
			while (count < N) {

				int max = 0, min = 101, maxIdx = -1, minIdx = -1;
				for (int i = 0; i < 100; i++) {
					if (max < arr[i]) {
						max = arr[i];
						maxIdx = i;
					}

					if (min > arr[i]) {
						min = arr[i];
						minIdx = i;
					}
				}

				if (max - min == 1 || max - min == 0) {
					break;
				}

				arr[maxIdx]--;
				arr[minIdx]++;

				count++;
			}

			int finalMax = arr[0], finalMin = arr[0];
			for (int i = 1; i < 100; i++) {
				if (arr[i] > finalMax) finalMax = arr[i];
				if (arr[i] < finalMin) finalMin = arr[i];
			}

			System.out.println("#" + t + " " + (finalMax - finalMin));
		}
	}
}
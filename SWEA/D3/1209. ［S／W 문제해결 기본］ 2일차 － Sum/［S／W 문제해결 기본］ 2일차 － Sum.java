import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;;

class Solution {

	static int[][] arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t <= 10; t++) {
			
			int test = Integer.parseInt(br.readLine());
			int max = 0;
			arr = new int[100][100];
			for (int i = 0; i < 100; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int sum = 0;
				for (int j = 0; j < 100; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					sum += arr[i][j];
				}
				max = Math.max(max, sum);
			}

			for (int i = 0; i < 100; i++) {
				int sum = 0;
				for (int j = 0; j < 100; j++) {
					sum += arr[j][i];
				}
				max = Math.max(max, sum);
			}

			int sumA = 0, sumB = 0;
			for (int i = 0; i < 100; i++) {
				sumA += arr[i][i];
				sumB += arr[i][99 - i];
			}
			max = Math.max(Math.max(max, sumA), sumB);

			System.out.println("#" + test + " " + max);
		}
	}
}
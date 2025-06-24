import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] A, B, arr;

	public static void main(String args[]) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		A = new int[N];
		B = new int[M];
		arr = new int[N + M];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			B[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(A);
		Arrays.sort(B);

		int idxA = 0, idxB = 0, count = 0;
		while (count < N + M) {

			int curA = 1000000001, curB = 1000000001;
			if (idxA < N)
				curA = A[idxA];
			if (idxB < M)
				curB = B[idxB];

			if (curA < curB) {
				arr[count++] = curA;
				idxA++;
			} else {
				arr[count++] = curB;
				idxB++;
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N + M; i++) {
			sb.append(arr[i]).append(" ");
		}
		System.out.println(sb);
	}
}
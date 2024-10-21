import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringTokenizer st;

    private static int T, strike, ball, result;
    private static String num;
    private static boolean[] arr = new boolean[1000];

    public void Input() throws Exception {

        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        
        for (int i=0; i< T; i++) {
            st = new StringTokenizer(br.readLine());
            
            num = st.nextToken();
            strike = Integer.parseInt(st.nextToken());
            ball = Integer.parseInt(st.nextToken());
            
            Solve(i);
        }
    }
    
    static void Solve(int cnt) {
        
        for (int i= 123; i<= 987; i++) {

            String cmpNum = String.valueOf(i);

            int s = 0, b = 0;

            // strike/ball판독
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    if (j == k && cmpNum.charAt(j) == num.charAt(k)) {
                        s++;
                    }

                    if (j != k && cmpNum.charAt(j) == num.charAt(k)) {
                        b++;
                    }
                }
            }

            if (cnt == 0) {
                if (s == strike && b == ball) {
                    arr[i] = true;
                }
            }
            else {
                if (s != strike || b != ball) {
                    arr[i] = false;
                }
            }
        }
    }

    public void Solution() throws Exception {

        for (int i= 123; i<= 987; i++) {

            if (arr[i] == true) {
                String tmp = String.valueOf(i);
                if (tmp.charAt(0) != tmp.charAt(1) && tmp.charAt(1) != tmp.charAt(2) && tmp.charAt(0) != tmp.charAt(2)) {
                    if (tmp.charAt(0) != '0' && tmp.charAt(1) != '0' && tmp.charAt(2) != '0') {
                        result++;
                    }
                }
            }
        }

        bw.write(String.valueOf(result));
    }

    public static void main(String[] args) throws Exception {
        new Main().Input();
        new Main().Solution();
        bw.flush();
        bw.close();
        br.close();
    }
}
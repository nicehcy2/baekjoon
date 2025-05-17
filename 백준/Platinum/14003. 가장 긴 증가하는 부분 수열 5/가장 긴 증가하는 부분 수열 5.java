import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static int[] arr, indexArr;
    static List<Integer> list = new ArrayList<>();

    static void solve() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        arr = new int[N];
        indexArr = new int[N];

        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        list.add(arr[0]);
        indexArr[0] = 1;
        for (int i=0; i<N; i++) {
            
            if (arr[i] > list.get(list.size() - 1)) {
                list.add(arr[i]);
                indexArr[i] = list.size() - 1;
            } else {
                
                int start = 0, end = list.size() - 1, mid = 0;

                while (start < end) {
                    
                    mid = (start + end) / 2;
                    
                    if (list.get(mid) < arr[i]) {
                        start = mid + 1;
                    } else {
                        end = mid;
                    } 
                }
                
                list.set(end, arr[i]);
                indexArr[i] = end;
            }
        }

        System.out.println(list.size());

        int maxIdx = 0;
        int max = 0;
        for (int i=0; i<N; i++) {
            if (indexArr[i] > max) {
                max = indexArr[i];
                maxIdx = i;
            }
        }

        Stack<Integer> s = new Stack<>();
        s.push(arr[maxIdx]);
        for (int i = maxIdx - 1; i>=0; i--) {

            if (max - indexArr[i] == 1) {
                max = indexArr[i];
                s.push(arr[i]);
            }
        }

        while(!s.empty()) {
            System.out.print(s.pop() + " ");
        }
    }

    public static void main(String[] args) throws Exception {

        solve();
    }
}

import java.io.*;
import java.util.*;

public class Main {
    static String[] str = new String[4];
    static ArrayList<Character> gear[] = new ArrayList[4];
    static int k, idx, dir;

    public static void main(String[] args) throws Exception {
        Input();
        //Solve();
    }

    static void Input() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int i = 0; i < 4; i++) {
            str[i] = br.readLine();
        }

        for (int i = 0; i < 4; i++) {
            gear[i] = StringToArray(str[i]);
        }

        k = Integer.valueOf(br.readLine());

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            idx = Integer.parseInt(st.nextToken());
            dir = Integer.parseInt(st.nextToken());
            idx = idx - 1;

            Solve();

            /*
            System.out.println();
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 8; k++) {
                    System.out.print(gear[j].get(k) + " ");
                }
                System.out.println();
            }
            System.out.println();

             */
        }

        System.out.println(SumScore());
    }

    static int SumScore() {
        int sum = 0;

        for (int i = 0; i < 4; i++) {
            if (gear[i].get(0) == '1') {
                sum += (int) Math.pow(2, i);
            }
        }

        return sum;
    }

    static void Solve() throws Exception {
        int localDir = dir;
        ArrayList<Integer> plusRot = new ArrayList<>();
        ArrayList<Integer> minusRot = new ArrayList<>();

        // 더하는 방향으로 탐색
        for (int i = idx; i < 4; i++) {
            // 인덱스 범위가 초과 되면 탐색 종료
            if (checkPlusIdx(i)) {
                // 같은 극이면 탐색 종료
                if (gear[i].get(2) == gear[i + 1].get(6)) {
                    break;
                }
                // 다른 극이면 반대 방향으로 회전 후 적용
                else {
                    plusRot.add(i + 1);
                }
            } else {
                break;
            }
        }

        // 빼는 방향으로 탐색
        for (int i = idx; i >= 0; i--) {
            // 인덱스 범위가 초과 되면 탐색 종료
            if (checkMinusIdx(i)) {
                // 같은 극이면 탐색 종료
                if (gear[i].get(6) == gear[i - 1].get(2)) {
                    break;
                }
                // 다른 극이면 반대 방향으로 회전 후 적용(잘못된 코드)
                else {
                    minusRot.add(i - 1);
                }
            } else {
                break;
            }
        }

        gear[idx] = rotateArr(gear[idx], dir);
        localDir = dir;

        for (int i = 0; i < plusRot.size(); i++) {
            localDir *= -1;
            gear[plusRot.get(i)] = rotateArr(gear[plusRot.get(i)], localDir);
        }

        localDir = dir;
        for (int i = 0; i < minusRot.size(); i++) {
            localDir *= -1;
            gear[minusRot.get(i)] = rotateArr(gear[minusRot.get(i)], localDir);
        }

    }

    static Boolean checkMinusIdx(int i) {
        if (i - 1 < 0) {
            return false;
        } else return true;
    }

    static Boolean checkPlusIdx(int i) {
        if (i + 1 > 3) {
            return false;
        } else return true;
    }

    static ArrayList<Character> StringToArray(String s) {
        ArrayList<Character> gear = new ArrayList<>();

        for (int i = 0; i < 8; i++) {
            gear.add(s.charAt(i));
        }

        return gear;
    }

    static ArrayList<Character> rotateArr(ArrayList<Character> arr, int dir) {
        ArrayList<Character> rotatedArr = new ArrayList<>();

        // 시계 방향 회전
        if (dir == 1) {
            rotatedArr.add(arr.get(7));
            for (int i = 0; i < 7; i++) {
                rotatedArr.add(arr.get(i));
            }
        }
        // 반시계 방향 회전
        else if (dir == -1) {
            for (int i = 1; i < 8; i++) {
                rotatedArr.add(arr.get(i));
            }
            rotatedArr.add(arr.get(0));
        }

        return rotatedArr;
    }
}
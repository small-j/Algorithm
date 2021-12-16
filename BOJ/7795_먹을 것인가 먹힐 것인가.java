
//풀이
//정렬, 두 포인터

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        while(T > 0){
            T--;
            int N = scan.nextInt();
            int M = scan.nextInt();
            ArrayList<Integer> n = new ArrayList<Integer>();
            ArrayList<Integer> m = new ArrayList<Integer>();
            for(int i = 0; i<N; i++){
                int num = scan.nextInt();
                n.add(num);
            }
            for(int i = 0; i<M; i++){
                int num = scan.nextInt();
                m.add(num);
            }
            Collections.sort(n, new Desc());
            Collections.sort(m, new Desc());
            int cnt = 0, num = 0;
            for(int i = 0; i<n.size(); i++){
                for(int j = num; j<m.size(); j++){
                    if(n.get(i) > m.get(j)) {
                        num = j;
                        cnt += m.size() - j;
                        break;
                    }
                }
            }
            System.out.println(cnt);
        }
    }

    static class Desc implements Comparator<Integer> {
        @Override
        public int compare(Integer a, Integer b){
            return b.compareTo(a);
        }
    }
}

import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        List<int[]> works = new ArrayList<>();
        for(int i = 0; i<M; i++){
            int[] work = new int[3];
            work[0] = scanner.nextInt();
            work[1] = scanner.nextInt();
            work[2] = scanner.nextInt();
            works.add(work);
        }
        works.add(new int[]{0,0,0});

        works.sort(new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b){
                for(int i = 0; i < 2; i++){
                    if(a[i] != b[i]){
                        return Integer.compare(a[i], b[i]);
                    }
                }
                return 0;
            }
        });
        // works.sort(Comparator.comparingInt(a->a[0]));
        
        int[] dp = new int[M + 1];
        for(int i = 1; i < M+1; i++){
            dp[i] = dp[i-1];
            // for(int j = 0; j < i; j++){
            //     if(works.get(j)[1] < works.get(i)[0]){
            //         dp[i] = Math.max(dp[j]+works.get(i)[2], dp[i]);
            //     }
            // }
            int l = 0, r = i;
            while(l < r){
                int mid = (l + r) >> 1;
                if(works.get(mid)[1] < works.get(i)[0]){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            dp[i] = Math.max(dp[l-1] + works.get(i)[2], dp[i]);
        }

        System.out.println(dp[M]);
        scanner.close();
    }
}
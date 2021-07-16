import java.util.Scanner;
import java.io.*;
public class Main{
    public static void main(String[] args)throws Exception{
        StreamTokenizer sc=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter out=new PrintWriter(new OutputStreamWriter(System.out));
        sc.nextToken();
        int[] a=new int[110000];
        P[] q=new P[310000];
        int l=1,r=0,sum=0;
        int n=(int)sc.nval;
        for(int i=1;i<=n;i++) {
            sc.nextToken();
            int time=(int)sc.nval;
            sc.nextToken();
            int m=(int)sc.nval;
            for(int j=1;j<=m;j++) {
                sc.nextToken();
                int x=(int)sc.nval;
                r++;
                q[r]=new P(time,x);
                a[x]++;
                if(a[x]==1)sum++;
            }
            while(q[l].time<=time-86400) {
                int x=q[l].x;
                a[x]--;
                if(a[x]==0)sum--;
                l++;
            }
            out.write(sum+"\n");
        }
        out.flush();
    }
}
class P{
    int time,x;
    public P(int time,int x) {
        this.time=time;
        this.x=x;
    }
}
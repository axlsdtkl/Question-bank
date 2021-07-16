import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		int[][] f={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
		int n=cin.nextInt();
		int na=cin.nextInt();
		int nb=cin.nextInt();
		int[] a=new int[300];
		int[] b=new int[300];
		for(int i=0;i<na;i++)a[i]=cin.nextInt();
		for(int i=0;i<nb;i++)b[i]=cin.nextInt();
		int ans1=0,ans2=0;
		for(int i=0;i<n;i++) {
			int x=a[i%na];
			int y=b[i%nb];
			ans1+=f[x][y];
			ans2+=f[y][x];
		}
		System.out.println(ans1+" "+ans2);
	}
}
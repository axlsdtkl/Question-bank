import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		int prex=1,prey=n/2+1;
		int[][] f=new int[40][40];
		f[prex][prey]=1;
		for(int i=2;i<=n*n;i++) {
			if(prex==1&&prey!=n) {prex=n;prey++;}
			else if(prey==n&&prex!=1){prey=1;prex--;}
			else if(prex==1&&prey==n)prex++;
			else if(f[prex-1][prey+1]==0) {prex--;prey++;}
			else prex++;
			f[prex][prey]=i;
		}
		for(int i=1;i<=n;i++) {
			for(int j=1;j<n;j++)System.out.printf("%d ",f[i][j]);
			System.out.printf("%d\n",f[i][n]);
		}
	}
}
import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		int ans=0;
		int n=cin.nextInt();
		int x=cin.nextInt();
		for(int i=1;i<=n;i++) {
			int m=i;
			while(m>0) {
				if(m%10==x)ans++;
				m/=10;
			}
		}
		System.out.println(ans);
	}
}
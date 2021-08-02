import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) throws IOException {
		BufferedReader s=new BufferedReader(new InputStreamReader(System.in));
		String[] x=s.readLine().split(" ");
		int n=Integer.parseInt(x[0]);
		int m=Integer.parseInt(x[1]);
		Student[] a=new Student[110000];
		x=s.readLine().split(" ");
		a[0]=new Student(1,"");
		a[0].fx=Integer.parseInt(x[0]);
		a[0].name=x[1];
		for(int i=n-1;i>=1;i--) {
			a[i]=new Student(1,"");
			x=s.readLine().split(" ");
			a[i].fx=Integer.parseInt(x[0]);
			a[i].name=x[1];
		}
		int now=0,xx,yy;
		while(m>0) {
			m--;
			x=s.readLine().split(" ");
			xx=Integer.parseInt(x[0]);
			yy=Integer.parseInt(x[1]);
			xx=(xx+a[now].fx)%2;
			if(xx==0)now+=yy;else now-=yy;
			now=(now+n)%n;
		}
		System.out.println(a[now].name);
	}
}
class Student{
	public int fx;
	public String name;
	public Student(int fx,String name) {
		this.fx=fx;
		this.name=name;
	}
}

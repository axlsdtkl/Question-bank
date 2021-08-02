#include<bits/stdc++.h>
using namespace std;
int q,r[100050],d[100050],m[100050],y[100050],s=0,d1[15]={0,31,28,31,30,31,30,31,31,30,31,30,31},flag=0,a;
int main(){
	//freopen("julian.in","r",stdin);
	//freopen("julian.out","w",stdout);	
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>r[i];
		d[i]=1;
		m[i]=1;
		y[i]=4713;
	}
	for(int i=1;i<=q;i++){
		if(r[i]<=1721422){
			while(r[i]>=365){
				if((r[i]>=366&&(y[i]-1)%4==0)||(r[i]>=365&&(y[i]-1)%4!=0)){
					if((y[i]-1)%4==0){	
						y[i]--;
						r[i]=r[i]-366;
					}
					else{
						r[i]=r[i]-365;
						y[i]--;
					}
				}
                else{
                    break;}
			}
				if(r[i]<=365&&r[i]>=28){
					for(int j=1;j<=12;j++){
						if(r[i]-d1[j]<0)	break;
						r[i]=r[i]-d1[j];
						if(j==2&&((y[i]-1)%4==0))	r[i]=r[i]-1;
						m[i]=j+1;
					}
				}
				d[i]=d[i]+r[i];
			cout<<d[i]<<' '<<m[i]<<' '<<y[i]<<' ';
			cout<<"BC";
			cout<<endl;	
		}
		if(r[i]==1721423){
			cout<<31<<' '<<12<<' '<<1<<' ';
			cout<<"BC";
			cout<<endl;
		}
		if(r[i]>1721423){
			r[i]=r[i]-1721423;
			y[i]=1;
			m[i]=1;
			while(r[i]>=365){
				if((r[i]>=366&&y[i]%4==0)||(r[i]>=365&&y[i]%4!=0)){
					if(y[i]%4==0&&y[i]<=1582){	
						y[i]++;
						r[i]=r[i]-366;
					}
					if((y[i]%400==0||(y[i]%4==0&&y[i]%100!=0))&&y[i]>1582){	
						y[i]++;
						r[i]=r[i]-366;
					}
					else{
						r[i]=r[i]-365;
						y[i]++;
					}
				}
else{
                    break;}
				if(y[i]>1582&&flag==0){
					r[i]=r[i]+10;
					flag=1;
				}
			}
			if(r[i]<=365&&r[i]>=28){
				for(int j=1;j<=12;j++){
					if(r[i]-d1[j]<0)	break;
					r[i]=r[i]-d1[j];
					if(j==2&&((y[i]%4==0)&&y[i]<=1582))	r[i]=r[i]-1;
					if(j==2&&((y[i]%400==0||(y[i]%4==0&&y[i]%100!=0))&&y[i]>1582))	r[i]=r[i]-1;
					m[i]=j+1;
					a=d1[j];
				}
			}
			d[i]=r[i];
			if(d[i]==0){
				m[i]=m[i]-1;
				d[i]=a;
			}	
			cout<<d[i]<<' '<<m[i]<<' '<<y[i]<<' ';
			cout<<endl;	
		}
		flag=0;	
	}
	return 0;
}
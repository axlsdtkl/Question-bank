class Solution {
public:
    string smallestGoodBase(string n) {
        int m=n.length();
        long long x=0;
        for(int i=0;i<m;i++)x=x*10+n[i]-'0';
        long long now=1;
        int mark=0;
        for(int i=1;;i++){
            now=now*2;
            if(now>x){
                mark=i;
                break;
            }
        }
        for(int i=mark;i>=1;i--){
            long long now=(1LL<<i)-1;
            long long l=2,r=x;
            while(l+1<r){
                long long mid=(l+r)>>1;
                long long sum=0;
                for(int j=1;j<=i;j++){
                    if(sum>(x-1)/mid+1){
                        sum=x+1;
                        break;
                    }
                    sum=sum*mid+1;
                    if(sum>x)break;
                }
                if(sum>x)r=mid;
                else l=mid;
            }
            long long sum=0;
            for(int j=1;j<=i;j++){
                sum=sum*l+1;
            }
            if(sum==x){
                return to_string(l);
            }
        }
        return 0;
    }
};
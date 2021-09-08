class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int> >B;
    priority_queue<int,vector<int>,greater<int> >S;
    int numB=0,numS=0;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        numB=B.size();
        numS=S.size();
        if(numB+numS==0)B.push(num);
        else{
            if(num<=B.top())B.push(num);
            else S.push(num);
            if(B.size()>S.size()+1){
                int x=B.top();
                B.pop();
                S.push(x); 
            }
            if(S.size()>B.size()){
                int x=S.top();
                S.pop();
                B.push(x);
            }
        }
    }
    
    double findMedian() {
        numB=B.size();
        numS=S.size();
        if((numB+numS)%2==1){
            return (double)B.top();
        }
        double res=((double)B.top()+(double)S.top())/2;
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
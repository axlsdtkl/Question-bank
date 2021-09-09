/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        for(;;){
            int op=rand7();
            if(op>=1&&op<=3){
                for(;;){
                    int x=rand7();
                    if(x<=5)return x;
                }
            }else if(op>=4&&op<=6){
                for(;;){
                    int x=rand7();
                    if(x<=5)return x+5;
                }
            }
        }
    }
}
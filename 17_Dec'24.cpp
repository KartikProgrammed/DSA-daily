//50. Pow(x, n)
//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

//CODES:-
//APPROACH 1(Brute force-TLE):
class Solution {
public:
    double myPow(double x, int n) {
        double result=x;
        if(n==0){
            return 1;
        }
        if(n<0){
            result=1/x;
            while(n<-1){
                result=result*(1/x);
                n++;
            }
        }
        else{
            while(n>1){
                result=result*x;
                n--;
            }
        }
        return result;
    }
};

//APPROACH 2:-
class Solution {
public:
    double pow(double x,int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        double ans=pow(x,n/2);
        double ans2;
        if(n%2==0){
            ans2=(ans*ans);
        }
        else{
            ans2=(ans*ans*x);
        }
        return ans2;
    }
    double myPow(double x, int n) {
        double ans2=n>0?pow(x,n):1/pow(x,n);
        return ans2;
    }
};
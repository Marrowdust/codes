#include <iostream>
using namespace std;
int Power(int Number, int power){
    if(power==1){
        return Number;
    }
    if(Number%2==0){
        int X =Power(Number,power/2);       
        return X*X;                                
    }else
    {
        int Y=Number;
        int X=Power(Number,power/2);
        return X*X*Y;

    }
}
int main(){
int number=1000;
int power=2;
int PowerNUmber=Power(number,power);
cout<<PowerNUmber<<endl;
return 0;

}
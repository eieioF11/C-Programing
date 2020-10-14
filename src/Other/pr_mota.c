#include<mbed.h>
DigitalOut In1(IO19);
DigitalOut In2(IO18);

int main(){
    In1=0;
    In2=0;
    while(1){
        In1=1;
        wait(5);
        In1=0;
        wait(5);
    }
}

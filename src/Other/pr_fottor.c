#include<mbed_lib.h>
DigitalOut In1(GPIO_NUM_17);
DigitalIn Out2(GPIO_NUM_18);

extern"C"void app_main(){
    In1=0;
    while(1){
        In1=1;
        scanf("%d",&Out2);
        printf("%d,",Out2);
        wait(5);
        In1=0;
        scanf("%d",&Out2);
        printf("%d\n",Out2);
        wait(5);
    }
}

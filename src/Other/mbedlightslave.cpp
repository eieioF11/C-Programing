#include "mbed.h" 

#define SLAVE_ADR (0xf0<<1)//front adress
//#define SLAVE_ADR (0xb0<<1)//back adress

I2CSlave slave(dp5, dp27);  //(SDA,SCL)

Serial pc(USBTX,USBRX);

AnalogIn a0(dp4);
AnalogIn a1(dp9);
AnalogIn a2(dp10);
AnalogIn a3(dp11);
AnalogIn a4(dp13);

Timeout timer;//timer interrupt declaration
void retimer(){NVIC_SystemReset();/*reset*/}//interrupt handler

int main()
{
    pc.baud(115200);
    
    
    timer.attach(retimer/*interrupt handler*/,3/*time*/);//interrupt start
    
    slave.frequency(100000);
    slave.address(SLAVE_ADR);
    
    char data[6]= {0,0,0,0,0,0};
    char buf[1];buf[0]=0;
    short scount=0;
    
    while(1) 
    {
        int receivecheck = slave.receive();//受信確認
        switch (receivecheck) 
        {
            case I2CSlave::NoData:break;//データ無し
            case I2CSlave::ReadAddressed://マスターからのデータ送信要求
                timer.detach();//timer interrupt stop
                if(buf[0]==0)
                {
                    data[0] = (a0*1000)/(60/17);//40/17
                    data[1] = (a1*1000)/(60/17);
                    data[2] = (a2*1000)/(60/17);
                    data[3] = (a3*1000)/(60/17);
                    data[4] = (a4*1000)/(60/17);
                    for(int i=0; i<6; i++) 
                    {
                        if(data[i]>255)data[i]=255;
                        if(data[i]==0&&i!=5)data[i]=1;
                    }
                    data[5]=0;
                    scount=6;
                }
                else
                {
                    scount=0;
                    for(int i=0;i<6;i++)
                    {
                        if(buf[0]&1<<i)scount++;
                        switch((int)buf[0]&1<<i)
                        {
                            case 0b00001:data[scount-1]=(a0*1000)/(60/17);break;
                            case 0b00010:data[scount-1]=(a1*1000)/(60/17);break;
                            case 0b00100:data[scount-1]=(a2*1000)/(60/17);break;
                            case 0b01000:data[scount-1]=(a3*1000)/(60/17);break;
                            case 0b10000:data[scount-1]=(a4*1000)/(60/17);break;
                        }
                    }
                }
                slave.write(data,scount);
                break;
            case I2CSlave::WriteAddressed:slave.read(buf,1);break;//マスターからデータを受信
        }
        pc.printf("bin:%d,%d\r\n",buf[0],scount);
    }
}
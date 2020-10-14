#include <stdio.h>
#define red false
#define brue true
class Autoprocessing
{
	private:
        int count=0;
        int taskstatus=0;
        int times=0,told=0;
        bool tauto=false;
        const char *taskname[20];
        bool (*taskp[20])(void);
        void Setup();
        bool taskrun();
        void counter();
	public:
        bool stop=false;
        short line=0;
        bool ftype=brue;
        Autoprocessing();
        Autoprocessing(int Times);
        void reset();
        void setfunction(const char*name,bool (*taskp)(void),int tasknum);
        bool run();
        void selecttask(int statusnum);
        int statusread();
        const char *status();
        int read_ms();
        //int readcount();
};
Autoprocessing::Autoprocessing(){tauto=true;Setup();}
Autoprocessing::Autoprocessing(int Times){times=Times;Setup();}
void Autoprocessing::Setup()
{
}
void Autoprocessing::reset()
{
    count=0;
    taskstatus=0;
    tauto=false;
}
void Autoprocessing::setfunction(const char*name,bool (*tfp)(void),int tasknum)
{
    taskname[tasknum-1]=name;
    told=tasknum;
    taskp[tasknum-1]=tfp;
    if(tauto)times = (tasknum>told)?tasknum:told;
} 
void Autoprocessing::counter(){count++;}
bool Autoprocessing::taskrun()
{
    bool endcheck=false;
    if(endcheck==false){if(stop==false)endcheck=(*taskp[taskstatus])();}
    return endcheck;
}
bool Autoprocessing::run()
{
    bool end=false,endtask=false;
    if(taskstatus<times)endtask=taskrun();
    if(endtask)
    {
        if(taskstatus<times)taskstatus++;
        if(taskstatus==times)end=true;
    }
    return end;
}
void Autoprocessing::selecttask(int statusnum){taskstatus=statusnum-1;}
int Autoprocessing::statusread()
{
    if(times==taskstatus)return 0;
    else return taskstatus+1;
}
const char* Autoprocessing::status()
{
    const char* name=" ";
    if(times==taskstatus)name="all task end";
    else name=taskname[taskstatus];
    return name;
}
int Autoprocessing::read_ms(){return count;}
//int Autoprocessing::readcount(){return taskcount;}
/*
bool Autoprocessing::run()
{
    bool end=false,endtask=false;
    if(taskstatus<times)endtask=taskrun();
    else end=true;
    if(endtask)taskstatus++;
    else if(endtask==false&&taskstatus==0)taskstatus=times-1;
    if(end)taskcount++;
    return end;
}*/
int i=0;
bool Start()
{
    printf("start\n");
    return true;
}
bool funcA()
{
    printf("runfuncA!!\n");
    return true;
}
bool funcB()
{
    printf("runfuncB!!\n");
    return true;
}
bool funcC()
{
    printf("runfuncC!!\n");
    return true;
}
bool End()
{
    printf("runEnd!!\n");
    scanf("%d",&i);
    if(i!=0)return true;
    else return false;
}
Autoprocessing Auto;
int main()
{
    bool end=false;
    Auto.setfunction("start",Start,1);
    Auto.setfunction("funA",funcA,2);
    Auto.setfunction("funB",funcB,3);
    Auto.setfunction("funC",funcC,4);
    Auto.setfunction("end",End,5);
    while(true)
    {
        //=Auto.readcount();
        printf("task%d",Auto.statusread());
        printf("/%s\n",Auto.status());
        end = Auto.run();
        if(end)break;
    }
    printf("%s\n",Auto.status());
	return 0;
}

#ifndef PCB_H
#define PCB_H


class PCB
{
public:
    PCB();
    int pid;  //进程号
    int arriveTime;//到达时间
    int serviceTime;//服务时间
    int priority;//优先级
    int startTime;//开始运行时间
    int finishTime;//完成运行时间
    int waitTime;//等待时间
    float responseRatio;//相应比
    float turnaroundTime;//周转时间
    int state[20];//状态 1:就绪 2:执行 3:结束


};

#endif // PCB_H

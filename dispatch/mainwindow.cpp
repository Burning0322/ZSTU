#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include <QFileDialog>
#include <QTextStream>
#include <typeinfo>
#include <iostream>
#include <QDebug>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    //下拉框
    ui->comboBox->addItem("先来先服务");
    ui->comboBox->addItem("时间片轮转");
    ui->comboBox->addItem("短作业优先");
    ui->comboBox->addItem("静态优先权优先调度");
    ui->comboBox->addItem("高响应比调度");
    //表格
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"进程号"<<"进入时间"<<"服务时间"<<"优先级"<<"响应时间"<<"结束时间"<<"状态");

    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->label->setVisible(false);
    ui->timeEdit->setVisible(false);

//    测试数据
//    ui->tableWidget->setRowCount(2);
//    QStringList pidList;
//    pidList<<"124"<<"534"<<"267";
//    QStringList enterTime;
//    enterTime<<"0"<<"2"<<"3";
//    QStringList serveTime;
//    serveTime<<"3"<<"5"<<"1";
//    QStringList priority;
//    priority<<"3"<<"2"<<"1";



//    for(int i=0;i<2;i++){
//        int col = 0;
//        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(pidList[i]));
//        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(enterTime[i]));
//        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(serveTime[i]));
//        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(priority[i]));
//        ui->tableWidget->setItem(i,6,new QTableWidgetItem("就绪"));
//    }
//    //让tableWidget内容中的每个元素居中
//    for (int i=0;i<2;i++){
//        for (int j=0;j<4;j++){
//            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//        }

//    }
}

//初始化PCB
void MainWindow::initPcb()
{
    int rows = ui->tableWidget->rowCount();
    for(int i = 0;i<rows;i++)
    {
        pcbArr[i].pid = (ui->tableWidget->item(i,0)->text()).toInt();
        pcbArr[i].arriveTime = (ui->tableWidget->item(i,1)->text()).toInt();
        pcbArr[i].serviceTime = (ui->tableWidget->item(i,2)->text()).toInt();
        pcbArr[i].priority = (ui->tableWidget->item(i,3)->text()).toInt();
        memset(pcbArr[i].state,0,sizeof(pcbArr[i].state));
    }
}
//清除PCB
void MainWindow::clearPcb(int rows)
{
    for(int i = 0;i<rows;i++)
    {
        pcbArr[i].pid = -1;
        pcbArr[i].arriveTime = -1;
        pcbArr[i].serviceTime = -1;
        pcbArr[i].priority = -1;
        memset(pcbArr[i].state,0,sizeof(pcbArr[i].state));
    }
}
//对到达时间从小到大排序
void MainWindow::sort()
{
    int rows = ui->tableWidget->rowCount();
    for(int i=0;i<rows;i++){
        temp[i] = pcbArr[i];
        temp[i].startTime = -1;
    }
    int i,j;
    for(i = 1; i < rows; i++)
    {
        PCB t = temp[i];
        for(j = i - 1; j >= 0 && t.arriveTime < temp[j].arriveTime; j--)
        {
            temp[j+1] = temp[j];
        }
        temp[j+1] = t;
    }
}
//将pcb信息复制
void MainWindow::copyPcb()
{
    int rows = ui->tableWidget->rowCount();
    for(int a = 0;a<rows;a++)
    {
        for(int b = 0;b<rows;b++)
        {
            if(pcbArr[a].pid == temp[b].pid)
            {
                pcbArr[a].startTime = temp[b].startTime;
                pcbArr[a].finishTime = temp[b].finishTime;
                for(int i = 0;i<20;i++)
                {
                    pcbArr[a].state[i] = temp[b].state[i];

                }

                a++;
            }

        }
    }
}

//先来先服务
void MainWindow::fcfs()
{
    sort();
    int rows = ui->tableWidget->rowCount();
    int sum = 0;
    for(int k = 0;k<rows;k++)
    {
        if(k == 0)
        {
            temp[k].startTime = temp[k].arriveTime;
            temp[k].finishTime = temp[k].startTime + temp[k].serviceTime;
            temp[k].turnaroundTime = temp[k].finishTime - temp[k].arriveTime;
        }
        else
        {
            if(temp[k].arriveTime <= temp[k-1].finishTime)
            {
                temp[k].startTime = temp[k-1].finishTime;
            }
            else//第一个进程完成而第二个进程还未到达
            {
                temp[k].startTime = temp[k].arriveTime;
            }
            temp[k].finishTime = temp[k].startTime + temp[k].serviceTime;
            temp[k].turnaroundTime = temp[k].finishTime - temp[k].arriveTime;
        }
        sum += temp[k].turnaroundTime;
    }
    fcfsAverageTurnaroundTime = sum / rows;
    copyPcb();
}
//短作业优先
void MainWindow::sjf()
{
    sort();
    int rows = ui->tableWidget->rowCount();
    int current = temp[0].arriveTime;//当前时间等于第一个进程的到达时间

    int min_p,lastmin_p;
    int flag[rows];//标记进程是否执行结束
    int f = 0;//标记是否有上一次的下标
    for(int i = 0;i<rows;i++)
    {
        flag[i] = 0;
    }
    while(1)
    {
        int compare[rows];//用于存放当前已到达但并未结束进程的剩余服务时间
        for(int i = 0;i<rows;i++)
        {
            compare[i] = 0;
        }

        for(int i = 0;i<rows;i++)
        {
            if(temp[i].arriveTime <= current && flag[i] == 0)
            {
                compare[i] = temp[i].serviceTime;

            }
        }
        int min = 100;
        for(int i = 0;i<rows;i++)//找出当前进程最小剩余服务时间
        {
            if(compare[i] < min && compare[i] > 0)
            {
                min_p = i;//标记该进程
                min = compare[i];
            }
        }
        if(f == 1)
        {
            if((min_p != lastmin_p) && (temp[lastmin_p].state[current] != 3))//如果上一个进程被抢占
            {
                temp[lastmin_p].state[current] = 1;//就绪状态
            }
        }
        if(temp[min_p].startTime == -1)
        {
            temp[min_p].startTime = current;
        }
        temp[min_p].serviceTime--;
        temp[min_p].state[current] = 2;//执行状态
        current++;
        if(temp[min_p].serviceTime == 0)//判断当前进程是否结束
        {
            flag[min_p] = 1;
            temp[min_p].finishTime = current;
            temp[min_p].state[current] = 3;//结束状态
        }
        if(temp[min_p].serviceTime < 0)//判断所有进程是否结束
        {
            break;
        }
        lastmin_p = min_p;
        f = 1;
    }
    int sum = 0;
    for(int i = 0;i<rows;i++)
    {
        temp[i].turnaroundTime = temp[i].finishTime - temp[i].arriveTime;
        sum += temp[i].turnaroundTime;
    }
    sjfAverageTurnaroundTime = sum / rows;
    copyPcb();
}
//时间片轮转
void MainWindow::rr()
{
    sort();
    int time;
    time = (ui->timeEdit->text()).toInt();
    int rows = ui->tableWidget->rowCount();
    int curNum;
    int f;
    int current = temp[0].arriveTime;//当前时间等于第一个进程的到达时间
    int flag[rows];//标记进程是否执行结束
    for(int j = 0;j<rows;j++)
    {
        flag[j] = 0;
    }
    while(1)
    {
        f = 0;
        for(int i = 0; i<rows; i++)
        {

            if(temp[i].startTime == -1)
            {
                temp[i].startTime = current;
            }
            if(temp[i].serviceTime <= time && flag[i] == 0)//时间片内可以执行完毕
            {
                temp[i].state[current] = 2;//执行状态
                current += temp[i].serviceTime;
                temp[i].finishTime = current;
                temp[i].state[current] = 3;//结束状态
                flag[i] = 1;

            }
            curNum = 0;
            if(temp[i].serviceTime > time && flag[i] == 0)//时间片内不能执行完毕
            {   //cout<<i<<endl;
                temp[i].state[current] = 2;//执行状态
                current += time;
                temp[i].serviceTime -= time;
                for(int j = 0 ;j<rows;j++)
                {
                    if(temp[j].arriveTime <= current)
                    {
                        curNum++;
                    }
                }
                if(i+1 == curNum && curNum <rows)//如果还有未到达的进程
                {
                    i = -1;//重回第一个进程，因为for循环后要++因此i=-1即为ℹ=0
                }
                else
                {
                    temp[i].state[current] = 1;//被抢占后变为就绪状态
                    //cout << i<<current<<endl;

                }
            }
        }
        for(int i = 0;i<rows;i++)
        {
            if(flag[i] == 0 && f == 0)//所有进程未完成置f为1
            {
                f = 1;
            }
        }
        if(f == 0)
        {
            break;
        }
    }
    int sum = 0;
    for(int i = 0;i<rows;i++)
    {
        temp[i].turnaroundTime = temp[i].finishTime - temp[i].arriveTime;
        sum += temp[i].turnaroundTime;
    }
    rrAverageTurnaroundTime = sum / rows;
    copyPcb();



}
//静态优先权优先调度
void MainWindow::pf()
{
    sort();
    int rows = ui->tableWidget->rowCount();
    int current = temp[0].arriveTime;//当前时间等于第一个进程的到达时间

    int min_p,lastmin_p;
    int flag[rows];//标记进程是否执行结束
    for(int i = 0;i<rows;i++)
    {
        flag[i] = 0;
    }
    int f = 0;//标记是否有上一次的下标
    while(1)
    {
        int compare[rows];
        for(int i = 0;i<rows;i++)
        {
            compare[i] = 0;
        }

        for(int i = 0;i<rows;i++)
        {
            if(temp[i].arriveTime <= current && flag[i] == 0)//将当前时间已到达且未完成的进程的优先级存入数组
            {
                compare[i] = temp[i].priority;

            }
        }
        int min = 100;
        for(int i = 0;i<rows;i++)//默认数值越小优先级越高
        {
            if(compare[i] < min && compare[i] > 0)
            {
                min_p = i;
                min = compare[i];//找出当前优先级最高的进程的下标和优先级
            }
        }
        if(f == 1)
        {
            if((min_p != lastmin_p) && (temp[lastmin_p].state[current] != 3))//如果上一个进程被抢占
            {
                temp[lastmin_p].state[current] = 1;//就绪状态
            }
        }
        if(temp[min_p].startTime == -1)
        {
            temp[min_p].startTime = current;
        }
        temp[min_p].state[current] = 2;//执行状态
        temp[min_p].serviceTime--;
        current++;
        if(temp[min_p].serviceTime == 0)
        {
            flag[min_p] = 1;
            temp[min_p].finishTime = current;
            temp[min_p].state[current] = 3;//结束状态
        }
        if(temp[min_p].serviceTime < 0)
        {
            break;
        }
        lastmin_p = min_p;//保留当前下标
        f = 1;
    }
    int sum = 0;
    for(int i = 0;i<rows;i++)
    {
        temp[i].turnaroundTime = temp[i].finishTime - temp[i].arriveTime;
        sum += temp[i].turnaroundTime;
    }
    pfAverageTurnaroundTime = sum / rows;
    copyPcb();
}
//高响应比调度
//等待时间=上一个的完成时间-该作业到达的时刻
//响应比=（等待时间+服务时间）/服务时间=等待时间/服务时间+1
void MainWindow::hrrn()
{
    sort();
    int rows = ui->tableWidget->rowCount();
    int run_p = 0;
    int last_p = 0;

    int flag[rows];//标记进程是否执行结束
    for(int i = 0;i<rows;i++)
    {
        flag[i] = 0;
    }
    while(1)
    {
        if(run_p == 0)
        {
            temp[0].startTime = temp[0].arriveTime;
            temp[0].finishTime = temp[0].startTime + temp[0].serviceTime;
            flag[0] = 1;
        }
        int f = 0;
        int compare[rows];
        for(int i = 0;i<rows;i++)
        {
            compare[i] = 0;
        }
        for(int i = 1;i<rows;i++)
        {
            if(flag[i] == 0)
            {
                temp[i].waitTime = temp[last_p].finishTime - temp[i].arriveTime;
                temp[i].responseRatio = (temp[i].waitTime/temp[i].serviceTime)+1;
                compare[i] = temp[i].responseRatio;
            }
        }
        float maxRatio = 0;
        for(int i = 1;i<rows;i++)
        {
            if(compare[i] > maxRatio)
            {
                run_p = i;
                maxRatio = compare[i];
            }
        }
        temp[run_p].startTime = temp[last_p].finishTime;
        temp[run_p].finishTime = temp[run_p].startTime + temp[run_p].serviceTime;
        flag[run_p] = 1;
        last_p = run_p;
        for(int i = 0;i<rows;i++)
        {
            if(flag[i] == 0 && f == 0)
            {
                f = 1;
            }
        }
        if(f == 0)
        {
            break;
        }
    }
    int sum = 0;
    for(int i = 0;i<rows;i++)
    {
        temp[i].turnaroundTime = temp[i].finishTime - temp[i].arriveTime;
        sum += temp[i].turnaroundTime;
    }
    hrrnAverageTurnaroundTime = sum / rows;
    copyPcb();
}
//手动添加进程
void MainWindow::on_addButton_clicked()
{
    int rows = ui->tableWidget->rowCount();

    ui->tableWidget->insertRow(rows);
    for(int i=0;i<4;i++){
        ui->tableWidget->setItem(rows,i,new QTableWidgetItem("0"));
    }
    ui->tableWidget->setItem(rows,6,new QTableWidgetItem(" "));
    ui->tableWidget->selectRow(rows);
//    for (int j=0;j<4;j++){
//        ui->tableWidget->item(rows,j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//    }
}
//开始
void MainWindow::on_startButton_clicked()
{
    initPcb();
    if(ui->tableWidget->rowCount() == 0)//如果表格无数据
    {
        QMessageBox msg;
        msg.setText("请添加数据！");
        msg.exec();
        return;
    }
    second = 0;
    if(ui->comboBox->currentText() == "先来先服务")
    {
        fcfs();
    }
    if(ui->comboBox->currentText() == "短作业优先")
    {
        sjf();
    }
    if(ui->comboBox->currentText() == "时间片轮转")
    {
        rr();
    }
    if(ui->comboBox->currentText() == "静态优先权优先调度")
    {
        pf();
    }
    if(ui->comboBox->currentText() == "高响应比调度")
    {
        hrrn();
    }
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    timer->start(1000);
}

//动态更新表格数据
void MainWindow::updateTime()
{
    int rows = ui->tableWidget->rowCount();
    ui->timer->setText(QString::number(second));
    for(int i = 0;i<rows;i++)
    {
        if(second < pcbArr[i].startTime && second >= pcbArr[i].arriveTime)
        {
            ui->tableWidget->setItem(i,6,new QTableWidgetItem("就绪"));
        }
        if(pcbArr[i].state[second] == 1)
        {
            ui->tableWidget->setItem(i,6,new QTableWidgetItem("等待"));
        }
        if(pcbArr[i].state[second] == 2)
        {
            ui->tableWidget->setItem(i,6,new QTableWidgetItem("执行"));
        }
        if(second == pcbArr[i].startTime)
        {
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(pcbArr[i].startTime)));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem("执行"));
            //ui->tableWidget->item(i,4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
        if(second == pcbArr[i].finishTime)
        {
            ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(pcbArr[i].finishTime)));
            ui->tableWidget->setItem(i,6,new QTableWidgetItem("结束"));
            //ui->tableWidget->item(i,5)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        }
    }

    //当所有进程结束时，定时器关闭
    int flag = rows;
    for(int j = 0;j<rows;j++)
    { 
        if((ui->tableWidget->item(j,6)->text()) == "结束")
        {
            flag--;
        }
    }
    if(flag == 0)
    {
        if(ui->comboBox->currentText() == "先来先服务")
        {
            ui->fcsfEdit->setText(QString::number(fcfsAverageTurnaroundTime));
        }
        if(ui->comboBox->currentText() == "短作业优先")
        {
            ui->sjfEdit->setText(QString::number(sjfAverageTurnaroundTime));
        }
        if(ui->comboBox->currentText() == "时间片轮转")
        {
            ui->rrEdit->setText(QString::number(rrAverageTurnaroundTime));
        }
        if(ui->comboBox->currentText() == "静态优先权优先调度")
        {
            ui->pfEdit->setText(QString::number(pfAverageTurnaroundTime));
        }
        if(ui->comboBox->currentText() == "高响应比调度")
        {
            ui->hrrnEdit->setText(QString::number(hrrnAverageTurnaroundTime));
        }
        timer->stop();
        delete timer;
    }
    else
    {
        second++;
    }
}


//删除表格所有行
void MainWindow::on_clearButton_clicked()
{
    int rows = ui->tableWidget->rowCount();
    clearPcb(rows);
    for(int i = 0;i<rows;i++)
    {
        ui->tableWidget->removeRow(0);
    }
    ui->timer->setText(QString::number(0));
    ui->fcsfEdit->setText("");
    ui->sjfEdit->setText("");
    ui->rrEdit->setText("");
    ui->pfEdit->setText("");
    ui->hrrnEdit->setText("");
}
//更换选项清空上一次结果
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int rows = ui->tableWidget->rowCount();
    switch(index)
    {
        case 1:
            ui->label->setVisible(true);
            ui->timeEdit->setVisible(true);
            for(int i = 0;i<rows;i++)
            {
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(""));
                ui->tableWidget->setItem(i,5,new QTableWidgetItem(""));
                ui->tableWidget->setItem(i,6,new QTableWidgetItem(""));
            }
            break;
        default:
            ui->label->setVisible(false);
            ui->timeEdit->setVisible(false);
            for(int i = 0;i<rows;i++)
            {
                ui->tableWidget->setItem(i,4,new QTableWidgetItem(""));
                ui->tableWidget->setItem(i,5,new QTableWidgetItem(""));
                ui->tableWidget->setItem(i,6,new QTableWidgetItem(""));
            }

            break;
    }
}

void MainWindow::on_fileButton_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,tr("open file"),"",tr("text(*.txt)"));
    if(!fileName.isEmpty())
    {
        QFile file;
        file.setFileName(fileName);
        //打开文件
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox msg;
            msg.setText("打开文件失败!");
            msg.exec();
        }
        else
        {
            if(!file.size())
            {
                QMessageBox::warning(0,tr("警告"),tr("文件大小为空!"),QMessageBox::Ok);
            }
            else
            {
                //将文件数据导入表格
                int r_count = 0;        //统计文件的行数
                QStringList textList;   //记录文件中每一行的数据
                QTextStream in(&file);
                while (!in.atEnd())
                {
                    QString line = in.readLine();
                    textList.append(line);          //保存文件的数据
                    r_count++;                      //记录文件的行数
                }
                file.close();       //关闭文件
                if(!textList.isEmpty())
                {
                    ui->tableWidget->setRowCount(r_count);
                    for(int row = 0; row < r_count; row++)
                    {
                        QStringList tmpList;
                        tmpList = textList.at(row).split(" ");
                        for(int col = 0; col < 4; col++)
                        {
                            QTableWidgetItem *item = new QTableWidgetItem(tmpList.at(col));
                            ui->tableWidget->setItem(row, col, item);
                        }
                        ui->tableWidget->setItem(row,6,new QTableWidgetItem(" "));
                    }
                }
            }
        }
    }

}

#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    //初始化变量
    int BombNum = 0;//玩家输入的循环次数变量
    int num = 0;//循环引用的变量
    int MessageStop = 0;//记录发出的消息数量
    int stopNum = 0;//记录停止的次数
    int start = 0;//是否继续变量

    while (start == 0) 
    {
        //询问要循环的次数
        printf("注意，在使用的时候请确保Discord已全屏化并且已打开私信\n");
        printf("请输入循环的次数:\n");
        scanf_s("%d", &BombNum);

        //如果循环时间将大于50个的话就警告
        if (BombNum >= 50)
        {
            printf("注意！超过50次的刷屏消息送出可能会导致“发送过快”的提示出现\n");
            printf("是否继续？\n");
            printf("0.否   1.是\n");
            scanf_s("%d", &start);

            //判断选择
            if (start == 1) { break; }

            else if (start == 0) {
            printf("\n");
            continue;
                    
                }
            }
            //如果循环次数并非整数
            else if (BombNum <= 0) {
                printf("\n");
                printf("注意：请输入整数\n");
                continue;
            }
            //完全没有问题就直接开始
            else
            {
                start = 1;
                break;
            }
    }

        //准备
        //设置光标位置为 (x, y) 坐标
        int x = 700; // 设置 x 坐标
        int y = 815; // 设置 y 坐标
        SetCursorPos(x, y);
        //模拟鼠标点击
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        //现在已经选中对话框了

        num = BombNum;
        for (int i = 0; i < num;i++)
        {
            // 粘贴
            keybd_event(VK_CONTROL, 0, 0, 0);
            keybd_event('V', 0, 0, 0);

            keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

            Sleep(100);//等待0.1秒

            //回车发送
            keybd_event(VK_RETURN, 0, 0, 0);
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

            Sleep(100);//等待0.1秒

            //为了避免出现“消息发送过快”而设置的冷却
            MessageStop++;
            if (num != 10 && MessageStop == 10) {
                printf("已暂停\n");
                Sleep(5000);//停止5秒
                stopNum++;
                printf("已继续 暂停次数：%d\n",stopNum);
                MessageStop = 0;
            }
        }
    return 0;
}
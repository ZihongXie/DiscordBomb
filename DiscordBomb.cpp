#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    //��ʼ������
    int BombNum = 0;//��������ѭ����������
    int num = 0;//ѭ�����õı���
    int MessageStop = 0;//��¼��������Ϣ����
    int stopNum = 0;//��¼ֹͣ�Ĵ���
    int start = 0;//�Ƿ��������

    while (start == 0) 
    {
        //ѯ��Ҫѭ���Ĵ���
        printf("ע�⣬��ʹ�õ�ʱ����ȷ��Discord��ȫ���������Ѵ�˽��\n");
        printf("������ѭ���Ĵ���:\n");
        scanf_s("%d", &BombNum);

        //���ѭ��ʱ�佫����50���Ļ��;���
        if (BombNum >= 50)
        {
            printf("ע�⣡����50�ε�ˢ����Ϣ�ͳ����ܻᵼ�¡����͹��족����ʾ����\n");
            printf("�Ƿ������\n");
            printf("0.��   1.��\n");
            scanf_s("%d", &start);

            //�ж�ѡ��
            if (start == 1) { break; }

            else if (start == 0) {
            printf("\n");
            continue;
                    
                }
            }
            //���ѭ��������������
            else if (BombNum <= 0) {
                printf("\n");
                printf("ע�⣺����������\n");
                continue;
            }
            //��ȫû�������ֱ�ӿ�ʼ
            else
            {
                start = 1;
                break;
            }
    }

        //׼��
        //���ù��λ��Ϊ (x, y) ����
        int x = 700; // ���� x ����
        int y = 815; // ���� y ����
        SetCursorPos(x, y);
        //ģ�������
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        //�����Ѿ�ѡ�жԻ�����

        num = BombNum;
        for (int i = 0; i < num;i++)
        {
            // ճ��
            keybd_event(VK_CONTROL, 0, 0, 0);
            keybd_event('V', 0, 0, 0);

            keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

            Sleep(100);//�ȴ�0.1��

            //�س�����
            keybd_event(VK_RETURN, 0, 0, 0);
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

            Sleep(100);//�ȴ�0.1��

            //Ϊ�˱�����֡���Ϣ���͹��족�����õ���ȴ
            MessageStop++;
            if (num != 10 && MessageStop == 10) {
                printf("����ͣ\n");
                Sleep(5000);//ֹͣ5��
                stopNum++;
                printf("�Ѽ��� ��ͣ������%d\n",stopNum);
                MessageStop = 0;
            }
        }
    return 0;
}
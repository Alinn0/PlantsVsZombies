
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "Getpid.hpp" 


int addbase1 = 0;
int addbase2 = 0;
int sun = 9999;
int B = 0;
int C = 0;
int shoot;
int head = 0x6A9EC0;
DWORD PID = getpid("MainWindow", "植物大战僵尸中文版");
HANDLE Process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
BYTE cd_on[7] = { 0xE9,0x63,0xF1,0x3C,0x10,0x66,0x90 };
BYTE cd_on1[15] = { 0x81,0x47,0x24,0x88,0x13,0x00,0x00,0x8B,0x47,0x24,0xE9,0x90,0x0E,0xC3,0xEF };
BYTE cd_off[7] = { 0x83,0x47,0x24,0x01,0x8B,0x47,0x24 };
BYTE shoot_on[10] = { 0x0F ,0x84 ,0x98 ,0xFE ,0xFF ,0xFF ,0x83 ,0xF8 ,0x12 ,0x0F };
BYTE shoot_off[10] = { 0x0F ,0x85 ,0x98 ,0xFE ,0xFF ,0xFF ,0x83 ,0xF8 ,0x12 ,0x0F };




void CD_ON()
{
    WriteProcessMemory(Process_handle, (void*)(0x0048728C), cd_on, 7, 0);
    WriteProcessMemory(Process_handle, (void*)(0x108563F4), cd_on1, 15, 0);
    printf("卡槽冷却已开启\n");
};

void CD_OFF()
{
    WriteProcessMemory(Process_handle, (void*)(0x0048728C), cd_off, 7, 0);
    printf("卡槽冷却已关闭\n");
};

void Shoot_ON()
{
    WriteProcessMemory(Process_handle, (void*)(0x464A96), shoot_on, 10, 0);
    printf("连发已开启\n");
};

void Shoot_OFF()
{
    WriteProcessMemory(Process_handle, (void*)(0x464A96), shoot_off, 10, 0);
    printf("连发已关闭\n");
};


void SUM()
{
    ReadProcessMemory(Process_handle, (void*)(head), &addbase1, 4, 0);
    ReadProcessMemory(Process_handle, (void*)(addbase1 + 0x768), &addbase2, 4, 0);
    WriteProcessMemory(Process_handle, (void*)(addbase2 + 0x5560), &sun, 4, 0);
    printf("阳光已设置为9999.....\n");
};

int main()
{

    while (1)
    {

        printf("请选择：\n1:卡槽冷却\n2:增加阳光\n3.开启连发\n");
        scanf_s("%d", &B);
        switch (B)
        {
        case 1:
            printf("请选择：\n1:开启\n2:关闭\n");
            scanf_s("%d", &C);
            switch (C)
            {
            case 1:
                CD_ON();
                break;
            case 2:
                CD_OFF();
                break;
            default:
                printf("输入错误\n");
                break;
            }
            break;
        case 2:
            SUM();
            break;
        case 3:
            printf("请选择：\n1:开启\n2:关闭\n");
            scanf_s("%d", &shoot);
            switch (shoot)
            {
            case 1:
                Shoot_ON();
                break;
            case 2:
                Shoot_OFF();
                break;
            default:
                printf("输入错误\n");
                break;
            }
            break;
        default:
            printf("敬请期待\n");
            break;
        }


    }




}

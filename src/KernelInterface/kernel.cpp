#include "include/KernelInterface/kernel.h"
#include "include/kma/driver.h"
#include <cstdio>
#include <stdlib.h>

int choice = 0;
int KMA_choice = 0;

KernelDriver::KernelDriver(/* args */)
{
    printf("\033[31m************************************************\n");
    printf("\033[37;1;90m");
    printf("---驱动选择---\n");
    printf("1. KMA(KPM)\n");
    printf("2. 测试\n");
    printf("3. 测试\n");
    printf("4. 测试\n");
    printf("\033[31m************************************************");
    printf("\n请输入你的选择(1-4):");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("已选择 KMA 驱动\n\n");
        printf("\033[31m************************************************\n");
        printf("\033[37;1;90m");
        printf("---KMA驱动读写方式---\n");
        printf("1. 硬件级\n");
        printf("2. 内核层\n");
        printf("\033[31m************************************************");
        printf("\n请输入你的选择(1-2):");
        scanf("%d", &KMA_choice);

        if (KMA_choice != 1 && KMA_choice != 2)
        {
            printf("无效选择\n");
        }
        break;
    case 2:
        printf("测试中...\n");
        break;
    case 3:
        printf("测试中...\n");
        break;
    case 4:
        printf("测试中...\n");
        break;
    default:
        printf("无效选择\n");
    }
}

KernelDriver::~KernelDriver()
{
}

bool KernelDriver::read(uintptr_t addr, void *buffer, size_t size)
{
    switch (choice)
    {
    case 1:
    {
        Driver *driver = new Driver();
        if (KMA_choice == 1)
        {
            // 硬件级读取
            return driver->read_safe(addr, buffer, size);
        }
        else if (KMA_choice == 2)
        {
            // 内核层读取
            return driver->read(addr, buffer, size);
        }
        break;
    }
    case 2:
        // 测试中...
        return false;
        break;
    case 3:
        // 测试中...
        return false;
        break;
    case 4:
        // 测试中...
        return false;
        break;
    default:
        return false;
    }
}

bool KernelDriver::write(uintptr_t addr, void *buffer, size_t size)
{
    switch (choice)
    {
    case 1:
    {
        Driver *driver = new Driver();
        return driver->write(addr, buffer, size);
        break;
    }
    case 2:
        // 测试中...
        return false;
        break;
    case 3:
        // 测试中...
        return false;
        break;
    case 4:
        // 测试中...
        return false;
        break;
    default:
        return false;
    }
}
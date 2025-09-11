#include "kernel.h"
#include <cstdio>

// 全局变量定义（只能在一个 .cpp 里定义一次）
int choice = 0;
int KMA_choice = 0;
float px, py;
Driver *driver = nullptr;
pid_t pid = 0;

// ---------------- Vector3 ----------------
Vector3::Vector3() {
    this->X = 0;
    this->Z = 0;
    this->Y = 0;
}

Vector3::Vector3(float x, float z, float y) {
    this->X = x;
    this->Z = z;
    this->Y = y;
}

// ---------------- 驱动选择 ----------------
bool KernelDriver(/* args */) {
    printf("\033[1;31m************************************************\033[0m\n");
    printf("\033[1;36m---驱动选择---\033[0m\n");
    printf("\033[0;37m1. KMA(KPM)\033[0m\n");
    printf("\033[0;37m2. 测试\033[0m\n");
    printf("\033[0;37m3. 测试\033[0m\n");
    printf("\033[0;37m4. 测试\033[0m\n");
    printf("\033[1;31m************************************************\033[0m\n");
    printf("\033[1;35m请输入你的选择(1-4): \033[0m");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            driver = new Driver();
            if (driver->initpid(0)) {
                printf("\033[1;32mKernel driver initialized\033[0m\n");
            } else {
                printf("\033[1;33mKernel driver uninitialized\033[0m\n");
            }

            printf("\033[1;31m************************************************\033[0m\n");
            printf("\033[1;36m---KMA驱动读写方式---\033[0m\n");
            printf("\033[0;37m1. 硬件级(仅支持QGKI、GKI2.0+)\033[0m\n");
            printf("\033[0;37m2. 内核层(多兼容)\033[0m\n");
            printf("\033[1;31m************************************************\033[0m\n");
            printf("\033[1;35m请输入你的选择(1-2): \033[0m");
            scanf("%d", &KMA_choice);

            if (KMA_choice != 1 && KMA_choice != 2) {
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
    return true;
}

// ---------------- 初始化 pid ----------------
bool initpid(pid_t pid) {
    switch (choice) {
        case 1: {
            return driver->initpid(pid);
        }
        case 2:
            // 测试中...
            return false;
        case 3:
            // 测试中...
            return false;
        case 4:
            // 测试中...
            return false;
        default:
            return false;
    }
}

// ---------------- 获取 pid ----------------
pid_t get_pid(char *name) {
    switch (choice) {
        case 1: {
            return driver->get_pid(name);
        }
        case 2:
            // 测试中...
            return -1;
        case 3:
            // 测试中...
            return -1;
        case 4:
            // 测试中...
            return -1;
        default:
            return -1;
    }
}

// ---------------- 获取 pid（返回 int） ----------------
int getPID(char *name) {
    return get_pid(name);
}

// ---------------- 获取模块基址 ----------------
uintptr_t getModuleBase(char *module_name) {
    switch (choice) {
        case 1: {
            return driver->get_module_base(driver->get_pid("com.tencent.tmgp.sgame"), module_name);
        }
        case 2:
            // 测试中...
            return 0;
        case 3:
            // 测试中...
            return 0;
        case 4:
            // 测试中...
            return 0;
        default:
            return 0;
    }
}

// ---------------- 读内存 ----------------
bool read(uintptr_t addr, void *buffer, size_t size) {
    switch (choice) {
        case 1: {
            if (KMA_choice == 1) {
                // 硬件级读取
                return driver->read_safe(addr, buffer, size);
            } else if (KMA_choice == 2) {
                // 内核层读取
                return driver->read(addr, buffer, size);
            }
            return false;
        }
        case 2:
            // 测试中...
            return false;
        case 3:
            // 测试中...
            return false;
        case 4:
            // 测试中...
            return false;
        default:
            return false;
    }
}

// ---------------- 写内存 ----------------
bool write(uintptr_t addr, void *buffer, size_t size) {
    switch (choice) {
        case 1: {
            return driver->write(addr, buffer, size);
        }
        case 2:
            // 测试中...
            return false;
        case 3:
            // 测试中...
            return false;
        case 4:
            // 测试中...
            return false;
        default:
            return false;
    }
}

// ---------------- 模板读（泛型） ----------------
template <typename T>
T read(uintptr_t addr) {
    return driver->read<T>(addr);
}
// 显式实例化需要的类型
template int read<int>(uintptr_t addr);
template float read<float>(uintptr_t addr);
template long read<long>(uintptr_t addr);
template uintptr_t read<uintptr_t>(uintptr_t addr);

// ---------------- 工具函数 ----------------
long ReadValue(long addr) {
    return read<uintptr_t>(addr);
}

long ReadDword(long addr) {
    return read<uintptr_t>(addr);
}

float ReadFloat(long addr) {
    return read<uintptr_t>(addr);
}

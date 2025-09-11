#pragma once
#include <sys/types.h>
#include "driver.h"

// 全局变量声明
extern int choice;
extern int KMA_choice;
extern float px, py;
extern Driver *driver;
extern pid_t pid;

// 定义一个xzy形式的坐标(因为u3d是xzy)
struct Vector3 {
    float X;
    float Z;
    float Y;

    Vector3();
    Vector3(float x, float z, float y);
};

// 函数声明
bool KernelDriver();
bool initpid(pid_t pid);
pid_t get_pid(char *name);
int getPID(char *name);
uintptr_t getModuleBase(char *module_name);
bool read(uintptr_t addr, void *buffer, size_t size);
bool write(uintptr_t addr, void *buffer, size_t size);

// 模板函数声明
template <typename T> T read(uintptr_t addr);

// 工具函数声明
long ReadValue(long addr);
long ReadDword(long addr);
float ReadFloat(long addr);

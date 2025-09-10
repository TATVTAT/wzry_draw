#include <cstdint>


class KernelDriver
{
private:
    /* data */
public:
    KernelDriver(/* args */);
    ~KernelDriver();

    bool read(uintptr_t addr, void *buffer, size_t size);

    bool write(uintptr_t addr, void *buffer, size_t size);
};
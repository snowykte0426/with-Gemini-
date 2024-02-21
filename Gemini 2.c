#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>

typedef struct _SYSTEM_PROCESSOR_INFO {
    DWORD dwProcessorType;
    DWORD dwProcessorLevel;
    DWORD dwProcessorRevision;
    DWORD dwNumberOfCores;
    DWORD dwNumberOfProcessors;
    DWORD dwNumberOfLogicalProcessors;
    DWORD dwProcessorArchitecture;
    DWORD dwProcessorManufacturer;
    DWORD dwProcessorId;
    DWORD dwProcessorStepping;
    // DWORD lpProcessorInfo; // Not used on Windows Vista or later
    LPVOID lpProcessorFeatures;
} SYSTEM_PROCESSOR_INFO;

void print_cpu_info() {
    SYSTEM_PROCESSOR_INFO si;
    GetSystemInfo(&si);

    SYSTEM_PROCESSOR_INFO* cpuInfo = &si; // No need for separate pointer

    printf("CPU 이름: %s\n", cpuInfo->lpProcessorFeatures);
    printf("CPU 코어 수: %d\n", si.dwNumberOfProcessors);
    printf("CPU 쓰레드 수: %d\n", si.dwNumberOfLogicalProcessors);
}

void print_storage_info() {
    // TODO: Implement Windows storage info retrieval and display
}

void print_memory_info() {
    MEMORYSTATUSEX mem_status;
    GlobalMemoryStatusEx(&mem_status);

    printf("시스템 메모리 용량: %llu GB\n", mem_status.ullTotalPhys / (1024 * 1024 * 1024));
}

void print_mainboard_info() {
    // TODO: Implement Windows motherboard info retrieval and display
}

void print_gpu_info() {
    // TODO: Implement Windows GPU info retrieval and display
}

int main() {
    
    SYSTEM_INFO si;
    GetSystemInfo(&si);

    SYSTEM_PROCESSOR_INFO* cpuInfo = &si; // No need for separate pointer

    printf("CPU 이름: %s\n", cpuInfo->lpProcessorFeatures);
    printf("CPU 코어 수: %d\n", si.dwNumberOfProcessors);
   
    // TODO: Implement Windows storage info retrieval and display
    MEMORYSTATUSEX mem_status;
    GlobalMemoryStatusEx(&mem_status);

    printf("시스템 메모리 용량: %llu GB\n", mem_status.ullTotalPhys / (1024 * 1024 * 1024));
    // TODO: Implement Windows motherboard info retrieval and display
    // TODO: Implement Windows GPU info retrieval and display

    return 0;
}
#else
// TODO: Implement Linux
#endif

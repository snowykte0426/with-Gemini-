#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#ifdef _WIN32_WINNT
#if _WIN32_WINNT >= 0x0600
#define PROCESSOR_CLOCK_SPEED_SUPPORTED 1
#endif
#endif

// CPU ���� ��� �Լ�
void PrintCPUInfo() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);

    printf("CPU ��: %s\n", si.dwProcessorType);
    printf("CPU �ھ� ��: %d\n", si.dwNumberOfProcessors);
/*
#ifdef PROCESSOR_CLOCK_SPEED_SUPPORTED
    printf("CPU Ŭ�� �ӵ�: %.2f GHz\n", si.dwProcessorClockSpeed / 1000.0);
#else
    printf("CPU Ŭ�� �ӵ�: %.2f GHz\n", si.dwProcessorSpeed / 1000.0);
#endif

    // ���μ��� �۵� �ð� ���
    DWORDLONG uptime;
    LPFILETIME uptime_ptr; // ���� ����

    uptime_ptr = &uptime;

    if (!GetSystemTimePreciseAsFileTime(uptime_ptr)) {
        printf("GetSystemTimePreciseAsFileTime �Լ� ȣ�� ����\n");
        return 1;
    }

    if (uptime->dwHighDateTime == 0 && uptime->dwLowDateTime == 0) {
        printf("uptime ���� �� ����\n");
        return 1;*/
    }
/*
    // 100������ ������ �� ������ ��ȯ
    uptime /= 10000000;

    // �ð� ���
    DWORD hours = uptime->dwHighDateTime * 3600 + uptime->dwLowDateTime / 3600000000;
    DWORD minutes = (uptime->dwLowDateTime % 3600000000) / 600000000;
    DWORD seconds = (uptime->dwLowDateTime % 600000000) / 10000000;

    // �ð� �� ���� Ȯ��
    if (hours >= 24) {
        printf("�ð� �� ����: %d�ð�\n", hours);
        return 1;
    }

    printf("���μ��� �۵� �ð�: %d�ð� %d�� %d��\n", hours, minutes, seconds);
}*/

// �ý��� �޸� ���� ��� �Լ�
void PrintMemoryInfo() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    GlobalMemoryStatusEx(&memInfo);

    printf("�� �ý��� �޸�: %.2f GB\n", memInfo.ullTotalPhys / 1073741824.0);
    printf("��� ������ �ý��� �޸�: %.2f GB\n", memInfo.ullAvailPhys / 1073741824.0);
}

// ���� ��ġ ���� ��� �Լ�
void PrintStorageInfo() {
    ULARGE_INTEGER totalBytes, freeBytes, availableBytes;

    GetDiskFreeSpaceExW(L"C:\\", &freeBytes, &totalBytes, &availableBytes);

    printf("�� ���� ����: %.2f GB\n", totalBytes.QuadPart / 1073741824.0);
    printf("��� ������ ���� ����: %.2f GB\n", freeBytes.QuadPart / 1073741824.0);
}

int main() {
    PrintCPUInfo();
    PrintMemoryInfo();
    PrintStorageInfo();

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#ifdef _WIN32_WINNT
#if _WIN32_WINNT >= 0x0600
#define PROCESSOR_CLOCK_SPEED_SUPPORTED 1
#endif
#endif

// CPU 정보 출력 함수
void PrintCPUInfo() {
    SYSTEM_INFO si;
    GetSystemInfo(&si);

    printf("CPU 모델: %s\n", si.dwProcessorType);
    printf("CPU 코어 수: %d\n", si.dwNumberOfProcessors);
/*
#ifdef PROCESSOR_CLOCK_SPEED_SUPPORTED
    printf("CPU 클럭 속도: %.2f GHz\n", si.dwProcessorClockSpeed / 1000.0);
#else
    printf("CPU 클럭 속도: %.2f GHz\n", si.dwProcessorSpeed / 1000.0);
#endif

    // 프로세서 작동 시간 출력
    DWORDLONG uptime;
    LPFILETIME uptime_ptr; // 변수 선언

    uptime_ptr = &uptime;

    if (!GetSystemTimePreciseAsFileTime(uptime_ptr)) {
        printf("GetSystemTimePreciseAsFileTime 함수 호출 실패\n");
        return 1;
    }

    if (uptime->dwHighDateTime == 0 && uptime->dwLowDateTime == 0) {
        printf("uptime 변수 값 오류\n");
        return 1;*/
    }
/*
    // 100나노초 단위를 초 단위로 변환
    uptime /= 10000000;

    // 시간 계산
    DWORD hours = uptime->dwHighDateTime * 3600 + uptime->dwLowDateTime / 3600000000;
    DWORD minutes = (uptime->dwLowDateTime % 3600000000) / 600000000;
    DWORD seconds = (uptime->dwLowDateTime % 600000000) / 10000000;

    // 시간 값 범위 확인
    if (hours >= 24) {
        printf("시간 값 오류: %d시간\n", hours);
        return 1;
    }

    printf("프로세서 작동 시간: %d시간 %d분 %d초\n", hours, minutes, seconds);
}*/

// 시스템 메모리 정보 출력 함수
void PrintMemoryInfo() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    GlobalMemoryStatusEx(&memInfo);

    printf("총 시스템 메모리: %.2f GB\n", memInfo.ullTotalPhys / 1073741824.0);
    printf("사용 가능한 시스템 메모리: %.2f GB\n", memInfo.ullAvailPhys / 1073741824.0);
}

// 저장 장치 정보 출력 함수
void PrintStorageInfo() {
    ULARGE_INTEGER totalBytes, freeBytes, availableBytes;

    GetDiskFreeSpaceExW(L"C:\\", &freeBytes, &totalBytes, &availableBytes);

    printf("총 저장 공간: %.2f GB\n", totalBytes.QuadPart / 1073741824.0);
    printf("사용 가능한 저장 공간: %.2f GB\n", freeBytes.QuadPart / 1073741824.0);
}

int main() {
    PrintCPUInfo();
    PrintMemoryInfo();
    PrintStorageInfo();

    return 0;
}

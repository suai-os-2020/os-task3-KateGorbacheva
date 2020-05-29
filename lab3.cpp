#include "lab3.h"
#include <windows.h>

#include <string>
//
// lab3 code  located here!
//
#define MAX_SEM_COUNT 10


using namespace std;



//Threads
HANDLE  aThread,
        bThread,
        cThread,
        dThread,
        eThread,
        fThread,
        gThread,
        hThread,
        iThread,
        kThread,
        mThread;

//Mutex
HANDLE stdout_mutex;
DWORD IDThread;

//Semaphors
HANDLE
        sem_B,
        sem_C,
        sem_D,
        sem_G,
        sem_H,
        sem_K,

        segmentEnd;

unsigned int lab3_thread_graph_id()
{
    return 6;
}

const char* lab3_unsynchronized_threads()
{
    return "deg";
}

const char* lab3_sequential_threads()
{
    return "bcd";
}





DWORD WINAPI a(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "a"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();

    }

    return 0;
}


DWORD WINAPI b(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_B, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "b"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_C, 1, NULL);
    }


    return 0;
}


DWORD WINAPI c(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_C, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "c"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_D, 1, NULL);
    }
    
    

    return 0;
}




DWORD WINAPI d(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_D, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "d"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_B, 1, NULL);
    }
    
        WaitForSingleObject(sem_D, INFINITE);
    for (int i = 0;i < 3;i++) {

        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "d"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
    
    

    return 0;
}





DWORD WINAPI e(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "e"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    

    return 0;
}




DWORD WINAPI f(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "f"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}




DWORD WINAPI g(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g" << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(segmentEnd, 1, NULL);

        WaitForSingleObject(sem_G, INFINITE);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g" << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    


    return 0;
}


DWORD WINAPI h(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "h"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(segmentEnd, 1, NULL);

        WaitForSingleObject(sem_H, INFINITE);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "h"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    

    return 0;
}


DWORD WINAPI i(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "i"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}



DWORD WINAPI k(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "k"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(segmentEnd, 1, NULL);

        WaitForSingleObject(sem_K, INFINITE);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "k"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
    

    return 0;
}


DWORD WINAPI m(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "m"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    

    return 0;
}











int lab3_init()
{

    int inc = 10;

    stdout_mutex = CreateMutex(NULL, false, NULL);
    if (stdout_mutex == NULL)
        return GetLastError();


    
    sem_D = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_D == NULL)
        return GetLastError();
    
    
    sem_G = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_G == NULL)
        return GetLastError();
    
    sem_H = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_H == NULL)
        return GetLastError();
    
    sem_K = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_K == NULL)
        return GetLastError();
    
    
    
    segmentEnd = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (segmentEnd == NULL)
        return GetLastError();
    



    aThread = CreateThread(NULL, 0, (a), 0, 0, &IDThread);
    if (aThread == NULL)
        return GetLastError();

    WaitForSingleObject(aThread, INFINITE);

    
    bThread = CreateThread(NULL, 0,(b),0, 0, &IDThread);
    if (bThread == NULL)
        return GetLastError();
    cThread = CreateThread(NULL, 0,(c),0, 0, &IDThread);
    if (cThread == NULL)
        return GetLastError();
    dThread = CreateThread(NULL, 0,(d),0, 0, &IDThread);
    if (dThread == NULL)
        return GetLastError();
    
    
    WaitForSingleObject(bThread, INFINITE);
    WaitForSingleObject(cThread, INFINITE);
    
    ReleaseSemaphore(sem_D, 1, NULL);
    
    eThread = CreateThread(NULL, 0,(e),0, 0, &IDThread);
    if (eThread == NULL)
        return GetLastError();
    gThread = CreateThread(NULL, 0,(g),0, 0, &IDThread);
    if (gThread == NULL)
        return GetLastError();
    
    
    WaitForSingleObject(eThread, INFINITE);
    WaitForSingleObject(dThread, INFINITE);
    
        ReleaseSemaphore(sem_G, 1, NULL);

        WaitForSingleObject(segmentEnd, INFINITE);
    
    
    fThread = CreateThread(NULL, 0,(f),0, 0, &IDThread);
    if (fThread == NULL)
        return GetLastError();
    hThread = CreateThread(NULL, 0,(h),0, 0, &IDThread);
    if (hThread == NULL)
        return GetLastError();
    
    
    WaitForSingleObject(fThread, INFINITE);
    WaitForSingleObject(gThread, INFINITE);
    
        ReleaseSemaphore(sem_H, 1, NULL);

        WaitForSingleObject(segmentEnd, INFINITE);
        
    iThread = CreateThread(NULL, 0,(i),0, 0, &IDThread);
    if (iThread == NULL)
        return GetLastError();
    kThread = CreateThread(NULL, 0,(k),0, 0, &IDThread);
    if (kThread == NULL)
        return GetLastError();
    

        
    WaitForSingleObject(hThread, INFINITE);
    WaitForSingleObject(iThread, INFINITE);
    
        ReleaseSemaphore(sem_K, 1, NULL);

        WaitForSingleObject(segmentEnd, INFINITE);
    
    mThread = CreateThread(NULL, 0,(m),0, 0, &IDThread);
    if (mThread == NULL)
        return GetLastError();
    
    
    
    WaitForSingleObject(kThread, INFINITE);
    WaitForSingleObject(mThread, INFINITE);
    
   
    // закрываем дескриптор
    
    CloseHandle(sem_B);
    CloseHandle(sem_C);
    CloseHandle(sem_D);
    CloseHandle(sem_G);
    CloseHandle(sem_H);
    CloseHandle(sem_K);


    CloseHandle(segmentEnd);



    CloseHandle(aThread);
    CloseHandle(bThread);
    CloseHandle(cThread);
    CloseHandle(dThread);
    CloseHandle(eThread);
    CloseHandle(fThread);
    CloseHandle(gThread);
    CloseHandle(hThread);
    CloseHandle(iThread);
    CloseHandle(kThread);
    CloseHandle(mThread);

    // CreateThread();
    //  WaitForMultipleObjects();
    // ...
    CloseHandle(stdout_mutex);

    return 0;
}









#include "lab3.h"
#include <windows.h>

#include <string>
//
// lab3 code  located here!
//
#define MAX_SEM_COUNT 10


using namespace std;



//Threads
HANDLE  aThread,
        bThread,
        cThread,
        dThread,
        eThread,
        fThread,
        gThread,
        hThread,
        iThread,
        kThread,
        mThread;

//Mutex
HANDLE stdout_mutex;
DWORD IDThread;

//Semaphors
HANDLE
        sem_B,
        sem_C,
        sem_D,
        sem_G,
        sem_H,
        sem_K,

        segmentEnd;

unsigned int lab3_thread_graph_id()
{
    return 6;
}

const char* lab3_unsynchronized_threads()
{
    return "deg";
}

const char* lab3_sequential_threads()
{
    return "bcd";
}





DWORD WINAPI a(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "a"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();

    }

    return 0;
}


DWORD WINAPI b(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_B, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "b"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_C, 1, NULL);
    }


    return 0;
}


DWORD WINAPI c(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_C, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "c"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_D, 1, NULL);
    }
    
    

    return 0;
}




DWORD WINAPI d(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_D, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "d"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_B, 1, NULL);
    }
    
        WaitForSingleObject(sem_D, INFINITE);
    for (int i = 0;i < 3;i++) {

        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "d"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
    
    

    return 0;
}





DWORD WINAPI e(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "e"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    

    return 0;
}




DWORD WINAPI f(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "f"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}




DWORD WINAPI g(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g" << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(segmentEnd, 1, NULL);

        WaitForSingleObject(sem_G, INFINITE);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g" << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    


    return 0;
}


DWORD WINAPI h(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "h"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(segmentEnd, 1, NULL);

        WaitForSingleObject(sem_H, INFINITE);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "h"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    

    return 0;
}


DWORD WINAPI i(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "i"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}



DWORD WINAPI k(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "k"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(segmentEnd, 1, NULL);

        WaitForSingleObject(sem_K, INFINITE);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "k"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
    

    return 0;
}


DWORD WINAPI m(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "m"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    

    return 0;
}











int lab3_init()
{

    int inc = 10;

    stdout_mutex = CreateMutex(NULL, false, NULL);
    if (stdout_mutex == NULL)
        return GetLastError();


    
    sem_D = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_D == NULL)
        return GetLastError();
    
    
    sem_G = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_G == NULL)
        return GetLastError();
    
    sem_H = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_H == NULL)
        return GetLastError();
    
    sem_K = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_K == NULL)
        return GetLastError();
    
    
    
    segmentEnd = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (segmentEnd == NULL)
        return GetLastError();
    



    aThread = CreateThread(NULL, 0, (a), 0, 0, &IDThread);
    if (aThread == NULL)
        return GetLastError();

    WaitForSingleObject(aThread, INFINITE);

    
    bThread = CreateThread(NULL, 0,(b),0, 0, &IDThread);
    if (bThread == NULL)
        return GetLastError();
    cThread = CreateThread(NULL, 0,(c),0, 0, &IDThread);
    if (cThread == NULL)
        return GetLastError();
    dThread = CreateThread(NULL, 0,(d),0, 0, &IDThread);
    if (dThread == NULL)
        return GetLastError();
    
    
    WaitForSingleObject(bThread, INFINITE);
    WaitForSingleObject(cThread, INFINITE);
    
    ReleaseSemaphore(sem_D, 1, NULL);
    
    eThread = CreateThread(NULL, 0,(e),0, 0, &IDThread);
    if (eThread == NULL)
        return GetLastError();
    gThread = CreateThread(NULL, 0,(g),0, 0, &IDThread);
    if (gThread == NULL)
        return GetLastError();
    
    
    WaitForSingleObject(eThread, INFINITE);
    WaitForSingleObject(dThread, INFINITE);
    
        ReleaseSemaphore(sem_G, 1, NULL);

        WaitForSingleObject(segmentEnd, INFINITE);
    
    
    fThread = CreateThread(NULL, 0,(f),0, 0, &IDThread);
    if (fThread == NULL)
        return GetLastError();
    hThread = CreateThread(NULL, 0,(h),0, 0, &IDThread);
    if (hThread == NULL)
        return GetLastError();
    
    
    WaitForSingleObject(fThread, INFINITE);
    WaitForSingleObject(gThread, INFINITE);
    
        ReleaseSemaphore(sem_H, 1, NULL);

        WaitForSingleObject(segmentEnd, INFINITE);
        
    iThread = CreateThread(NULL, 0,(i),0, 0, &IDThread);
    if (iThread == NULL)
        return GetLastError();
    kThread = CreateThread(NULL, 0,(k),0, 0, &IDThread);
    if (kThread == NULL)
        return GetLastError();
    

        
    WaitForSingleObject(hThread, INFINITE);
    WaitForSingleObject(iThread, INFINITE);
    
        ReleaseSemaphore(sem_K, 1, NULL);

        WaitForSingleObject(segmentEnd, INFINITE);
    
    mThread = CreateThread(NULL, 0,(m),0, 0, &IDThread);
    if (mThread == NULL)
        return GetLastError();
    
    
    
    WaitForSingleObject(kThread, INFINITE);
    WaitForSingleObject(mThread, INFINITE);
    
   
    // закрываем дескриптор
    
    CloseHandle(sem_B);
    CloseHandle(sem_C);
    CloseHandle(sem_D);
    CloseHandle(sem_G);
    CloseHandle(sem_H);
    CloseHandle(sem_K);


    CloseHandle(segmentEnd);



    CloseHandle(aThread);
    CloseHandle(bThread);
    CloseHandle(cThread);
    CloseHandle(dThread);
    CloseHandle(eThread);
    CloseHandle(fThread);
    CloseHandle(gThread);
    CloseHandle(hThread);
    CloseHandle(iThread);
    CloseHandle(kThread);
    CloseHandle(mThread);

    // CreateThread();
    //  WaitForMultipleObjects();
    // ...
    CloseHandle(stdout_mutex);

    return 0;
}










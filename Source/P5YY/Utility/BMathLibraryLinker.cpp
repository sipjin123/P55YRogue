#include "BMathLibraryLinker.h"


typedef int(*_getcustomVoidInit)(); 
typedef void(*_getcustomVoidSet)(int a);
typedef int(*_getcustomVoidGet)(); 
typedef int(*_getcustomVoidAdditiveGet)(int a);

typedef void(*_getfibonacci_init)(int a, int b);
typedef bool(*_getfibonacci_current)(); 
typedef bool(*_getFibonacci_next)(); 


typedef bool(*_getInvertedBool)(bool boolState); // Declare a method to store the DLL method getInvertedBool.
typedef int(*_getIntPlusPlus)(int lastInt); // Declare a method to store the DLL method getIntPlusPlus.
typedef float(*_getCircleArea)(float radius); // Declare a method to store the DLL method getCircleArea.
typedef char*(*_getCharArray)(char* parameterText); // Declare a method to store the DLL method getCharArray.
typedef float*(*_getVector4)(float x, float y, float z, float w); // Declare a method to store the DLL method getVector4.

_getInvertedBool m_getInvertedBoolFromDll;
_getIntPlusPlus m_getIntPlusPlusFromDll;
_getCircleArea m_getCircleAreaFromDll;
_getCharArray m_getCharArrayFromDll;
_getVector4 m_getVector4FromDll;

_getfibonacci_init m_getFibonacciInitFromDll;
_getfibonacci_current m_getFibonacciCurrentFromDLL;
_getFibonacci_next m_getFibonacciNextFromDll;

_getcustomVoidInit m_getcustomVoidInitFromDll;
_getcustomVoidSet m_setcustomVoidFromDll;
_getcustomVoidGet m_getcustomVoidFromDll;
_getcustomVoidAdditiveGet m_getcustomVoidAdditiveFromDll;
void *v_dllHandle;

#pragma region Load DLL

// Method to import a DLL.
bool UBMathLibraryLinker::importDLL(FString folder, FString name)
{
    FString filePath = *FPaths::ProjectPluginsDir() + folder + "/" + name;
    
    if (FPaths::FileExists(filePath))
    {
        UE_LOG(LogTemp, Warning, TEXT("New path is: {%s}"), *filePath);
        v_dllHandle = FPlatformProcess::GetDllHandle(*filePath); // Retrieve the DLL.
        if (v_dllHandle != NULL)
        {
            return true;
        }
    }
    return false;    // Return an error.
}
#pragma endregion Load DLL

#pragma region Import Methods

// Imports the method getInvertedBool from the DLL.
bool UBMathLibraryLinker::importMethodGetInvertedBool()
{
    if (v_dllHandle != NULL)
    {
        m_getInvertedBoolFromDll = NULL;
        FString procName = "getInvertedBool";    // Needs to be the exact name of the DLL method.
        m_getInvertedBoolFromDll = (_getInvertedBool)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getInvertedBoolFromDll != NULL)
        {
            return true;
        }
    }
    return false;    // Return an error.
}

// Imports the method getIntPlusPlus from the DLL.
bool UBMathLibraryLinker::importMethodGetIntPlusPlus()
{
    if (v_dllHandle != NULL)
    {
        m_getIntPlusPlusFromDll = NULL;
        FString procName = "getIntPlusPlus";    // Needs to be the exact name of the DLL method.
        m_getIntPlusPlusFromDll = (_getIntPlusPlus)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getIntPlusPlusFromDll != NULL)
        {
            return true;
        }
    }
    return false;    // Return an error.
}

// Imports the method getCircleArea from the DLL.
bool UBMathLibraryLinker::importMethodGetCircleArea()
{
    if (v_dllHandle != NULL)
    {
        m_getCircleAreaFromDll = NULL;
        FString procName = "getCircleArea";    // Needs to be the exact name of the DLL method.
        m_getCircleAreaFromDll = (_getCircleArea)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getCircleAreaFromDll != NULL)
        {
            return true;
        }
    }
    return false;    // Return an error.
}

// Imports the method getVector4 from the DLL.
bool UBMathLibraryLinker::importMethodGetVector4( )
{
    if( v_dllHandle != NULL )
    {
        m_getVector4FromDll = NULL;
        FString procName = "getVector4";    // Needs to be the exact name of the DLL method.
        m_getVector4FromDll = ( _getVector4 ) FPlatformProcess::GetDllExport( v_dllHandle, *procName );
        if( m_getVector4FromDll != NULL )
        {
            return true;
        }
    }
    return false;    // Return an error.
}

bool UBMathLibraryLinker::importMethodinitCustomVoid()
{
    if( v_dllHandle != NULL )
    {
        m_getcustomVoidInitFromDll = NULL;
        FString procName = "initCustomVoid";    // Needs to be the exact name of the DLL method.
        m_getcustomVoidInitFromDll = ( _getcustomVoidInit ) FPlatformProcess::GetDllExport( v_dllHandle, *procName );
        if( m_getcustomVoidInitFromDll != NULL )
        {
            return true;
        }
    }
    return false;    // Return an error.
}

bool UBMathLibraryLinker::importMethodsetCustomVoid()
{
    if (v_dllHandle != NULL)
    {
        m_setcustomVoidFromDll = NULL;
        FString procName = "setCustomVoid";    // Needs to be the exact name of the DLL method.
        m_setcustomVoidFromDll = (_getcustomVoidSet)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_setcustomVoidFromDll != NULL)
        {
            return true;
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("FAIL INIT Setter Custom VOID"));
    return false;    // Return an error.
}

bool UBMathLibraryLinker::importMethodgetCustomVoid()
{
    if (v_dllHandle != NULL)
    {
        m_getcustomVoidFromDll = NULL;
        FString procName = "getCustomVoid";    // Needs to be the exact name of the DLL method.
        m_getcustomVoidFromDll = (_getcustomVoidGet)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getcustomVoidFromDll != NULL)
        {
            return true;
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("FAIL INIT Getter Custom VOID"));
    return false;    // Return an error.
}

bool UBMathLibraryLinker::importMethodgetCustomVoidAdditive()
{
    if (v_dllHandle != NULL)
    {
        m_getcustomVoidAdditiveFromDll = NULL;
        FString procName = "getCustomVoidAdditive";    // Needs to be the exact name of the DLL method.
        m_getcustomVoidAdditiveFromDll = (_getcustomVoidAdditiveGet)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getcustomVoidAdditiveFromDll != NULL)
        {
            return true;
        }
    }
    
    UE_LOG(LogTemp, Warning, TEXT("FAIL INIT Getter Custom VOID additive"));
    return false;    // Return an error.
}

bool UBMathLibraryLinker::importMethodfibonacci_init()
{
    if (v_dllHandle != NULL)
    {
        UE_LOG(LogTemp, Warning, TEXT("ATTEMPT TO FIBO"));
        m_getFibonacciInitFromDll = NULL;
        FString procName = "fibonacci_init";    // Needs to be the exact name of the DLL method.
        m_getFibonacciInitFromDll = (_getfibonacci_init) FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getFibonacciInitFromDll != NULL)
        {
            UE_LOG(LogTemp, Warning, TEXT("Fibonacci Initiated"));
            return true;
        }
    }
            UE_LOG(LogTemp, Warning, TEXT("Fibonacci Failed to Initiate"));
    return false;    // Return an error.
}

bool UBMathLibraryLinker::importMethodfibonacci_next()
{
    if (v_dllHandle != NULL)
    {
        m_getFibonacciNextFromDll = NULL;
        FString procName = "fibonacci_next";    // Needs to be the exact name of the DLL method.
        m_getFibonacciNextFromDll = (_getFibonacci_next)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getFibonacciNextFromDll != NULL)
        {
            return true;
        }
    }
    return false;    // Return an error.
}

bool UBMathLibraryLinker::importMethodfibonacci_current()
{
    if (v_dllHandle != NULL)
    {
        m_getFibonacciCurrentFromDLL = NULL;
        FString procName = "fibonacci_current";    // Needs to be the exact name of the DLL method.
        m_getFibonacciCurrentFromDLL = (_getfibonacci_current)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getFibonacciCurrentFromDLL != NULL)
        {
            return true;
        }
    }
    return false;    // Return an error.
}

#pragma endregion Import Methods

#pragma region Method Calls

// Calls the method getInvertedBoolFromDll that was imported from the DLL.
bool UBMathLibraryLinker::getInvertedBoolFromDll(bool boolState)
{
    if (m_getInvertedBoolFromDll != NULL)
    {
        bool out = bool(m_getInvertedBoolFromDll(boolState)); // Call the DLL method with arguments corresponding to the exact signature and return type of the method.
        return out;
    }
    return boolState;    // Return an error.
}

// Calls the method m_getIntPlusPlusFromDll that was imported from the DLL.
int UBMathLibraryLinker::getIntPlusPlusFromDll(int lastInt)
{
    if (m_getIntPlusPlusFromDll != NULL)
    {
        int out = int(m_getIntPlusPlusFromDll(lastInt)); // Call the DLL method with arguments corresponding to the exact signature and return type of the method.
        return out;
    }
    return -32202;    // Return an error.
}

// Calls the method m_getCircleAreaFromDll that was imported from the DLL.
float UBMathLibraryLinker::getCircleAreaFromDll(float radius)
{
    if (m_getCircleAreaFromDll != NULL)
    {
        float out = float(m_getCircleAreaFromDll(radius)); // Call the DLL method with arguments corresponding to the exact signature and return type of the method.
        return out;
    }
    return -32202.0F;    // Return an error.
}

// Calls the method m_getCharArrayFromDLL that was imported from the DLL.
FString UBMathLibraryLinker::getCharArrayFromDll(FString parameterText)
{
    if (m_getCharArrayFromDll != NULL)
    {
        char* parameterChar = TCHAR_TO_ANSI(*parameterText);

        char* returnChar = m_getCharArrayFromDll(parameterChar);

        return (ANSI_TO_TCHAR(returnChar));
    }
    return "Error: Method getCharArray was probabey not imported yet!";    // Return an error.
}

// Calls the method m_getVector4FromDll that was imported from the DLL.
FVector4 UBMathLibraryLinker::getVector4FromDll( FVector4 vector4 )
{
    if( m_getVector4FromDll != NULL )
    {
        float* vector4Array = m_getVector4FromDll( vector4.X, vector4.Y, vector4.Z, vector4.W );

        return FVector4( vector4Array[0], vector4Array[1], vector4Array[2], vector4Array[3] );
    }
    return FVector4( -32202.0F, -32202.0F, -32202.0F, -32202.0F );    // Return an error.
}

int UBMathLibraryLinker::initCustomVoidFromDll()
{
    if (m_getcustomVoidInitFromDll != NULL)
    {
        UE_LOG(LogTemp, Warning, TEXT("SUCCESS Custom VOID"));
        int out = int(m_getcustomVoidInitFromDll()); // Call the DLL method with arguments corresponding to the exact signature and return type of the method.
        return out;
    }
    return -2;
}

void UBMathLibraryLinker::setCustomVoidFromDll(int addVal)
{
    if (m_setcustomVoidFromDll != NULL)
    {
        UE_LOG(LogTemp, Warning, TEXT("SUCCESS Custom VOID"));
        m_setcustomVoidFromDll(addVal);
    } else
    {
        UE_LOG(LogTemp, Warning, TEXT("FAIL INIT FIBO"));
    }
}

int UBMathLibraryLinker::getCustomVoidFromDll()
{
    if (m_getcustomVoidFromDll != NULL)
    {
        int out = int(m_getcustomVoidFromDll()); // Call the DLL method with arguments corresponding to the exact signature and return type of the method.
        return out;
    }
    return -1;    // Return an error.
}

int UBMathLibraryLinker::getCustomVoidAdditiveFromDll(int addVal)
{
    if (m_getcustomVoidAdditiveFromDll != NULL)
    {
        int out = int(m_getcustomVoidAdditiveFromDll(addVal)); // Call the DLL method with arguments corresponding to the exact signature and return type of the method.
        return out;
    }
    return -1;    // Return an error.
}

void UBMathLibraryLinker::fibonacci_initFromDll(int a, int b)
{
    if (m_getFibonacciInitFromDll != NULL)
    {
        UE_LOG(LogTemp, Warning, TEXT("SUCCESS INIT FIBO"));
        m_getFibonacciInitFromDll(a, b);
    } else
    {
        UE_LOG(LogTemp, Warning, TEXT("FAIL INIT FIBO"));
    }
}

bool UBMathLibraryLinker::fibonacci_nextFromDll()
{
    if (m_getFibonacciNextFromDll != NULL)
    {
        return m_getFibonacciNextFromDll();
    }
    return false;    // Return an error.
}

int UBMathLibraryLinker::getfibonacci_currentFromDLL()
{
    if (m_getFibonacciCurrentFromDLL != NULL)
    {
        int out = int(m_getFibonacciCurrentFromDLL()); // Call the DLL method with arguments corresponding to the exact signature and return type of the method.
        return out;
    }
    return -1;    // Return an error.
    /*
    if (v_dllHandle != NULL)
    {
        m_getFibonacciCurrentFromDLL = NULL;
        FString procName = "fibonacci_current";    // Needs to be the exact name of the DLL method.
        m_getFibonacciCurrentFromDLL = (_getfibonacci_current)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
        if (m_getFibonacciCurrentFromDLL != NULL)
        {
            return 1;
        }
    }
    return 0;    // Return an error.*/
}


#pragma endregion Method Calls


#pragma region Unload DLL

// If you love something  set it free.
void UBMathLibraryLinker::freeDLL()
{
    if (v_dllHandle != NULL)
    {
        m_getInvertedBoolFromDll = NULL;
        m_getIntPlusPlusFromDll = NULL;
        m_getCircleAreaFromDll = NULL;
        m_getCharArrayFromDll = NULL;
        m_getVector4FromDll = NULL;

        FPlatformProcess::FreeDllHandle(v_dllHandle);
        v_dllHandle = NULL;
    }
}

#pragma endregion Unload DLL

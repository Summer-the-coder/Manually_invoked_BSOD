// DISCLAIMER: This code is provided for educational purposes only. It **will** crash your system. Use at your own risk.
#include <Windows.h>
#pragma comment(lib, "ntdll.lib")

extern "C" {
    NTSTATUS NTAPI RtlAdjustPrivilege(
        ULONG Privilege,
        BOOLEAN Enable,
        BOOLEAN CurrentThread,
        PBOOLEAN OldValue
    );

    NTSTATUS NTAPI NtRaiseHardError(
        LONG ErrorStatus,
        ULONG NumberOfParameters,
        ULONG UnicodeStringParameterMask,
        PULONG_PTR Parameters,
        ULONG ValidResponseOptions,
        PULONG Response
    );
}

int main() {
    BOOLEAN bl;
    ULONG Response;

    RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response);

    return 0;
}

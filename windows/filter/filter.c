/*
 * Minimal NDIS filter driver skeleton (educational).
 * This is a skeleton showing required entry points. Build with Visual Studio + WDK.
 *
 * IMPORTANT: This code is a non-functional template intended for learning and
 * must be adapted and tested heavily before use.
 */
#include <ndis.h>

// Globals
NDIS_HANDLE FilterDriverHandle = NULL;

VOID FilterDriverUnload(_In_ PDRIVER_OBJECT DriverObject)
{
    UNREFERENCED_PARAMETER(DriverObject);
    // Cleanup, if needed
}

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
    UNREFERENCED_PARAMETER(RegistryPath);
    DriverObject->DriverUnload = FilterDriverUnload;
    // Register NDIS filter driver here - in real driver use NdisFRegisterFilterDriver
    // This is a placeholder to show structure.
    return STATUS_SUCCESS;
}

// NOTE: Real NDIS drivers require many callbacks, registration with NDIS,
// proper IRQL handling, and a .inf for installation. See Microsoft samples.

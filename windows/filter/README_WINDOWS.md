# Windows NDIS Filter Driver (skeleton)

This folder contains a minimal NDIS filter driver skeleton. It is **not** a complete,
loadable, secure driver. Use it only as a starting point.

## Build
- Install Visual Studio 2022 (or newer) and Windows Driver Kit (WDK).
- Create an NDIS Filter Driver project or import `filter.c` into an existing driver project.
- Link against the correct NDIS libraries and set driver model to Kernel.

## Testing
- You will need to sign the driver or enable test-signing on Windows.
- Use `sc` / `pnputil` / Device Manager to install the driver using a proper INF.
- Always test on a VM or test machine — do not install unsigned drivers on production systems.

## Resources
- Microsoft NDIS driver samples (in WDK)
- NDIS Filter and Miniport driver documentation

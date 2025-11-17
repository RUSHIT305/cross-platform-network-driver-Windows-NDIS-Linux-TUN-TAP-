# cross-netdriver

Cross-platform starter repository containing:
- Linux user-space TUN/TAP program (Ubuntu 22.04+)
- Optional Linux kernel-style net_device skeleton (example only)
- Windows NDIS Filter driver skeleton (Windows 10 / 11)
- Build instructions and examples

**Important:** The Windows driver skeleton is a starting point and **must** be built using Visual Studio + Windows Driver Kit (WDK). The Linux TUN program builds with `gcc`.

## Contents
- linux/ — TUN/TAP user-space example + optional kernel skeleton
- windows/filter/ — NDIS Filter driver skeleton (sample)
- tools/create_repo.sh — helper script
- LICENSE (MIT)

## Quick start (Ubuntu)
```bash
cd linux
make
sudo ./tun-user tun0
```

Configure the interface after creation, e.g.:
```bash
sudo ip addr add 10.0.0.1/24 dev tun0
sudo ip link set dev tun0 up
```

## Quick notes (Windows)
- Open `windows/filter` in Visual Studio as a KMDF/NDIS driver project (or import sources).
- Install WDK and sign the driver for testing.
- See `windows/filter/README_WINDOWS.md` for details.

## License
MIT

PLEASE NOTE :- THIS DRIVER IS NOT FOR PRODUCTION. IT IS SOLELY FOR EDUCATIONAL USES AND NORMAL TESTING. 

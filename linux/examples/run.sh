#!/usr/bin/env bash
# Example: build and run tun-user (requires sudo to configure the device)
set -e
cd "$(dirname "$0")/.."
make
sudo ./tun-user tun0

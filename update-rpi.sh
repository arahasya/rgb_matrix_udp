#!/bin/bash

cd "$(dirname "${BASH_SOURCE[0]}")"

git pull
git submodule update --remote --merge

cd rpi-rgb-led-matrix/
export USER_DEFINES=-DFIXED_FRAME_MICROSECONDS=10000
make

cd ../udp_receiver/
./build.sh
sudo ./install.sh

echo "[Done]"

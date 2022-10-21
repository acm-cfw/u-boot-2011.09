#!/bin/bash

PLATFORM="sun8iw5p1"
CONFIG_ARCH_R16="y"
export CONFIG_ARCH_R16

make -j8 $PLATFORM CROSS_COMPILE=/usr/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabi/bin/arm-linux-gnueabi- spl boot0

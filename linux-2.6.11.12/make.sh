#!/bin/bash
make ARCH=i386 defconfig O=../out
make bzImage -j4 O=../out

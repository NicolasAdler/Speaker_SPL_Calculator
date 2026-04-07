#!/bin/bash
make clean

python SPL_Calculator.py

make all
./main

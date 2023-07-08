#!/bin/bash

cp(){
    g++ $1.cpp -o $1.out -g -O3 -std=c++17 -fsprit-stack -fsanitize=address -fsanitize=undefined
}

run(){
    echo "==== Running Start ($2) ######"
    ./$1.out < $2.txt > out_$2.txt
    echo "==== Running End ($2) ######" 
}

if [ $1 == 'c']; then
    cp $2
elif  [$1 == "r"]; then
    run $2 $3
4fi
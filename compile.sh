#!/bin/bash

compiled_dir=./compiled
compiled_classes_dir=$compiled_dir/classes
source_dir=./src

if ! [ -d $compiled_dir ]
then
    mkdir $compiled_dir
fi

if ! [ -d $compiled_classes_dir ]
then
    mkdir $compiled_classes_dir
fi

g++ -c $source_dir/simpson_integration.cpp -o $compiled_classes_dir/simpson_integration.o -fopenmp && \
g++ -c $source_dir/main.cpp -o $compiled_classes_dir/main.o && \
g++ $compiled_classes_dir/main.o $compiled_classes_dir/simpson_integration.o -o $compiled_dir/program -fopenmp
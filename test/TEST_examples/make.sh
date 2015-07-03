#!/bin/bash
for f in *.jobs
do
cat $f >> CMakeLists.txt
done

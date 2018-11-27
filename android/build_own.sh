#!/bin/bash

if [ $# -lt 3 ]; then
	echo " Invalid arguments ...!"
	echo "usage ./build_own.sh <0/1> <TARGET PRODUCT> [OPTIONS]"
	exit 0
fi

mkdir -p logs/buildlogs_andriod/`date |cut -d ' ' -f 3``date|cut -d ' ' -f 2``date|cut -d ' ' -f 6`

if [ $1 -eq 1 ]; then
ionice -c 3 nice -n 30 ./build.sh $2 -c $3 |tee logs/buildlogs_andriod/`date |cut -d ' ' -f 3``date|cut -d ' ' -f 2``date|cut -d ' ' -f 6`/build_`date | cut -d ' ' -f 6`_`date | cut -d ' ' -f 4`_`date | cut -d ' ' -f 3`_`date | cut -d ' ' -f 2`.log
else
ionice -c 3 nice -n 30 ./build.sh $2 $3 |tee logs/buildlogs_andriod/`date |cut -d ' ' -f 3``date|cut -d ' ' -f 2``date|cut -d ' ' -f 6`/build_`date | cut -d ' ' -f 6`_`date | cut -d ' ' -f 4`_`date | cut -d ' ' -f 3`_`date | cut -d ' ' -f 2`.log
fi

cd logs/buildlogs_andriod/

git status
git add .
git commit -m "Build attempted and logs pushed with command {./build.sh $2 $1 $3}"
git push

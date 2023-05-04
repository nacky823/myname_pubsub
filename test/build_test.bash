#!/bin/bash

echo $-

dir=~
[ "$1" != "" ] && dir="$1"

ng () {
    echo -e "NG at line $1" 
    res=1
    exit $res
}

res=0

cd $dir/ros2_ws
pwd
ls -A
colcon build
[ "$?" = 0 ] || ng ${LINENO}

exit $res
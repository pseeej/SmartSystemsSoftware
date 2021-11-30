#!/bin/sh

res=`expr 100000 \* $1 / \( $2 \* $2 \)`

if [ $res -lt 185 ]
then
   echo "저체중입니다."
elif [ $res -ge 230 ]
then
   echo "과체중입니다."
else
   echo "정상체중입니다."
fi

exit 0
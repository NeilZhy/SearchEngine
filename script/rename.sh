#!/bin/bash

#将htmlsource目录下面的所有文件替换成1-n开头的文件
#执行脚本之前需要先使用rename指令将文件的空格替换掉's/ /_/g' *

cd ./htmlsource
rename 's/ /_/g' *
cd ..

i=0
for x in `ls ./htmlsource`
do
    mv "./htmlsource/$x" "./htmlsource/$i.html"
    ((i++))
done

#for x in `ls ./htmlsource | tr " " "_"`
#do
#    f="`echo ${x} | tr "_" "\\ "`"
#    f1="`echo ${x}| sed 's/_//g'`"
#    #echo $f1
#    if [ "$f" != "$f1" ]
#    then
#        mv "$f" "$f1"
#    fi
#done

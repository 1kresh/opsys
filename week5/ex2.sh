#!/bin/bash
tempfile=$(mktemp ./lock.XXXX)
lockfile=./lockfile
if ln $tempfile $lockfile ; then
    echo 0 >> ex2.txt
    for (( i = 0 ; i < 10; i++ )) do
        LAST=`grep -Eo "^[0-9]+$" ex2.txt | tail -1`
        NEW=`expr ${LAST} + 1`
        echo "$NEW" >> ex2.txt
    done
    rm $lockfile
fi
rm $tempfile

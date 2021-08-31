#!/usr/bin/env bash
INPUT=0-hreadelf
make -B 0-hreadelf && ./${INPUT} ${INPUT} | cat -e > /tmp/a
readelf -W -h ./${INPUT} | cat -e > /tmp/b
colordiff -y -W 200 /tmp/{a,b}

#!/usr/bin/env bash
INPUT=${1-0-hreadelf}
# make -B 0-hreadelf && ./0-hreadelf "${INPUT}" | cat -e > /tmp/a || exit
# readelf -W -h "${INPUT}" | cat -e > /tmp/b || exit
colordiff -y -W 200 /tmp/{a,b}

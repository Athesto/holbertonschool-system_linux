#!/bin/sh
#shellcheck disable=SC1091
. ./9-handle_signal.sh

echo "PID: $$"

while :
do
    echo "Waiting ..."
    sleep 2
done

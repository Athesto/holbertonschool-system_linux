#!/usr/bin/env sh
if [ $# != 1 ]; then 
{ 
    echo "Usage: $0 <pid>" >&2
    exit 1
}
fi

kill -3 "$1"

#!/usr/bin/env sh
[ $# != 1 ] && { echo "Usage: $0 <pid>" >&2; exit 1; }

kill -3 "$1"

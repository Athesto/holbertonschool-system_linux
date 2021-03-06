#!/usr/bin/python3
''' a script that finds a string in the
heap of a running process, and replaces it.'''

from sys import argv, exit
from pprint import pprint
if __name__ == "__main__":
    if len(argv) != 4:
        print("use {} pid search_string replace_string".format(argv[0]))
        exit(1)
    [pid, search, replace] = argv[1:]
    if "" in [pid, search]:
        print("please use a no empty value")
        exit(1)
    if replace == '':
        replace = ' ' * len(search)
    maps_path = "/proc/{}/maps".format(pid)
    mem_path = "/proc/{}/mem".format(pid)
    heap = {
        "start": '',
        "end": '',
        "mode": "",
        "mem": ""
    }
    with open(maps_path) as maps:
        for line in maps:
            if "[heap]" in line:
                tmp = line.split()
                tmp[0] = tmp[0].split('-')
                tmp[0] = list(map(lambda x: int('0x' + x, 16), tmp[0]))
                [heap['start'], heap['end']] = tmp[0]
                heap['mode'] = tmp[1]
                break
    if heap["start"] == '':
        print("heap not found")
        exit(2)

    with open(mem_path, 'rb+') as mem:
        mem.seek(heap['start'])
        heap["mem"] = mem.read(heap['end'] - heap['start'])
        try:
            i = heap["mem"].index(bytes(search, "ASCII"))
        except ValueError:
            print("string not found")
            exit(3)
        mem.seek(heap['start'] + i)
        mem.write(bytes(replace, "ASCII"))

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    prettier.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacharle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 23:04:13 by cacharle          #+#    #+#              #
#    Updated: 2020/05/04 14:44:44 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import sys
import re
import argparse


def green(*strings):
    return "".join(["\033[32m{}\033[0m".format(s) for s in strings])


def red(*strings):
    return "".join(["\033[31m{}\033[0m".format(s) for s in strings])

def create_logs_entry(logs, key):
    logs[key] = {}
    logs[key]["ok_counter"] = 0
    logs[key]["ko_counter"] = 0
    logs[key]["ko_info"] = []

def parse():
    logs = {}
    for line in sys.stdin:
        line = line.strip()
        if line[:2] == "OK":
            l = logs.get(line[4:])
            if l is None:
                print("\n\n", line[4:], ": ", sep="", end="")
                create_logs_entry(logs, line[4:])
            logs[line[4:]]["ok_counter"] += 1
            if (logs[line[4:]]["ok_counter"] + logs[line[4:]]["ko_counter"]) % 15 == 0:
                print("\n", ''.join([" " for _ in range(1 + len(line[4:]))]), end="")
            print(green("[OK] "), end="")
            continue
        m = None
        if line.find("SEGFAULT") != -1:
            name = line[4:]
        else:
            m = re.search("^KO: \[COMPARE\]: (.*): expected: (.*) got: (.*)( with: .*)?$", line)
            if m is None:
                print(line)
                print("PARSING ERROR")
                continue
            name = m.group(1)

        l = logs.get(name)
        if l is None:
            create_logs_entry(logs, name)
            print("\n\n", name, ": ", sep="", end="")
            l = logs.get(name)
        l["ko_counter"] += 1
        if m is None:
            l["ko_info"].append({
                "type": "SEGFAULT",
                "expected": None,
                "actual": None,
                "with": None
            })
        else:
            l["ko_info"].append({
                "type": "COMPARE",
                "expected": m.group(2),
                "actual": m.group(3),
                "with": None
            })
        if m is not None and m.group(4) is not None:
            l["ko_info"][-1]["with"] = m.group(4)[6:]
        if (l["ok_counter"] + l["ko_counter"]) % 15 == 0:
            print("\n", ''.join([" " for _ in range(1 + len(name))]), end="")
        print(red("[KO] "), end="")
        sys.stdout.flush()
    return logs

if __name__ == "__main__":
    os.system("clear")
    logs = parse()
    print("\n")
    for k, v in logs.items():
        for e in v["ko_info"]:
            if e['type'] == "SEGFAULT":
                print("{} : {}".format(k, red('SEGFAULT')))
            elif e['type'] == "COMPARE":
                p = str(k)
                if e["with"] is not None:
                    p += "with {}".format(e['with'])
                print(p, ":\n    {}\n    {}".format(green('expected: ') + e['expected'],
                                                     red('actual: ') + e['actual']))

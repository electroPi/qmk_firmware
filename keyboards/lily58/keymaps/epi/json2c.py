#!/usr/bin/python3

import json

f = open('lily58_light_epi_layout.json', "r")

data = json.load(f)

# Iterating through the json
# list
# for i in data['layers']:
#     print(i)
#     print('peter')
def dump_layer(z):
    c1=0
    c2=0
    c3=0

    #print(z)
    for e in z:
        # first 3 rows
        if c3 < 3:
            if c1 < 6:
                # first half, left half
                print("%s,\t\t" %e, end='')
            c1 = c1+1
            if c1 == 6:
                # middle part
                print("\t\t\t", end='')
            elif c1 > 6 and c2 < 6:
                # second half, right half
                print("%s,\t\t" %e, end='')
                c2 = c2 + 1
            if c1 > 6 and c2 == 6:
                # end of line
                print('')
                c1 = 0
                c2 = 0
                c3 = c3 + 1
        elif c3 == 3:
            # 4'th row - the longest one
            if c1 < 14:
                print("%s,\t\t" %e, end='')
                c1 = c1+1
            elif c1 == 14:
                c3 = c3 + 1
                c1 = 0
                print("")
                print("\t\t\t\t\t%s,\t\t" %e, end='')
        elif c3 == 4:
            if c1 == 0:
                print("%s,\t\t" %e, end='')
            c1 = c1 + 1
            if c1 > 1:
                print("%s,\t\t" %e, end='')

for i in data['layers']:
    print("[layer] = LAYOUT(")
    dump_layer(i)
    print()
    print("),\n")

# Closing file
f.close()
print()


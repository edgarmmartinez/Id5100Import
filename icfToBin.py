#!/opt/local/bin/python

import sys
import binascii



if (len(sys.argv) != 2):
    print "Usage:",sys.argv[0],"<file name>"
    exit(1)

with open(sys.argv[1]) as myFile:
    icfContent = myFile.readlines()

for line in icfContent:
    if (line[0]!= '#'):
        strData = line[10:-2]
        sys.stdout.write (binascii.unhexlify(strData))

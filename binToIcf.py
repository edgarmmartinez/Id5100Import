#!/usr/local/bin/python

import sys
import binascii

if (len(sys.argv) != 2):
    print "Usage:",sys.argv[0],"<bin file>"
    exit(1)

with open (sys.argv[1],mode='rb') as myFile:
    binContent = myFile.read()

hexContent = binascii.hexlify(binContent)

hexSize = len(hexContent)

print "34840001"
print "#MapRev=3"
i = 0
while i < hexSize:
    end = i+0x40
    print ("%08x20%s" % (i/2,hexContent[i:end]))
    i = end

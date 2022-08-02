#-*- encoding: utf-8 from __future__ import unicode_literals
from itertools import cycle, izip
import re
import sys
import xorhack as xh
if len(sys.argv) == 3:
   f = open(sys.argv[1], 'rb')
   fname = str(sys.argv[1]) + '.' + str(sys.argv[2])
   fo = open(fname, "a")
   m = f.read().decode('utf-8')
   f.close()
   key = raw_input("key: ")
   c = ''
   c += xh.xor(m, key)
   fo.write(c.encode('utf-8'))
   fo.close()
else:
   print "Argument ERROR!"


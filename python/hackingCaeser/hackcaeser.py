#!/usr/bin/python
#-*- coding:utf-8 -*-
import sys
if len(sys.argv) == 3:
   fi = open(sys.argv[1], "r")
   c = fi.read().decode("utf-8").upper()
   f = str(sys.argv[1]) + '.' + str(sys.argv[2])
   fo = open(f, "a")
   a = u'АӘБВГҒДЕЖЗИЙКҚЛМНҢОӨПРСТУҰҮФХҺЦЧШЩЪЫІЬЭЮЯ'
   for key in range(len(a)):
      p = ''
      for let in c:
         if let in a:
            n = a.find(let)
            n = (n - key + len(a)) % len(a)   
            p = p + a[n]
      fo.write('key=%s: %s \n' % (key, p.encode("utf-8")))
   fi.close()
   fo.close()
else:
   print "Should be 3 arguments"
   print "python <name.py> <NameOfTextFile> <dec>"

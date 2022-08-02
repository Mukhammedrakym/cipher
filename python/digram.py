#!/usr/bin/python
#-*- coding:utf-8 -*-
import sys   #python <pythonFile.py> <fileneme>
a = u'АӘБВГҒДЕЖЗИЙКҚЛМНҢОӨПРСТУҰҮФХҺЦЧШЩЪЫІЬЭЮЯ'
f = open(sys.argv[1] , 'r') 

#print text
d={}
for i in a:
   for j in a:
      d[i + j] = 0
n = 0
for l in f:
   for k in d:
      d[k] += l.decode("utf-8").upper().count(k)
      n = n + 1
f.close()
print "Count of Bigrams in the text: ", n
print "Bigrams      Count      Persent"
for k in sorted(d, key = d.get, reverse = True):  
   persent = round((d[k] * 100.0 / n), 2) 
   print k, "         ", d[k], "       ", persent 

#!/usr/bin/python
#-*- coding: utf-8 -*-
import sys   #python <pythonFile.py> <fileneme>
alpha = u'АӘБВГҒДЕЖЗИЙКҚЛМНҢОӨПРСТУҰҮФХҺЦЧШЩЪЫІЬЭЮЯ'
f = open(sys.argv[1] , 'r') 
text = f.read()
text = text.decode('utf-8').upper()
f.close() 
#print text
k={}    
for i in alpha:     
   letter = 0
   for item in text:
      if item == i:
         letter = letter + 1
   k[i] = letter
n = 0
for i in alpha:      
   n = n + k[i]
print "Count of letters in file: ", n
print "Letters   Count   Percent"
for i in alpha:   
   persent = round((k[i] * 100.0 / n), 2)
   print i,"       ", k[i], "       ", persent

         

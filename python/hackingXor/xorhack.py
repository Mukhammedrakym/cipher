#!/usr/bin/python
# -*- encoding: utf-8 -*- from __future__ import unicode_literals
import re
import math
from sys import argv

def new_key(key, length):
   n = len(key)
   return (key * (length / n + 1))[:length]

def xor(m, key):
   enc = ''
   key = new_key(key, len(m))
   for i in range(len(m)):
      enc += unichr(ord(m[i]) ^ ord(key[i]))
   return enc

def shift_right(text, k):
   n = len(text)
   k = k % n
   k = n - k
   return text[k:] + text[:k]

def equal_symb(cipher, shift_text):
   c = 0
   for i in range(len(cipher)):
      if cipher[i] == shift_text[i]:
         c += 1
   return (c * 100.0) / len(cipher)

def find_key_length(cipher):
   d = []
   for i in range(1, len(cipher)):
      shiftText = shift_right(cipher, i)
      info = {
         "length": i,
         "match": equal_symb(cipher, shiftText),
         "shift": shiftText
      }
      d += [info]
   key_info = sorted(d, key = lambda item: item['match'], reverse = True)[0]
   return key_info['length']

def find_keys(cipher, key_len):
   blocks = [cipher[i:i+key_len] for i in range(0, len(cipher), key_len)]
   key = ''
   for i in range(key_len):
      freq = {}
      scaned_chars = 0
      for item in blocks:
	 if i < len(item):
	    char = xor(item[i], ' ')
	    if char in freq:
	       freq[char] += 1
	    else:
	       freq[char] = 1
	       scaned_chars += 1
		
      freq = {k: float(v) / scaned_chars for k, v in freq.items()}
      key_char = sorted(freq.items(), key = lambda item: item[1], reverse = True)[0]
      key += key_char[0]
   return key	

def find_key(string):
   r = re.compile(r"(.+?)\1+")
   return min(r.findall(string) or [""], key=len)	

if __name__ == '__main__':
   #"python xorhack.py text.txt.e out.txt"
   with open(argv[1], 'rb') as infile:
      cipher = infile.read().decode('utf-8')
   key_len = find_key_length(cipher)
   possible_key = find_keys(cipher, key_len)
   print "possible key: ", possible_key
   real_key = find_key(possible_key)
   
   print "Length of key: ", len(real_key)
   #print xor(cipher, possible_key)
   print "This text encoded by key: %s" % (real_key)
   dec = ''
   dec += xor(cipher, real_key)
   with open(argv[2], 'a') as outfile:
      outfile.write(dec.encode('utf-8'))
   infile.close()
   outfile.close()


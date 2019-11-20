# -*- coding: utf-8 -*-
"""
Created on Tue Jul 30 21:50:09 2019

@author: mateu
"""

while True:
    try:
        frase = input()
        pedaco = frase.split(' ')
        alient = False
        cont = 0
        ant = None
        for i in pedaco:
            if (ant and ant.lower() == i[0].lower() and alient == False):
                alient = True
                cont+=1
            elif(alient == True and ant.lower() != i[0].lower()):
                alient = False
            ant = i[0]
        
        print(cont)
    except EOFError:
        break
    
    
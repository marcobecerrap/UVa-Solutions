import sys

for InputLine in sys.stdin:
    InputNumber = int( InputLine )
    if InputNumber == 0:
        break
    if InputNumber == 1 or\
       InputNumber == 64 or\
       InputNumber == 729 or\
       InputNumber == 4096 or\
       InputNumber == 15625 or\
       InputNumber == 46656 or\
       InputNumber == 117649 or\
       InputNumber == 262144 or\
       InputNumber == 531441 or\
       InputNumber == 1000000 or\
       InputNumber == 1771561 or\
       InputNumber == 2985984 or\
       InputNumber == 4826809 or\
       InputNumber == 7529536 or\
       InputNumber == 11390625 or\
       InputNumber == 16777216 or\
       InputNumber == 24137569 or\
       InputNumber == 34012224 or\
       InputNumber == 47045881 or\
       InputNumber == 64000000 or\
       InputNumber == 85766121:
        print( 'Special' )
    else:
        print( 'Ordinary' )



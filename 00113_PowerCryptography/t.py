import sys

for InputRoot in sys.stdin:
    Root = int( InputRoot )
    Number = int( sys.stdin.readline() )

    Result = Number ** ( 1 / Root )
    
    print( round( Result ) )

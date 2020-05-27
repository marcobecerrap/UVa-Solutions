import sys

InputCases = int( sys.stdin.readline() )

for JJ in range( InputCases ):
    InputNumber = int( sys.stdin.readline() )
    Sequence = ''
    for TT in range( 1, InputNumber + 1 ):
        Sequence = Sequence + str( TT )
    SeqList = list( Sequence )
    print( SeqList.count('0'), SeqList.count('1'), SeqList.count('2'), SeqList.count('3'), SeqList.count('4'), SeqList.count('5'), SeqList.count('6'), SeqList.count('7'), SeqList.count('8'), SeqList.count('9'), )

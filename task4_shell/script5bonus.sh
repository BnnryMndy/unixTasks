i=0

while [ $i -lt $2 ]
do
	#DEBUG: echo $i
	i=`expr $i + 1`
	cat $1 >> "new_"$1
done
echo "__DONE__"
echo $1": " `wc -c < $1` "letters, " `wc -w < $1` "words, " `wc -l < $1` "strings."
echo "new_"$1": " `wc -c < new_$1` "letters," `wc -w <new_$1` "words, " `wc -l < new_$1` "srings."

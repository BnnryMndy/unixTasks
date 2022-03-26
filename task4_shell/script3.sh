if [ $# -lt 1 ]
then
	echo "empty"
	kill -9 $#
fi

if [ -f $1 ] 
then
	echo $1 "is file"
elif [ -d $1 ]
then
	echo $1 "is dir"
fi


if [ ! -d $2 ]
then
	echo "ERROR: this isn't dir blen"
	kill -9 $#
fi

cd $2

if [ $1 = "-d" ]
then
	echo "__dir mod__"
	ls -d */
elif [ $1 = "-f" ]
then
	echo "__file mod__"
	ls -p | grep -v /
fi


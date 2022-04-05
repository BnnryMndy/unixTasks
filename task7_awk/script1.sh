par=$#
if [ $par = 1 ]
then
	case $1 in
	1)
		cat file1 | awk '{print $1}'
		;;
	2)
		cat file1 | awk '{print $2}'
		;;
	3)
		cat file1 | awk 'NR > 1{print $1}'
		;;
	4)
		cat file1 | awk '{print $1":"$2}'
		;;
	*)
		echo "Not valid command"
		;;
	esac
else
	echo "Only 1 parametr"
fi

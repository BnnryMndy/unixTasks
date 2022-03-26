if [ $# -lt 1 ]
then
	echo "error: no args"
	kill -9 $#
fi

dir=$1
images=$(ls $dir | grep -e .jpg -e .jpeg | awk '{print $1}')
for img in $images
do
	name=$img
	date=$(exif $dir/$name | grep "Date and Time" | awk 'NR==1{print $4":"$5}')
	echo "$name -> $date-$name"
	cp "$dir/$name" "$dir/$date-$name"
done

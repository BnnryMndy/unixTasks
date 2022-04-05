par=$#
sum=0
if [ $par = 1 ]
then
	namemass=$(cat file3 | awk '{print substr($0,0,index($0,",")-1)}')
	scalemass=$(cat file3 | awk '{print substr($0,index($0,",")+1)}')
	case $1 in
	1)
		for i in $scalemass
		do
			sum=$(expr $i + $sum)
		done
		if [ $sum != 0 ]
		then
			echo "Total: $sum"
		else
			echo "Out of stock"
		fi
		;;
	2)
		echo "Input name:"
		read tname
		grscmass=$(cat file3 | grep $tname | awk '{print substr($0,index($0,",")+1)}')
		for i in $grscmass
		do
			sum=$(expr $i + $sum)
		done
		if [ $sum != 0 ]
		then
			echo "Total $tname : $sum"
		else
			echo "Out of stock"
		fi
		;;
	3)
		uniqmass=$(echo "")
		for i in $namemass
		do
			count=0
			for j in $uniqmass
			do
				if [ $i = $j ]
				then
					count=$(expr $count + 1)
				fi
			done
			if [ $count = 0 ]
			then
				uniqmass=$(echo "$uniqmass $i")
			fi
		done
		for i in $uniqmass
		do
			echo $i
		done
		;;
	4)
		uniqmass=$(echo "")
		exuniqmass=$(echo "")
		for i in $namemass
		do
			count=0
			supsum=0
			grscmass=$(cat file3 | grep $i | awk '{print substr($0,index($0,",")+1)}')
			for j in $grscmass
			do
				supsum=$(expr $j + $supsum)
			done
			for j in $uniqmass
			do
				if [ $i = $j ]
				then
					count=$(expr $count + 1)
				fi
			done
			if [ $count = 0 ]
			then
				uniqmass=$(echo "$uniqmass $i")
				exuniqmass=$(echo "$exuniqmass $i-$supsum")
			fi
		done
		for i in $exuniqmass
		do
			echo $i
		done
		;;
	5)
		uniqmass=$(echo "")
		for i in $namemass
		do
			count=0
			for j in $uniqmass
			do
				if [ $i = $j ]
				then
					count=$(expr $count + 1)
				fi
			done
			if [ $count = 0 ]
			then
				uniqmass=$(echo "$uniqmass $i")
			fi
		done
		for i in $uniqmass
		do
			supfmass=$(cat file3 | grep $i)
			echo "Names,Sales" > $i
			for j in $supfmass
			do
				echo $j >> $i
			done
		done
		;;
	6)
		uniqmass=$(echo "")
		exuniqmass=$(echo "")
		for i in $namemass
		do
			count=0
			supsum=0
			grscmass=$(cat file3 | grep $i | awk '{print substr($0,index($0,",")+1)}')
			for j in $grscmass
			do
				supsum=$(expr $j + $supsum)
			done
			for j in $uniqmass
			do
				if [ $i = $j ]
				then
					count=$(expr $count + 1)
				fi
			done
			if [ $count = 0 ]
			then
				uniqmass=$(echo "$uniqmass $i")
				exuniqmass=$(echo "$exuniqmass $i-$supsum")
			fi
		done
		echo "Names,Sales" > More300
		echo "Names,Sales" > Less300
		for i in $exuniqmass
		do
			checkawk=$(echo $i | awk 'substr($0,index($0,"-")+4,1)>=0 || substr($0,index($0,"-")+1,1)>=3 && substr($0,index($0,"-")+2,1)>=0 && substr($0,index($0,"-")+3,1)>=0 {print $1}');
			if [ $checcatkawk != "" ]
			then
				echo $i >> More300
			else
				echo $i >> Less300
			fi
		done
		;;
	*)
		echo "Not valid command"
		;;
	esac
else
	echo "Only 1 parametr"
fi

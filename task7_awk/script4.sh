mass=$(cat file4 | sed s/' '//g | sed s/'-'//g | sed s/'('//g | sed s/')'//g | sed s/'+'//g | sed s/'\.'//g | awk 'NR>1 {print $0}')
cat file4 | awk 'NR==1 {print $0}'
for i in $mass
do
	num=$(echo $i | awk '{print substr($0,index($0,";")+1)}')
	lennum=$(expr length $num)
	if [ $lennum = 11 ]
	then
		num=$(echo "$num")
	else
		num=$(echo "7$num")
	fi
	num=$(echo $num | awk '{print "+7("substr($0,2,3)")"substr($0,5,3)"-"substr($0,8,2)"-"substr($0,10)}')
	nam=$(echo $i | awk '{print substr($0,0,index($0,";"))}')
	echo "$nam$num"
done

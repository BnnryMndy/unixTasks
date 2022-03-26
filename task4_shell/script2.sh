echo "script name" $0
echo "PID:" $$
echo "params count: " $#
echo "params as string:" $*
echo "params as words:"
for i in $@
do
	echo $i
done

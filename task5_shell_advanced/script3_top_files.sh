echo "№\tsize\tdir\n---------------------"
du -h | sort -rn | head -n 10 | awk '$0=NR" "$0{print $1":""\t"$2"\t"$3"\n"}' | sed 'N;s/\n/ /g'

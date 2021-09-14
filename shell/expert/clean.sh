

function clean {
	filename=("*.o" "*.d" "*.gch" "*~"  "*.out" "core.*")
#	skip=()
	for name in ${filename[@]}; do
		#echo $name
	    find . -name $name -type f -print -exec rm -rf {} \;
	done 
}


clean

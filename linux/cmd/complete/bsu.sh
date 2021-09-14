
function __cmd_bsu() {
	local cur="${COMP_WORDS[COMP_CWORD]}"
	local options="$MAIN_COMMAND"
	COMPREPLY=( $(compgen -W "${options}" -- ${cur}) )
}

function __cmd_pushbaseline() {
	local cur="${COMP_WORDS[COMP_CWORD]}"
		COMPREPLY=()
	case $cur in
	--name=*)
		local options="NX01 NX02"
		COMPREPLY=( $(compgen -W "${options}" -- ${cur#--name=}) )
		;;
	--platform=*)
		local options="qcom mtk"
		COMPREPLY=( $(compgen -W "${options}" -- ${cur#--platform=}) )
		;;
	*) 
		local options="--platform= --name= --multi"
		COMPREPLY=( $(compgen -W "${options}" -- ${cur}) )
		;;
	esac	
}

function bsu() {
	case $1 in
	pushbaseline)
		shift
		__parsing_pushbaseline $@
		;;
	createrepo)
		shift
		__parsing_createrepo $@
		;;
	*)
		echo "unknown command $1"
		;;
	esac	
}

function __parsing_pushbaseline() {
	while [ $# -gt 0 ]; do
		case $1 in
			--platform=*)
			local platform=${1#--platform=}
		;;
		--name=*)
			local name=${1#--name=}
		;;
		--multi)
			local multi=1
			;;
		esac

		shift	
	done
	bsu_pushbaseline $platform $name $multi
}

function bsu_pushbaseline()
{
	echo bsu_pushbaseline $@
}

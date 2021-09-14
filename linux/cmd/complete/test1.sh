function __cmd_HUB() {
#$COMP_CWORD是系统自动变量，表示当前命令单词索引。 0表示第一个单词，也就是bsu。
	case $COMP_CWORD in
		0)	#仍在完成根命令，这里不需要处理
		;;
	1) #根命令已经完成，这里开始补充一级主命令
#${COMP_WORDS[0]}是根命令，在这个例子中就是bsu 
		eval __cmd_${COMP_WORDS[0]}
	;;
	2|*)#一级主命令已经完成，这里开始补充一级主命令的选项
#${COMP_WORDS[1]}是一级主命令，在这个例子中就是pushbaseline或者createrepo
		eval __cmd_${COMP_WORDS[1]}
	;;
	esac
}

complete -F __cmd_HUB bsu

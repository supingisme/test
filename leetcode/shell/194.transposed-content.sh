#194. 转置文件
#给定一个文件 file.txt，转置它的内容。
#
#你可以假设每行列数相同，并且每个字段由 ' ' 分隔.
#
#示例:
#
#假设 file.txt 文件内容如下：
#
#name age
#alice 21
#ryan 30
#应当输出：
#
#name alice ryan
#age 21 30

# Read from the file file.txt and print its transposed content to stdout.

#awk是一行一行地处理文本文件，运行流程是：
#
#先运行BEGIN后的{Action}，相当于表头
#再运行{Action}中的文件处理主体命令
#最后运行END后的{Action}中的命令
#有几个经常用到的awk常量：NF是当前行的field字段数；NR是正在处理的当前行数。
#
#注意到是转置，假如原始文本有m行n列（字段），那么转置后的文本应该有n行m列，即原始文本的每个字段都对应新文本的一行。我们可以用数组res来储存新文本，将新文本的每一行存为数组res的一个元素。
#
#在END之前我们遍历file.txt的每一行，并做一个判断：在第一行时，每碰到一个字段就将其按顺序放在res数组中；从第二行开始起，每碰到一个字段就将其追加到对应元素的末尾（中间添加一个空格）。
#
#文本处理完了，最后需要输出。在END后遍历数组，输出每一行。注意printf不会自动换行，而print会自动换行。

echo name age > file.txt
echo alice 21 >> file.txt
echo ryan 30 >> file.txt

awk '{
    for (i=1;i<=NF;i++){
        if (NR==1){
            res[i]=$i
        } else {
            res[i]=res[i]" "$i
        }
    }
}END{
    for(j=1;j<=NF;j++){
        print res[j]
    }
}' file.txt



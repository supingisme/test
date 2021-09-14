
ls /dev/pts/

for i in `ls /dev/pts`
do
echo Rong Tao say hi! > /dev/pts/$i
done

rm -f ex2.txt
rm -f -r week01 week10
mkdir week01
echo "Andrey" > ./week01/file.txt
mkdir week10
link ./week01/file.txt ./week10/_ex2.txt
inod=$(ls -i ./week01/file.txt|cut -c 1-17)
find . -inum $inod >> ex2.txt
find . -inum $inod -exec rm {} \; >> ex2.txt

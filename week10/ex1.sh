rm -f ./ex1.txt ./_ex1.txt ./_ex1_1.txt ./_ex1_2.txt
echo "Andrey" > _ex1.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
ls -i _ex1.txt _ex1_1.txt _ex1_2.txt >> ex1.txt

for i in {1..1000}
do
	b=$(tail -n 1 output.txt)
	echo "$(($b + 1))" >> output.txt
done

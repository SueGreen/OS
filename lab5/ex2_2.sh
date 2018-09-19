./ex2.sh &
while true; do
    if ! ln output.txt output.txt.lock
    then
      ./ex2.sh
        rm output.txt.lock;
        break
    else
        sleep 3
    fi
done

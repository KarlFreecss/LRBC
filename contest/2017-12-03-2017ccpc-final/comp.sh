echo "compliling"
g++ $1.cpp -W -g -o $1.exe
echo "compiled"
./$1.exe < $1.in

#! /bin/bash
if [ ! -d bin ]
then
	mkdir bin
fi
g++ *.cpp -o bin/a.out
if [ $? -eq 0 ] 
then
	if [[ "$1" == "-r" ]]
	then
		exec bin/a.out "${@:2}"
	fi
elif [[ "$1" == "-rf" ]]
then
	exec bin/a.out "${@:2}"
else
	echo "Complile Failed. Use -rf to run anyway"
fi

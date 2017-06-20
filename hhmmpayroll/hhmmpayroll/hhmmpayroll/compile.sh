#! /bin/bash
g++ *.cpp -o bin/a.out
if [[ "$1" == "-r" ]]
then
	exec bin/a.out "${@:2}"
fi

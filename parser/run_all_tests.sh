#!/bin/sh

for testfile in tests/good*.cminor
do
	if ./cminor -parse $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in tests/bad*.cminor
do
	if ./cminor -parse $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

#!/bin/bash

srcdir="/home/barmaco/workspace/project"
desdir="/home/barmaco/workspace/studyshell/test"

for file in "${srcdir}"/*
do
	#echo "${file}" 
	if test -d "${file}" 
	then
		cp -rf "${file}" "${desdir}"
	elif test -f "${file}"
	then
		cp -f "${file}" "${desdir}"
	fi
done

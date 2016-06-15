#http://www.runoob.com/linux/linux-shell-variable.html
#!/bin/bash

srcdir="/home/barmaco/workspace/project"
desdir="/home/barmaco/workspace/studyshell/test"

for file in "${srcdir}"/*			#循环
do
	#echo "${file}" 
	if test -d "${file}" 			#如果file存在并为文件夹
	then
		cp -rf "${file}" "${desdir}"	#复制文件夹
	elif test -f "${file}"			#如果file存在并为文件
	then
		cp -f "${file}" "${desdir}"
	fi
done

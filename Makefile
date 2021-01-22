preprocess:
	gcc -E shell.c -o shell.i

compile:
	gcc -S shell.i -o shell.s

assembly:
	gcc -c shell.s -o shell.o

linking:
	gcc  shell.o -o shell 

mkdir:
	gcc mkdir.c -o mkdir

ls:
	gcc ls.c -o ls

rm:
	gcc rm.c -o rm

date:
	gcc date.c -o date

cat:
	gcc cat.c -o cat

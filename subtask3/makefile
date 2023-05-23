all:
	g++ -c -Wall -Werror -fpic library.cpp
	ls
	g++ -shared -o libaudio.so library.o
	ls
	g++ -L/home/simran/Documents/code/subtask3: -Wall -o test main.cpp ./libaudio.so -o 	yourcode.out -lpthread -lm -ldl -lopenblas
	echo $LD_LIBRARY_PATH
	export LD_LIBRARY_PATH=/home/simran/Documents/code/subtask3:$LD_LIBRARY_PATH
	./yourcode.out b5cf6ea8_nohash_3.txt outputfile_txt
	./yourcode.out ca4d5368_nohash_5.txt outputfile_txt
	./yourcode.out 333784b7_nohash_0.txt outputfile_txt
	./yourcode.out 815f0f03_nohash_0.txt outputfile_txt
	./yourcode.out b2ae3928_nohash_1.txt outputfile_txt
	./yourcode.out b9cccd01_nohash_0.txt outputfile_txt
	./yourcode.out 3c257192_nohash_3.txt outputfile_txt
	./yourcode.out c7dc7278_nohash_3.txt outputfile_txt
	./yourcode.out 879a2b38_nohash_1.txt outputfile_txt
	./yourcode.out bb05582b_nohash_4.txt outputfile_txt


1:
	g++ -c -Wall -Werror -fpic lib_add.cpp lib_sub.cpp
	g++ -shared -o 
	.so lib_add.o lib_sub.o
	
	g++ -L/home/simran/Documents/code/subtask3 -Wall -o test m.cpp -lfoo
	
	echo $LD_LIBRARY_PATH
	
	export LD_LIBRARY_PATH=/home/simran/Documents/code/subtask3:$LD_LIBRARY_PATH
	./test





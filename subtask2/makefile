
normal:
	g++ main.cpp runnormal.cpp runmkl.cpp runopenblas.cpp -o yourcode.out -lpthread -lm -ldl -lopenblas
	./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt normal
mkl:
	g++ main.cpp runnormal.cpp runmkl.cpp runopenblas.cpp -o yourcode.out -lpthread -lm -ldl -lopenblas
	./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt mkl
openblas:
	g++ main.cpp runnormal.cpp runmkl.cpp runopenblas.cpp -o yourcode.out -lpthread -lm -ldl -lopenblas
	./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt openblas

plotnormal:
	gnuplot
	set style fill solid 0.25 border -1
	set style boxplot outliers pointtype 7
	set style data boxplot

	plot "runtimenormal.txt" using (1):1:(0.5):2
plotmkl:
	gnuplot
	set style fill solid 0.25 border -1
	set style boxplot outliers pointtype 7
	set style data boxplot

	plot "runtimemkl.txt" using (1):1:(0.5):2
plotopenblas:
	gnuplot
	set style fill solid 0.25 border -1
	set style boxplot outliers pointtype 7
	set style data boxplot

	plot "runtimeopenblas.txt" using (1):1:(0.5):2
clean:
	rm yourcode.out

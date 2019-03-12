ZdZdPlot.o : ZdZdPlot.C ZdZdPlot.h
	g++ -c  ZdZdPlot.C `root-config --cflags` `root-config --libs`

main_run :  main_run.cxx ZdZdPlot.o
	g++ -o main_run main_run.cxx ZdZdPlot.o  `root-config --cflags` `root-config --libs`


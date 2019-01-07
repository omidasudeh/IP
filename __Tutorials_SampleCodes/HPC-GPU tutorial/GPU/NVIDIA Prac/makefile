all: mat
#all: lab4p1_cuda
.PHONY : clean 
mat: 
	nvcc -O -o rotate image_work.cu  bmp_reader.o
clean:
	rm -rf *.o *.out

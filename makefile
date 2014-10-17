CXX = g++ -O3
FC = gfortran

objects= testFHT.o fftlog.o cdgamma.o drfftb.o drfftf.o drffti.o

run: $(objects)
	$(CXX) -o run $(objects) -lgfortran

.PHONY:clean
clean:
	rm *.o run
	

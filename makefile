testFHT:testFHT.o fht.o cdgamma.o drfftb.o drfftf.o drffti.o
	g++ -lgfortran testFHT.o fht.o cdgamma.o drfftb.o drfftf.o drffti.o -o testFHT
testFHT.o:testFHT.cpp
	g++ -o testFHT.o -c testFHT.cpp
fht.o:fftlog.f 
	gfortran -o fht.o -c fftlog.f
cdgamma.o:cdgamma.f
	gfortran -o cdgamma.o -c cdgamma.f
drfftb.o:drfftb.f
	gfortran -o drfftb.o -c drfftb.f
drfftf.o:drfftf.f
	gfortran -o drfftf.o -c drfftf.f
drffti.o:drffti.f
	gfortran -o drffti.o -c drffti.f
clean:
	rm *.o run
	

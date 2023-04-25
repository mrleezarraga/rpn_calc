rpn : bin/rpn_calc.o bin/io.o bin/stack.o
	gcc  bin/rpn_calc.o bin/io.o bin/stack.o -o bin/rpn
bin/stack.o :
	gcc -c stack.c -o bin/stack.o
bin/io.o :
	gcc -c io.c -o bin/io.o
bin/rpn_calc.o :
	gcc -c rpn_calc.c -o bin/rpn_calc.o
clean :
	rm -f bin/*
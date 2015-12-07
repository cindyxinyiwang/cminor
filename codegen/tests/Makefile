all: bounce fibonnacci maze good0 good1 good2 good3 good4 good5 good6 good7 good8 good9 good11 good12 good15 good16 good13 good14 good10 good17 good18 good19

bounce: bounce.o library.o gfx.o
	gcc $^ -o $@ -lX11 -lm

fibonnacci: fibonnacci.o library.o
	gcc $^ -o $@

maze: maze.o library.o
	gcc $^ -o $@

good13: good13.o library.o
	gcc $^ -o $@

good14: good14.o library.o
	gcc $^ -o $@

good19: good19.o library.o gfx.o
	gcc $^ -o $@ -lX11 -lm

good18: good18.o library.o
	gcc $^ -o $@

good17: good17.o library.o
	gcc $^ -o $@

good16: good16.o library.o
	gcc $^ -o $@

good15: good15.o library.o
	gcc $^ -o $@

good12: good12.o library.o
	gcc $^ -o $@

ood12: good12.o library.o
	gcc $^ -o $@

good11: good11.o library.o
	gcc $^ -o $@

good10: good10.o library.o
	gcc $^ -o $@

good9: good9.o library.o
	gcc $^ -o $@

good8: good8.o library.o
	gcc $^ -o $@

ood8: good8.o library.o
	gcc $^ -o $@

good0: good0.o library.o
	gcc $^ -o $@

good1: good1.o library.o
	gcc $^ -o $@

good2: good2.o library.o
	gcc $^ -o $@

good3: good3.o library.o
	gcc $^ -o $@

good4: good4.o library.o
	gcc $^ -o $@

good5: good5.o library.o
	gcc $^ -o $@

good6: good6.o library.o
	gcc $^ -o $@

good7: good7.o library.o
	gcc $^ -o $@

%.o: %.s
	gcc -c $< -o $@ -g

%.o: %.c
	gcc -c $< -o $@ -g

%.s: %.cminor
	echo "*** Make sure to put cminor in your PATH! ***"
	cminor -codegen $< $@

clean:
	rm -f *.o *.s *~ fibonnacci bounce maze

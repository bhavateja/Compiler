yacc -d test.y
lex test.l
gcc lex.yy.c y.tab.c
./a.out prgrm
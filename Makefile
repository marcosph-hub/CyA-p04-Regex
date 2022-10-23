main: main.cc
	g++ -std=c++14 -g -Wall -o p04-code_analyzer main.cc variables.cc statments.cc comments.cc main_program.cc

variables: variable.cc
	g++ -std=c++14 -g -Wall -o varibles variables.cc

statments: statments.cc
	g++ -std=c++14 -g -Wall -o statments statments.cc

comments: comments.cc
	g++ -std=c++14 -g -Wall -o comments comments.cc

main_program: main_program.cc
	g++ -std=c++14 -g -Wall -o main_program main_program.cc

clean:
	rm -f p04-code_analyzer

exec:
	./p04-code_analyzer factorial_function.cc code_schema.txt

all: ./a.out

compRun:
	g++ -std=c++11 main.cpp Stack.cpp Queue.cpp HashTable.cpp SocialMediaFeed.cpp  -o r.out

compTest:
	g++ -std=c++11 test.cpp  -o a.out

test: clean compTest; ./a.out

run: clean compRun; ./r.out

clean:
	rm -f *.out

FLAGS = -Wall -Werror -Wextra -std=c++17 -lstdc++

CLANG = clang-format --style=Google
CLANG_FILES = **/**/*.cc **/**/*.h **/*.cc **/*.h **/**/*.cpp **/**/**/*.cpp **/**/**/*.h

all: install

install:
	cmake -B build "view/3DViewer_2"
	cmake --build build --target 3DViewer_2 --parallel 8
	cp -R build/3DViewer_2.app ~/Desktop

uninstall:
	rm -rf build* 3DViewer_2 ~/Desktop/3DViewer_2.app

test: clean
	g++ $(FLAGS) tests/*.cc controller/*.cc model/sources/*.cc -lgtest -o test
	./test

clean:
	rm -rf build *.user view/build* *.gcno *.gcda *.info test report

dvi:
	open ../README_RUS.md

dist:
	mkdir archiv
	@cp -r controller model Makefile view archiv
	@tar -cf 3DViewer_2.tar archiv
	rm -rf archiv

gcov_report: clean
	g++ $(FLAGS) --coverage tests/*.cc controller/*.cc model/sources/*.cc -lgtest -o test
	./test
	lcov --ignore-errors inconsistent -t "test" -o test.info -c -d .
	lcov --remove test.info '/usr/*' -o test.info
	lcov --remove test.info '/model/headers/*' -o test.info
	lcov --remove test.info '/model/sources/model.cc' -o test.info
	lcov --remove test.info '/tests/*' -o test.info
	lcov --remove test.info '/controller' -o test.info
	genhtml -o report test.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.info test 

valgrind:
	docker build -t cont .
	docker run --name stock cont

clear:
	docker rm stock
	docker rmi cont

clang:
	$(CLANG) -i $(CLANG_FILES)
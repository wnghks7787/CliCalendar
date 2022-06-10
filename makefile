calendar: obj/calendar_function.o obj/calendar.o obj/todo_function.o obj/todo.o obj/main.o
	gcc obj/calendar_function.o obj/calendar.o obj/todo_function.o obj/todo.o obj/main.o -o calendar
obj/main.o: src/main.c src/selection.h
	gcc src/main.c -c -o obj/main.o
obj/todo.o: src/todo.c src/todo.h
	gcc src/todo.c -c -o obj/todo.o
obj/todo_function.o: src/todo_function.c
	gcc src/todo_function.c -c -o obj/todo_function.o
obj/calendar.o: src/calendar.c src/calendar.h
	gcc src/calendar.c -c -o obj/calendar.o
obj/calendar_function.o: src/calendar_function.c
	gcc src/calendar_function.c -c -o obj/calendar_function.o
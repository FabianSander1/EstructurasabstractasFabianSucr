
make:
	g++ mainn.cpp funciones.cpp -o empleados.exe
	.\empleados.exe

Doxyfile:
	@echo "GENERATE_HTML = YES" > Doxyfile
	@echo "GENERATE_LATEX = NO" >> Doxyfile
	@echo "PROJECT_NAME = Tarea3" >> Doxyfile
	@echo "EXTRACT_ALL = YES" >> Doxyfile

doc: Doxyfile
	doxygen Doxyfile
	@start "" ./html/index.html
	








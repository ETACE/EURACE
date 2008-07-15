all: dvi ps

function_transition_v1.ps:
	dot -Tps function_transition_v1.dot -o function_transition_v1.ps

function_transition_v2.ps:
	dot -Tps function_transition_v2.dot -o function_transition_v2.ps

cycle_function.ps:
	dot -Tps cycle_function.dot -o cycle_function.ps

function_dependence.ps:
	dot -Tps function_dependence.dot -o function_dependence.ps

images: function_transition_v1.ps function_transition_v2.ps cycle_function.ps function_dependence.ps

spell:
	ispell d11_main.tex

dvi: 
	latex d11_main
	bibtex d11_main
	latex d11_main
	latex d11_main

ps: dvi
	dvips -t a4 d11_main.dvi -o d11_main.ps

clean:
	rm -f d11_main.aux d11_main.bbl d11_main.blg d11_main.dvi d11_main.log d11_main.lof d11_main.lot d11_main.toc d11_main.ps 
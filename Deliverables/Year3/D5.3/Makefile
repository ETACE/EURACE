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
	aspell -c -t D53_main.tex
	aspell -c -t credit.tex
	aspell -c -t conclusions.tex
	aspell -c -t general.tex
	aspell -c -t introduction.tex
	aspell -c -t labour.tex
	aspell -c -t testing.tex

dvi: 
	latex D53_main
	bibtex D53_main
	latex D53_main
	latex D53_main

ps: dvi
	dvips -t a4 D53_main.dvi -o D53_main.ps

clean:
	rm -f *.aux D53_main.bbl D53_main.blg D53_main.dvi D53_main.log D53_main.lof D53_main.lot D53_main.toc D53_main.ps 
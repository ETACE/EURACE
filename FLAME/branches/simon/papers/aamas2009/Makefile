all: dvi ps

#function_transition_v1.ps:
#	dot -Tps function_transition_v1.dot -o function_transition_v1.ps

#images: function_transition_v1.ps function_transition_v2.ps cycle_function.ps function_dependence.ps

spell:
	aspell -c -t coakley_aamas2009.tex

dvi: 
	latex coakley_aamas2009
	bibtex coakley_aamas2009
	latex coakley_aamas2009
	latex coakley_aamas2009

ps: dvi
	dvips -t a4 coakley_aamas2009.dvi -o coakley_aamas2009.ps

clean:
	rm -f *.aux coakley_aamas2009.bbl coakley_aamas2009.blg coakley_aamas2009.dvi coakley_aamas2009.log coakley_aamas2009.lof coakley_aamas2009.lot coakley_aamas2009.toc coakley_aamas2009.ps 
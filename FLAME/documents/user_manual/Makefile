all: dvi ps

household_fsm_v1.ps: household_fsm_v1.dot
	dot -Tps household_fsm_v1.dot -o household_fsm_v1.ps

household_fsm_v1.1.ps: household_fsm_v1.1.dot
	dot -Tps household_fsm_v1.1.dot -o household_fsm_v1.1.ps

household_fsm_v2.ps: household_fsm_v2.dot
	dot -Tps household_fsm_v2.dot -o household_fsm_v2.ps

household_fsm_v3.ps: household_fsm_v3.dot
	dot -Tps household_fsm_v3.dot -o household_fsm_v3.ps

household_fsm_v3.1.ps: household_fsm_v3.1.dot
	dot -Tps household_fsm_v3.1.dot -o household_fsm_v3.1.ps

findajob_fsm.ps: findajob_fsm.dot
	dot -Tps findajob_fsm.dot -o findajob_fsm.ps

keratinocyte_fsm.ps: keratinocyte_fsm.dot
	dot -Tps keratinocyte_fsm.dot -o keratinocyte_fsm.ps

labourmarket_fsm_v2.ps: labourmarket_fsm_v2.dot
	dot -Tps labourmarket_fsm_v2.dot -o labourmarket_fsm_v2.ps

labourmarket_fsm_v3.ps: labourmarket_fsm_v3.dot
	dot -Tps labourmarket_fsm_v3.dot -o labourmarket_fsm_v3.ps

images: household_fsm_v1.ps household_fsm_v1.1.ps household_fsm_v2.ps household_fsm_v3.ps household_fsm_v3.1.ps findajob_fsm.ps keratinocyte_fsm.ps labourmarket_fsm_v2.ps labourmarket_fsm_v3.ps

spell:
	ispell usermanual.tex

dvi:
	latex usermanual
	bibtex usermanual
	latex usermanual
	latex usermanual

ps: dvi
	dvips -t a4 usermanual.dvi -o usermanual.ps

clean:
	rm -f *.aux usermanual.bbl usermanual.blg usermanual.dvi usermanual.log usermanual.lof usermanual.lot usermanual.toc *.ps

MAKEFLAGS += --silent --no-print-directory

LATEXMK = latexmk
RM = rm -f
FIND = find

SOURCES := $(wildcard ${CURDIR}/*.tex)
TARGETS := $(patsubst %.tex, %.pdf, $(SOURCES))

all: doc
doc: pdf
pdf: $(TARGETS)

%.pdf: %.tex
	$(LATEXMK) -pdf -cd -silent -M -MP -MF $*.depends $*

%.sty: ../%.sty
	cp $^ $@

prune:
	$(LATEXMK) -silent -c
	$(RM) *.bbl

clean:
	${FIND} . -type f \( -name '*.pdf' -o -name '*.aux' -o -name '*.log' -o -name '*.synctex.gz' \) -delete
	${FIND} . -type f \( -name '*.fls' -o -name '*.fdb_latexmk' \) -delete
	$(RM) *.depends


-include *.depends

.PHONY:
	all doc pdf prune clean
MAKEFLAGS += --silent --no-print-directory

FIND = find

TARGET_DIR = Target

all: doc
doc: pdf

pdf:
	+$(MAKE) -C Lehrplansemester-04/Betriebssysteme pdf
	+$(MAKE) -C Lehrplansemester-04/Algorithmen-und-Datenstrukturen pdf

prune:
	+$(MAKE) -C Lehrplansemester-04/Betriebssysteme prune
	+$(MAKE) -C Lehrplansemester-04/Algorithmen-und-Datenstrukturen prune

clean:
	+$(MAKE) -C Lehrplansemester-04/Betriebssysteme clean
	+$(MAKE) -C Lehrplansemester-04/Algorithmen-und-Datenstrukturen clean
	@[ -e $(TARGET_DIR) ] && $(FIND) $(TARGET_DIR) -type f -name '*.pdf' -delete || true
	@[ -e $(TARGET_DIR) ] && rmdir $(TARGET_DIR) || true

artifacts: pdf
	mkdir -p ${TARGET_DIR}
	cp Lehrplansemester-04/Algorithmen-und-Datenstrukturen/Algorithmen-und-Datenstrukturen.pdf ${TARGET_DIR}
	cp Lehrplansemester-04/Betriebssysteme/Betriebssysteme.pdf ${TARGET_DIR}

.PHONY:
	all doc pdf prune clean

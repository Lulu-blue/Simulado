JC = javac
JVM = java
SRC = src
BIN = bin
MAIN = benchmark.HeapSortBenchmark

compile:
	$(JC) -d $(BIN) $(SRC)/benchmark/*.java $(SRC)/model/**/*.java $(SRC)/no/*.java

run:
	$(JVM) -cp $(BIN) $(MAIN)

clean:
	rm -rf $(BIN)/*

jar:
	jar cvfm HeapSortBenchmark.jar MANIFEST.MF -C bin .

.PHONY: compile run clean jar
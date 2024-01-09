this an attempt to create:

1- inverted index
2- query search 


**further work is needed to read files to memory for memory effiency reasons. 


instructions:

part a: to compile the codes:

g++ index.cpp -o index

g++ query.cpp -o query


part b: to run the exe files:

./index wsj1-mini.docstream my_index

this will generate the index.

./query my_index "hello"

this, for example, to searh for the term "hello" in the inverted index. 


hope it helps :)

-Adel

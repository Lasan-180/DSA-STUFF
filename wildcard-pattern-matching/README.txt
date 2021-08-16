MEMBER INFORMATION
-------------------------------------------------------------------------------------
19001802	2019/CS/180	V.D.L.W Vithanage	lasanthiwathsala473@gmail.com


USAGE
--------------------------------------------------------------------------
Windows : c++ (wild_card_string_matching.cpp)
Three text files used : text.txt	pattern.txt	pattenmatch.output


EXPLANATION
--------------------------------------------------------------------------------------------------------
The program take 3 command line arguments : text.txt file, pettern.txt file, patternmatch.output file
The program opens a text.txt file and pattern.txt file first. Then do the matching and fine index positions
of the matchings. Then the program open patternmatch.output file and write the relevant positions output
in that file.

***String matching algorithm used to modify this problem : "Naive string matching algorithm"
I used naive string matching algorithm to find the starting points of the indexes of the
matchings and write it to the output file in the "find function" of my c++ file. I have 
chosen naive algorithm and modify it as the requirements of the wildcard pattern matches.

***Reasons behind the choosing naive string matching algorithm : The concept behind the naive algorithm 
to find patterns is very simple and easy to understand. So it can be modified and converted into the
problem of wildcard matchings.We used "_" this underscore sign to recognize the wildcards.Naive algorithm 
skip the underscore sign "_" and go to the next character if it finds the "_" sign. Other string matching 
algorithms are very complex and can not be modified easily because it need more logical and complex 
changes. Through the reliability and simple behavior of the naive string matching algorithm I used it.

Complexity of the used algorithm : o(xy)
where x is the length of the pattern and the y is the length of the text.

Code has been deeply explained in the "code_explanation.pdf" file in the zip file.


RUNNING TESTS
-----------------------------------------------------------------------------------
*Tests are scripted and can be executed with the "wild_card_string_matching.cpp" file.

*windows: c++ : wild_card_string_matching.cpp

*Input files are located inside the "Testdata" directory of the zipfile.
ex: text1.txt, pattern1.txt, patternmatch1.output

Respective file paths of text,pattern and patternmatch output files are stored in the 
"wild_card_string_matching.cpp" file.When the "wild_card_string_matching.cpp" script is 
run it read the relevant text file and pattern file and check whether there is a wild card
pattern match is there and the recognize the starting positions of the wild card pattern
matches in the text.Then the index positions are write on the output console as well as
the index positions are also written in the relevant paternmatch output file.

*Screenshots of the relevant output console is stored at "Screenshots.pdf" file in the
zip file.

For this assignment i have used 11 text files, 11 pattern files and 11 patternmatch
output files."wild_card_string_matching.cpp" file get the data already stored in the
11 text files and 11 pattern files one by one with the help of a for loop and match
them to identify any matches. After the output(positions of matches) are written in to 
11 patternmatch output files.


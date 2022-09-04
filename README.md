# Spell-check
*This is one of the CS50 projects that I did.*  

This program can spell-checks a text file, using a **hash table**

This program is meant for practice in pset5 of CS50x. One of the course from Harvard University.

UNDERSTANDING:

Theoretically, on input of size *n*, an algorithm with a running time of *n* is “asymptotically equivalent,” in terms of O, to an algorithm with a running time of *2n*. Indeed, when describing the running time of an algorithm, we typically focus on the dominant (i.e., most impactful) term (i.e., n in this case, since *n* could be much larger than 2). In the real world, though, the fact of the matter is that *2n* feels twice as slow as *n*.

When implementing speller.c, the program will *load* ```large```(a default dictionary with 143,091 words) into a **hash table**, it also will counts the number of words - *size* in the dictionary. After that, it will *check* word by word from the text file which we want, print out the misspelled ones, then *unload* the **hash table**. Beside that, the program also count the time in each part such as *load*, *check*, *size*, *unload*. Because the challenge here for my project is to implement the fastest spell checker I can.

At the end, it will print as this format:
```
WORDS MISSPELLED:

WORDS IN DICTIONARY:

WORDS IN TEXT:

TIME IN load:


TIME IN check:

TIME IN size:

TIME IN unload:

TIME IN TOTAL:
```

IMPLEMENTATION:

You can create your own dictionary in ```small``` in ```dictionaries``` folder

Execution example:

```
./speller dictionaries/large texts/lalaland.txt
```

And you could then run the staff’s solution on the same text in another window, as with the below.


```
./speller50 texts/lalaland.txt
```

And you could then compare the windows visually side by side. That could get tedious quickly, though. So you might instead want to “redirect” your program’s output to a file, as with the below.

```
$ ./speller texts/lalaland.txt > student.txt
$ ./speller50 texts/lalaland.txt > staff.txt
```




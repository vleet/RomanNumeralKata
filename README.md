#Roman Numeral Calculator

For this Kata, you will be creating a library which will allow the addition and subtraction of
Roman numerals. Once your solution is complete, please provide your solution as a Git
repository (publicly available via Github or Bitbucket). Please include within your repository, all
source and test code.

##The solution will be reviewed for:
- Test coverage
- Algorithms
- Code structure
- Use of source control - Overall solution

##The environment for this kata is the following:
- Ubuntu Linux
- The C programming language
- GNU GCC compiler tool chain
- GNU Make
- Check unit testing framework ( https://libcheck.github.io/check/ )
- git

##Roman Numeral rules:
- Numerals can be concatenated to form a larger numeral ("XX" + "II" = "XXII").
- In the Roman numeral system, the basic "digits" are the letters I, V, X, L, C, D, and M which represent the same numbers regardless of their position.
- Symbols are placed in order of value, starting with the largest values.
- When the higher numeral is placed before a lower numeral, the values of each Roman numeral are added.
- When smaller values precede larger values, the smaller values are subtracted from the larger values, and the result is added to the total.
- Do not repeat I, X, and C more than three times in a row. (Number 4 on a Roman numeral clock is usually written as IIII. )
- Symbols V, L, and D cannot appear more than once consecutively. ("D" + "D" = "M" not “DD”).
- Do not subtract a number from one that is more than 10 times greater: I may only precede V and X, X may only precede L and C, and C may only precede D and M.

##Stories

###User Story: Addition
As a Roman bookkeeper
I want to be able to add two numbers together
So that I can do my work faster with fewer mathematical errors.

###User Story: Subtraction
As a Roman bookkeeper
I want to be able to subtract a number from another
So that I can do my work faster and with fewer mathematical errors.

This Kata is based on the Roman Numeral Calculator Kata at http://bit.ly/1VfHqlj

---
### this assumes you already have 'docker engine' installed
execute the following in order to build a proper Docker image and execute
```
docker build -t ubuntu-roman .
```
after the 'build' step is complete
```
docker run -it -v your/path/:/tmp ubuntu-roman /bin/bash
```
```
cd /tmp
make clean && make
```

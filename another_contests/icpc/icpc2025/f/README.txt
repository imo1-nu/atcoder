This problem may have multiple answers.
One of the answers for each input data is provided in *.ans file.
The C++ source code of a judge program is also provided as
output_checker.cc and testlib.h.

Usage of the judge program (let output_checker.out be the executable file name):

output_checker.out <input data> <program output> <answer file>

<input data> is the input file (*.in file in this directory).
<program output> is the file storing the output of your program for the
input data <input data>.
<answer file> is the corresponding answer file to the input file (*.ans
in this directory).
If the <program output> is a correct answer for the <input data>,
output_checker.out exits with exit code 0, which is stored in $? shell variable.
Otherwise, it displays an error message and exits with a non-zero exit code.

Example:

If your program is "solve" and execute it with input 01.in,

> ./solve < 01.in > 01.out
> ./output_checker.out 01.in 01.out 01.ans
(no command should be executed between output_checker.out and echo)
> echo $?

Being displayed 0 by the command "echo $?", your program answered
correctly for input 01.in.

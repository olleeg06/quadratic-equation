My project can solve quadratic equations. You can enter the coefficients of an equation like a * x^2 + b * x + c = 0 and the program will give you the answer.

The program is useful because you don't have to enter the coefficients manually. You can have a file with the coefficients and the program will be able to read them all and give you the answers.

To start working with the project, you must download all the files from the "square" folder (5 cpp files, 5 hpp files and 1 Makefile). To work with the files, you must either download my file, change the coefficients in it to your own or have your own ready-made file. First, you need to compile the files via Makefile with the "make all" command in the terminal. Then you get a file (in my case, "result)". After that, in the same terminal, enter "./result" and the commands. There are 4 of them: help, test, solution and file <name>.

The first command is "help". It displays all possible commands.

The second command is "test". At this point, the code is checked and the output shows how many tests were successful.

Using the third command "solution" we can manually enter the equation coefficients and we will get the answer.

The fourth command "file <name>" reads commands from a file. In <name> you must enter the name of the file from which you are going to receive the coefficients. The command will process and output the answers to all equations.

When entering a non-existent command, you will be prompted with all existing commands.

To contact me, you can write to the mail dontsov12345678908@mail.ru

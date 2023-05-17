miniLibC is a project aiming to implement fonctions with x86-64 Assembler.
Theses fonctions are to be made into a library usable by C code.

The provided code is the testing area of each made fonctions meant to copy the behaviour
of already existing C fonctions.

The ones with an underscore in their names are the x86-64 version.

To see the results of the battery test, simply launch the the program like so :

./miniLibC

notes:
the behaviour intended to copy from strcmp was an earlier version where the fonction only replied by
-1/0/1 instead of a value representing the ASCII difference between the two arguments.

To run this program you need to have nasm installed in order to compile and run x86-64 Assembler code

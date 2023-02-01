# Unique-visitors
The task is to develop a program that processes log and analyzes unique visits.

Assume we register all visits to our WWW server. In particular, we register the users that access our server. Each user is given an unique id - an integer in the range [ 0 ; 99999 ]. The program is given the information on user access via the registration command, the command has the form + id, e.g.,

+ 123
+ 456
+ 123
+ 123
+ 789

Here, user 123 accessed our server in positions 0, 2 and 3, user 456 accessed the server in position 1 and user 789 accessed the server in position 4.
Next, we need to compute the unique users that accessed our server in a given range of time, For the sake of simplicity, we consider the position instead of time. The computation is requested by the analyze command. The command has the form ? from to where from and to are integer positions from where / to where compute the unique users. For the example above, a request ? 0 4 results in answer 3 / 5 (3 unique users in the range of length 5).

The input of the program is a list of commands to register mixed with commands to analyze the stored data. The program processes the input, stores the registrations and answers the analyze requests. The processing terminates when there is an error in the input or when all data are processed (EOF). There is at most 1000000 registration commands in the input.

The output of the program is:

the information on the visit # for the registration command,
the information on unique users / total range length for the analyze command.
The program must validate input data. If the input is invalid, the program must detect it, it shall output an error message (see below), and terminate. If displayed, the error message must be sent to the standard output (do not send it to the error output) and the error message must be terminated by a newline (\n). The registration command is considered invalid, if:

user id is missing,
id is not an integer,
id is not in the range [ 0 ; 99999 ], or
there is more than 1000000 visits registered with the registration command.
The analyze command is invalid, if:

from or to is missing,
from / to are not integers,
from is smaller than 0,
to is greater or equal to the number of visits registered so far, or
from is greater than to.
Obviously, the input is also rejected if the command is neither registration nor analyze.

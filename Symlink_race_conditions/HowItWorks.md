This is a very basic and simple simulation of a race condition between the couple system calls access() and open() via symlink().

# Explanation
Access() system call checks whether a process can access the file_1, if it returns 0 the access() allows the process to read/write/execute a certain file given as file_1.

After we gain the permission to handle the file_1 we switch it with another file of the same name linked to a "dangerous" file (e.g. /etc/passwd), this is file_2.

When open() is invoked it actually opens the file linked to file_2 (e.g. /etc/passwd or any file specified as file_2).


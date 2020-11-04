# Explanation

We stat() the file_1 information and we check if its UID is 0, if it is, it means the owner of that file is ROOT so we can't access it; otherwise we can open the file.

So what if we want to open a file which is owned by ROOT?
We simply give as input a regular file (with UID != 0) which not belongs to ROOT, doing so it gives us the allowance to bypass the checking (if UID == 0).

The race condition occurs between the checking and the opening of the file.

After bypassing the checking, we swap the file_1 with file_2 (see attack.c). 

When open() is invoked it actually opens file_2 (e.g. /etc/passwd or any file specified as file_2).

That's it! We now have opened to a file we couldn't have access to with normal permission. 

# SecurityHW
In this assignment, we will demonstrate different ways of concealing malware to fool malware detection software.
PE-Import.exe is the original file we will be altering in various ways.

## PE-Import.exe
The function of this file is to determine whether there is a PE-1.txt file containing the string "I want to learn PE file format!". If there is a file, then the executable will simply return that string contained in the file. However, if the file does not already exist, the executable will create that file.

## Packing
Packing/Unpacking is the practice of compressing/decompressing a file. By doing this to a file, the computer will regard the uncompressed and compressed files as distinct files despite the fact that they are the same program.

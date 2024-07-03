# Get Next Line

This project involves programming a function that returns a line read from a file descriptor, using a new type of variable: a static variable, which persists in the heap even after the function call is over.

The get_next_line() function will be useful for reading lines one by one from any file or even from the standard input. This means that with this function, it is possible to handle any input from the user. Each time the function is called, it will return the next line

This function looks like this:

```
char *get_next_line(int fd);
```

* Return value: The next line of the file, including the newline character \n if it exists. Returns NULL if an error occurred or there are no more lines.
* Parameters:
    * fd: The file descriptor to read from, which should have been previously opened in the program.

### Implementation

Despite appearing to be a short function at first glance, it hides a bit more complexity than it seems. This function uses the [read()](https://man7.org/linux/man-pages/man2/read.2.html) function to get the next N characters of the file. The tricky part is that the number of characters read() gets per call, also known as the buffer, is determined by the user and not the programmer. This is a problem because the buffer can be smaller or larger than what the next line requires. To address this problem, I use a static variable:

* If the buffer is shorter, we call read() repeatedly until we find a \n. Each time we make that call, we concatenate the buffer to our main line, a char * data type that we use to save the whole line.
* If the buffer is bigger or equal, we only call the read() function once.

Once we have this raw line, we split it into two parts: the string we want to return and the static variable, which is the string that will persist in heap memory until the next call to the function is made. We use this technique because if the function get_next_line (GNL) is called again, the read() will begin from where we left off, so the characters between the \n and the end of the buffer would not be lost.

### Bonus

The bonus section of the subject requires handling multiple file descriptors simultaneously, allowing for the opening and reading of different files within the same program. To achieve this, I created an array of static variables, with as many arrays as the system's OPEN_MAX allows using the macro OPEN_MAX. While this may not be the most efficient approach, it is the fastest one and does not significantly impact resource usage.

### Considerations

It is important to handle the situation where the end of the file is reached, and the get_next_line function is called. If, for some reason, the static variable is empty and points to NULL (perhaps it is the first call of the function, or the last call was precise enough that the last character in the buffer was a \n), I initialize the static variable with just a \0 inside. If, after reading the file, that string is still just \0 and nothing else, then the variable is freed and the function returns NULL.

Important: Imagine using this function but not calling it enough times to read the whole file. This would lead to an unreachable memory leak because there is an "alive" static variable loaded into the heap memory. To prevent this memory leak, the get_next_line function can be called one last time using a closed file descriptor as a parameter. This way, an error will occur while reading the file, so the program will free the static variable, set it to NULL, and return.

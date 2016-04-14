# ask
##### Simple utility to ask the user a question during a shell script
## Usage:
`ask -m <message> -d <default option> -o <option1> -o <option2> ...`

  - Returns number of option selected (0 for first, 1 for second...)
  - Returns -1 on invalid selection
  - Returns -2 after displaying the help message

#### Script Usage:
```
#!/bin/bash
if ask -m "are you sure" -o y -o n -d n
    rm -rf ~/
else
    echo "Coward!"
fi
```

### Options:
 `-o x` add answer `x` to the question (max 1 char)
 
 `-m str` set message to `str`
 
 `-d x` set default answer to `x`
 
 `-h` show help message
## Building:
This program is built with make and GCC.
  1. To build run `make`
  2. Manually copy into /usr/bin (or your prefered path directory)
  3. Optionally just package the binary with your scripts (It's only about 13K)

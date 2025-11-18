# Terminal Display Image
Allows you to view images from the terminal *(no gui needed)*

> [!NOTE]
> This uses true color to set colors. Most modern terminals impliment this however some older ones do not

## Features
- Prints images to terminal as coloured ascii 
- Auto resizes to best fit terminal

## Usage
```
dimg {FILE}
```

> [!NOTE]
> This uses the half slab character `▀` `▄` which most teminals print well. depending on your terminal there may be some irregularities in the output

## Installation
**Step 1** - Download files/clone repo

**Step 2** - Run `make` command to compile c code

**Step 3** - Test the program with `./dimg images/hd.jpg`

**Step 4** *(Optional)* - Set command alias with `alias dimg="/path/to/src/dimg"`
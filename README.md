# Terminal Display Image
Allows you to view images from the terminal *(no gui needed)*

> [!NOTE]
> This uses true color to set colors. Most modern terminals impliment this however some older ones do not

## Features
- Prints images to terminal as coloured ascii 
- Auto resizes to best fit terminal

## Usage
```
Usage: dimg [FILE] [DISPLAY OPTIONS]

Display options:
  -w, --max-width #    Maximum width of the outputed image in character spaces. This supports % values
  -h, --max-height #   Maximum height of the outputed image in character spaces. This supports % values
      --upper-slab     Print pixels using upper half slab '▀'
      --lower-slab     Print pixels using lower half slab '▄'
      --lower-slab     Print pixels using lower half slab '▄'
      --two-space      Print pixels using two spaces '  ' (this is more compatible but reduces image resolution 2x) 

Misc options:
      --help           Prints this message
```

## Examples
```
# print images/cat with 50% of the terminal width
dimg images/cat.png -w 50%

# print dog.png with the two space display method
dimg dog.png --two-space

# print /img/image.jpg with a height of 10 lines 
dimg /img/image.jpg -h 10
```

> [!NOTE]
> This uses the half slab character `▀` `▄` which most teminals print well. depending on your terminal there may be some irregularities in the output

## Installation
**Step 1** - Clone repo
```
git clone https://github.com/stratisco/Terminal-Display-Image.git
```

**Step 2** - Navigate to base directory
```
cd Terminal-Display-Image
```

**Step 3** - Compile c code
```
make
```

**Step 4** *(Optional)* - Test the program
```
./dimg images/hd.jpg
```

**Step 5** *(Optional)* - Set command alias
```
echo "alias dimg='/path/to/Terminal-Display-Image/dimg'" >> ~/.bashrc
source ~/.bashrc
```


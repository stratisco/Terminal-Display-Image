<p align="center">
  <img 
      src="images/post_example_small.png" 
      alt="example_low_res" 
      width="30%" 
      height="30%"
      decoding="async"
      fetchpriority="high"
  />
</p>

# Terminal Display Image
Prints images to the terminal using coloured ascii characters. This is the easiest way to view images from a terminal only envoriment *(no gui needed)*

> [!IMPORTANT]
> This program uses 24-bit *true color* to change terminal colors. This feature is supported by most modern terminals. For more info check out [this repo](https://github.com/termstandard/colors)

## Features
- Allows you to view images in terminal
- Auto scales to best fit terminal
- Has different display methods to further compatibility

| Original Image | Default output | Lower width output |
| :-------: | :------: | :------: |
| <img src="images/example.png" width="200" height="200"/> | <img src="images/post_example_normal.png" width="200" height="200"/> | <img src="images/post_example_small.png" width="200" height="200"/> |


## Usage
```
Usage: dimg [FILE] [DISPLAY OPTIONS]

Display options:
  -w, --max-width #    Maximum width of the outputed image in character spaces. This supports % values
  -h, --max-height #   Maximum height of the outputed image in character spaces. This supports % values
      --upper-slab     Print pixels using upper half slab '▀'
      --lower-slab     Print pixels using lower half slab '▄'
      --two-space      Print pixels using two spaces '  ' (this is more compatible but reduces image resolution 2x) 

Misc options:
      --help           Prints this message
```

## Examples
```
# print images/cat.png with 50% of the terminal width
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
./dimg images/example.jpg
```

**Step 5** *(Optional)* - Set command alias
```
echo "alias dimg='/path/to/Terminal-Display-Image/dimg'" >> ~/.bashrc
source ~/.bashrc
```


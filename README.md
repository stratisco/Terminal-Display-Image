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


# Christmas Tree

This program generates a randomly-sized ASCII art christmas tree. The program allows for two optional command-line arguments:

- Size of the tree (defaults to a random size between 3 and 17)
- Snow mode, which controls how snow appears in the output (defaults to "in foreground")

If your tree is large enough, you might spot additional ASCII art, such as presents, an owl, or a mysterious creature carrying a gift.


## Usage

To run the program, use the following command syntax:

./tree [-t tree_height] [-s snow_mode]

Where:

-t tree_height: Optional argument to specify the height of the tree. It must be an integer between 3 and 17. If not provided, the program will randomly generate a tree height within this range.

-s snow_mode: Optional argument to control the snow effect. You can choose from the following modes:

- f: Snow in the foreground of the picture (default if no argument is provided).
- b: Snow in the background of the picture.
- a: "Acid" snow — watch the picture slowly get destroyed by snowflakes (this was definitely not a bug that I thought looked cool).
- n: No snow effect.




# Christmas Tree

This program generates a randomly-sized ASCII art Christmas tree. The size of the tree can be customized, and the tree can feature additional animations like snow or random ASCII art creatures. The program allows for two optional command-line arguments:

- Size of the tree (defaults to a random size between 3 and 17)
- Snow mode, which controls how snow appears in the output (defaults to "in foreground")

If the tree is large enough, there is also a chance that additional ASCII art may appear, such as presents, an owl, or a mysterious creature bearing a gift.


## Usage

To run the program, use the following command syntax:

./tree [-t tree_height] [-s snow_mode]

Where:

-t tree_height: Optional argument to specify the height of the tree. It must be an integer between 3 and 17. If not provided, the program will randomly generate a tree height within this range.

-s snow_mode: Optional argument to control the snow effect. You can choose from the following modes:

- f: Snow in the foreground of the picture (default if no argument is provided).
- b: Snow in the background of the picture.
- a: "Acid" snow — watch the picture slowly get destroyed by snowflakes. (This was definitely not a bug that I thought looked cool!)
- n: No snow effect.




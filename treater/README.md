# Treater

## An application designed for keeping track of places visited and opinions of them.

### Running the program:
  * Obviously, clone the repository.
  * In a terminal, navigate to the `treater` project.
  * Create a `data` directory in the root directory:
  ```
  you@linux:~/path/to/treater$ mkdir data
  ```
  * Create a `data.txt` file:
  ```
  you@linux:~/path/to/treater$ cd data && touch data.txt
  ```
  * Navigate back to the `treater` directory:
  ```
  you@linux:~/path/to/treater/data$ cd ../
  ```
  * Run the following:
  ```
  you@linux:~/path/to/treater$ clear && make compile && ./bin/treater
  ```
  

### Main Menu
Chose from 3 options:
  * Add Review
  * List Reviews
  * Quit
 
### Add Review
This is for recording information about a place visited.
  * Add a Name
  * Add an Address
  * Add a Type (Restaurant, Games, etc.)
  * Add a Review (0-5 stars)
  * Add Items Experienced
  * Add a Return Factor (0-10)
  
### List Reviews
This is for listing all of the previous Reviews created.
  * Scroll down with the down arrow key. You will scoll all the way down until you get to `Next Page`. `Next Page` will not be highlighted, but when it is the currently highlighted item, the next set of items will render.
  * Scroll up with the up arrow key. You will scoll all the way up until you get to `Previous Page`. `Previous Page` will not be highlighted, but when it is the currently highlighted item, the previous set of items will render.
  
### Quit
  * Quits the program
  
*Note*: This application functions, but is still a work in progress. You can successfully add a Review and list all Review's, but I will be going through and cleaning up things. This project was meant to learn C++ and finish an application using `NCurses`.

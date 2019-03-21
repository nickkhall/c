# Treater
An application for managing and maintaining visited places, to keep track of personal reviews of an establishment.

----

## Classes
  * Establishment
    * Name - string
    * Address - string
    * Type - string
    * Review (0-5 stars) - int
    * Items experienced - vector< string >
    * Return Factor - boolean

  * User
    * Name - string

  * Menu
    * Type - string
    * Items - vector< string >
    * Choice - int
    * yPos - int
    * xPos - int

  * Interface
    * inputs - vector< string >
    * label - string

### As A User
  1. Starts out seeing the Main Menu.

  2. Selects from Menu:
    - Add Review
    - List Reviews
    - Quit

  3.
    - `2.1.` <h4>Add Review</h4>
      - User inputs name of establishment
      - User inputs type of establishment
      - User inputs address of establishment
      - User inputs items experienced at establishment
      - User inputs review (0-5 stars) of establishment
      - User inputs return factor of establishment (yes or no)

    - `2.2` <h4>List Review</h4>
      - User sees detailed table to previous reviews
      - User can search for previous reviews by:
        - name
        - address

    - `2.3` <h4>Quit</h4>
      - User quits the program

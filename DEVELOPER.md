# Project 2 - Part B
## Data Structures
The key data structures used are arrays, pointers, objects, and websockets

# Files
There are 5 files in this project
- CellularAutomaton.h is a header file that contains a class declaration for a CellularAutomaton object
- CellularAutomaton.cpp is a file that implements the methods specified in CellularAutomaton.h
- GraphicsClient.h is a header file that contains a class declaration for a GraphicsClient object
- GraphicsClient.cpp is a file that implements the method associated with it as defined in the GraphicsClient.h file
- casimulator.cpp is a file containing a main method that gets input and simulates a 2DCA accordingly, displaying the CA on a window connected to a graphics server, and has a function to represent Conway's game of life for the CA
# Functions
## CellularAutomaton
- `CellularAutomaton(std::string file, int qstate)` is a constructor that creates a CellularAutomaton object based on the given file
- `CellularAutomaton(int qstate, int width, int height)` is a constructor that creates a CellularAutomaton object with the given width and height
- `CellularAutomaton(const CellularAutomaton &other)` is a copy constructor that creates a new CellularAutomaton based on an existing object
- `CellularAutomaton operator=(const CellularAutomaton &rhs)` is an assignment = operator that sets the values of one CellularAutomaton equivalent to another
- `void Step(unsigned char (*)(unsigned char, unsigned char**, int, int, int, int, int))` is a function that updates the values that represent the states of a 2DCA according to the given rule
- `void displayCA(GraphicsClient &window)` is a function that displays the 2DCA on a given graphics window
- `~CellularAutomaton()` is the destructor for the CellularAutomaton object
- `void clear();` sets all values in the given CA to 0
- `void randomize();` sets all values in the CA to a random value
- `void reset();` sets all values in the CA to their original values
- `int getHeight();` returns the height of the CA
- `int getWidth();` returns the width of the CA
- `int getCellSize();` returns the size of each Cell in the CA
- `int getGapSize();` returns the size of the gaps between cells in the CA
- `void setCell(int,int);` changes the value of the cell at the given indexes
## GraphicsClient
- `GraphicsClient(std::string, int)` constructs a new GraphicsClient object with the given url and port number
- `GraphicsClient(const GraphicsClient &other)` creates a new GraphicsClient object that is a copy of an existing object
- `GraphicsClient operator=(const GraphicsClient &rhs)` Sets an existing GraphicsClient object to have values equal to another existing object
- `~GraphicsClient()` destructs the graphics client object
- The Following methods send signals to the graphics server to produce visuals in the window
   - 
- `void setBackgroundColor(int, int, int)`
- `void setDrawingColor(int, int, int)`
- `void clear()`
- `void setPixel(int, int, int, int, int)`
- `void drawRectangle(int, int, int, int)`
- `void fillRectangle(int, int, int, int)`
- `void clearRectangle(int, int, int, int)`
- `void drawOval(int, int, int, int)`
- `void fillOval(int, int, int, int)`
- `void drawLine(int, int, int, int)`
- `void drawString(int, int, string)`
- `void repaint()`
- `void loadFile();`
- `void getBytes(char *);` reads the bytes that are currently waiting to be read into the array located at the given pointer
- `int getBytesReady();` returns the number of bytes waiting to be read
- `int isPaused();` returns true if the simulator is paused
- `int isRunning();` returns true if the simulator hasn't been exited
- `void pause();` pauses the simulator
- `void play();` resumes te simulator
- `void quit();` exits the simulator
- `string getFilePath(char *, int);` returns the path to a file chosen from the explorer
- `int click(char *);` handles respones from the server based on the instruction stored at the given pointer


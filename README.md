# Dijkstras-Shortest-Path-on-Train-Routes-Between-Citites
C++ program to demonstrate Dijkstra's Shortest Path Algorithm on a weighted and directed graph where city train stations are the nodes and routes between departure cities and arrival cities are the edges

### Usage
This program prompts the user with the following options:
  "Enter any key to find shortest train routes from a source city to reachable arrival cities
  Or select one of the options below:
  Q Quit
  ? Help"
  
 The Q option terminates the program 
 The ? option presents a help page to inform the user about the program and the appropriate input format to utilize it
 When any other key is entered, the default option to perform Dijkstra's is selected 

Once the default option is selected, the user will first provide the total number of cities involved
  "Enter number of cities:"
  
The user will be prompted for the route information X times (where X is the number of cities provided previously)
  "Enter departure city and its arrival cities with distances"
 Each time, the program expects a line starting with a departure city name followed by each of its arrival cities with distances.
 Each city is separated by commas and each line must also end with a comma.
 An example of the formatted command line input is:
   "Los Angeles,New York(2789.42),Chicago(2015.40),"
  - where Los Angeles is the Departure city that has a route to arrival city New York 2789.42 miles away and another route to Chicago with a distance of 2015.40 miles.
  - commas separate each city and also distinguishes the end of one input line
 
 Once all lines of input are taken, the program will ask for the city for which Dijkstra's algorithm will find all shortest train routes from that city to all reachable cities based on the routes given previously.
 "Enter source city name:"
 
The program will print the initialized values of the graph before finding shortest routes
Then it will print the final result with all arrival cities and the shortest paths to each from the source city provided



*To test this program, download this project and run it on any IDE compatible with C++ programs or test it on Replit through this link:


 

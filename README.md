# Dijkstras-Shortest-Path-on-Train-Routes-Between-Citites
C++ program to demonstrate Dijkstra's Shortest Path Algorithm on a weighted and directed graph where city train stations are the nodes and routes between departure cities and arrival cities are the edges

### Usage
This program prompts the user with the following options: <br/>
  "Enter any key to find shortest train routes from a source city to reachable arrival cities <br/>
  Or select one of the options below: <br/>
  Q Quit <br/>
  ? Help" <br/>
  
- The Q option terminates the program <br/>
- The ? option presents a help page to inform the user about the program and the appropriate input format to utilize it <br/>
- When any other key is entered, the default option to perform Dijkstra's is selected  <br/>

Once the default option is selected, the user will first provide the total number of cities involved <br/>
  "Enter number of cities:"
  
The user will be prompted for the route information X times (where X is the number of cities provided previously) <br/>
  "Enter departure city and its arrival cities with distances" <br/>
 Each time, the program expects a line starting with a departure city name followed by each of its arrival cities with distances. 
 Each city is separated by commas and each line must also end with a comma. <br/>
 An example of the formatted command line input is: 
   "Los Angeles,New York(2789.42),Chicago(2015.40),"
  - where Los Angeles is the Departure city that has a route to arrival city New York 2789.42 miles away and another route to Chicago with a distance of 2015.40 miles.
  - commas separate each city and also distinguishes the end of one input line  <br/>
 
 Once all lines of input are taken, the program will ask for the city for which Dijkstra's algorithm will find all shortest train routes from that city to all reachable cities based on the routes given previously. <br/>
 "Enter source city name:" <br/>
 
The program will print the initialized values of the graph before finding shortest routes <br/>
Then it will print the final result with all arrival cities and the shortest paths to each from the source city provided



**To test this program, download this project and run it on any IDE compatible with C++ programs**

## Test Cases
###### Input 1:<br/>
3 //Number of cities <br/>
Chicago,New York(611.20), //route <br/>
New York,, //route <br/>
Los Angeles,New York(2789.42),Chicago(2015.40), //route <br/>
Los Angeles //source city <br/>

Expected Output 1:<br/>
Initialized graph before Dijsktra's:<br/>
City Name      d Value     PI             Arrival City List<br/>
New York       0.00        No parent      Arrival city list is empty<br/>
Los Angeles    30000.00    No parent      Chicago(2015.40)New York(2789.42)<br/>
Chicago        30000.00    No parent      New York(611.20)<br/>

Print the Dijkstra algorithm running result<br/>
Source City: Los Angeles<br/>
Arrival City  Shortest Dist. Shortest Path <br/>
Los Angeles    0.00           Los Angeles<br/>
Chicago        2015.40        Los Angeles->Chicago<br/>
New York       2626.60        Los Angeles->Chicago->New York<br/>

Input 2:<br/>
5 <br/>
Chicago,Duluth(502.71),El Paso(1487.51),Atlanta(718.19), <br/>
Duluth,El Paso(1527.35), <br/>
El Paso,Phoenix(429.03),Duluth(1527.35),<br/>
Atlanta,Duluth(27.64),Chicago(720.14),<br/>
Phoenix,Chicago(1753.78),Atlanta(1814.81),<br/>
Phoenix<br/>

Expected Output 2:<br/>
Initialized graph before Dijsktra's:<br/>

City Name      d Value     PI             Arrival City List<br/>
Phoenix        0.00        No parent      Atlanta(1814.81)Chicago(1753.78)<br/>
Chicago        30000.00    No parent      Atlanta(718.19)Duluth(502.71)El Paso(1487.51)<br/>
El Paso        30000.00    No parent      Duluth(1527.35)Phoenix(429.03)<br/>
Atlanta        30000.00    No parent      Chicago(720.14)Duluth(27.64)<br/>
Duluth         30000.00    No parent      El Paso(1527.35)<br/>

Print the Dijkstra algorithm running result<br/>

Source City: Phoenix<br/>

Arrival City  Shortest Dist. Shortest Path  <br/>
Phoenix        0.00           Phoenix<br/>
Chicago        1753.78        Phoenix->Chicago<br/>
Atlanta        1814.81        Phoenix->Atlanta<br/>
Duluth         1842.45        Phoenix->Atlanta->Duluth<br/>
El Paso        3241.29        Phoenix->Chicago->El Paso<br/>

Input 3: <br/>

Expected Output 3:<br/>


Input 4: <br/>

Expected Output 4:<br/>




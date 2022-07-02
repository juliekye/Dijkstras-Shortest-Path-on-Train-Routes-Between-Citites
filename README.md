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
#### Input 1:<br/>
3 //Number of cities <br/>
Chicago,New York(611.20), //route <br/>
New York,, //departure city with no arrival cities <br/>
Los Angeles,New York(2789.42),Chicago(2015.40), //route <br/>
Los Angeles //source city <br/>

#### Expected Output 1:<br/>
Initialized graph before Dijsktra's:<br/>
City Name  &emsp;     d Value &emsp;     PI     &emsp;        Arrival City List<br/>
New York   &emsp;     0.00    &emsp;     No parent &emsp;     Arrival city list is empty<br/>
Los Angeles  &emsp;   30000.00  &emsp;   No parent  &emsp;    Chicago(2015.40)New York(2789.42)<br/>
Chicago  &emsp;       30000.00  &emsp;   No parent   &emsp;   New York(611.20)<br/>

Print the Dijkstra algorithm running result<br/>
Source City: Los Angeles<br/>
Arrival City &emsp; Shortest Dist. &emsp;Shortest Path <br/>
Los Angeles &emsp;  0.00   &emsp;        Los Angeles<br/>
Chicago    &emsp;   2015.40    &emsp;    Los Angeles->Chicago<br/>
New York   &emsp;   2626.60    &emsp;    Los Angeles->Chicago->New York<br/>

#### Input 2:<br/>
5 <br/>
Chicago,Duluth(502.71),El Paso(1487.51),Atlanta(718.19), <br/>
Duluth,El Paso(1527.35), <br/>
El Paso,Phoenix(429.03),Duluth(1527.35),<br/>
Atlanta,Duluth(27.64),Chicago(720.14),<br/>
Phoenix,Chicago(1753.78),Atlanta(1814.81),<br/>
Phoenix<br/>
 
#### Expected Output 2:<br/>
Initialized graph before Dijsktra's:<br/>

City Name  &emsp;     d Value &emsp;     PI     &emsp;        Arrival City List<br/>
Phoenix   &emsp;      0.00     &emsp;    No parent   &emsp;    Atlanta(1814.81)Chicago(1753.78)<br/>
Chicago  &emsp;       30000.00  &emsp;   No parent   &emsp;    Atlanta(718.19)Duluth(502.71)El Paso(1487.51)<br/>
El Paso   &emsp;      30000.00  &emsp;   No parent   &emsp;    Duluth(1527.35)Phoenix(429.03)<br/>
Atlanta   &emsp;      30000.00   &emsp;  No parent   &emsp;    Chicago(720.14)Duluth(27.64)<br/>
Duluth    &emsp;      30000.00  &emsp;   No parent     &emsp;  El Paso(1527.35)<br/>

Print the Dijkstra algorithm running result<br/>

Source City: Phoenix<br/>

Arrival City &emsp; Shortest Dist. &emsp;Shortest Path <br/>
Phoenix &emsp;        0.00    &emsp;        Phoenix<br/>
Chicago  &emsp;       1753.78  &emsp;       Phoenix->Chicago<br/>
Atlanta  &emsp;       1814.81  &emsp;       Phoenix->Atlanta<br/>
Duluth  &emsp;        1842.45  &emsp;       Phoenix->Atlanta->Duluth<br/>
El Paso   &emsp;      3241.29   &emsp;      Phoenix->Chicago->El Paso<br/>

#### Input 3: <br/>
8
Buffalo,Washington(401.54),Columbus(3025.19),Albany(293.76),
Albany,Boston(364.72),
Boston,New York(214.5),
New York,Washington(225.70),
Columbus,Washington(402.80),Seattle(2418.50),
San Diego,Columbus(2224.30),
Seattle,San Diego(1255.34),Columbus(2420.30),Buffalo(2599.0),
Washington,New York(225.70),San Diego(2625.30),
Seattle

#### Expected Output 3:<br/>
City Name  &emsp;     d Value &emsp;     PI     &emsp;        Arrival City List<br/>
Buffalo        30000.00    No Parent      Albany(293.76),Columbus(3025.19),Washington(401.54),
Albany         30000.00    No Parent      Boston(364.72),
Boston         30000.00    No Parent      New York(214.50),
New York       30000.00    No Parent      Washington(225.70),
Columbus       30000.00    No Parent      Seattle(2418.50),Washington(402.80),
San Diego      30000.00    No Parent      Columbus(2224.30),
Seattle        30000.00    No Parent      Buffalo(2599.00),Columbus(2420.30),San Diego(1255.34),
Washington     30000.00    No Parent      New York(225.70),San Diego(2625.30),

Print the Dijkstra algorithm running result

Source City: Seattle

Arrival City &emsp; Shortest Dist. &emsp;Shortest Path <br/>
Seattle        0.00           Seattle
San Diego      1255.34        Seattle->San Diego
Columbus       2420.30        Seattle->Columbus
Buffalo        2599.00        Seattle->Buffalo
Washington     2823.10        Seattle->Columbus->Washington
Albany         2892.76        Seattle->Buffalo->Albany
New York       3048.80        Seattle->Columbus->Washington->New York
Boston         3257.48        Seattle->Buffalo->Albany->Boston


#### Input 4: <br/>
12
Denver,Salt Lake(350.5),Santa Fe(180.24),Dallas(475.62),Chicago(620.78),
Phoenix,Seattle(470.67),
Santa Fe,Phoenix(275.32),Austin(572.18),
Austin,Dallas(350.24),
Dallas,Austin(250.18),Miami(560.89),Denver(550.6),Atlanta(780.5),
Atlanta,Washington(420.24),Miami(320.61),Dallas(860.28),
Chicago,Denver(570.19),
Washington,New York(250.37),
Seattle,New York(1320.52),Salt Lake(325.45),
Salt Lake,Phoenix(450.18),Santa Fe(379.2),
New York,Chicago(320.5),
Miami,Atlanta(457.6),
Seattle

#### Expected Output 4:<br/>
City Name  &emsp;     d Value &emsp;     PI     &emsp;        Arrival City List<br/>
Denver         30000.00    No Parent      Chicago(620.78),Dallas(475.62),Salt Lake(350.50),Santa Fe(180.24),
Phoenix        30000.00    No Parent      Seattle(470.67),
Santa Fe       30000.00    No Parent      Austin(572.18),Phoenix(275.32),
Austin         30000.00    No Parent      Dallas(350.24),
Dallas         30000.00    No Parent      Atlanta(780.50),Austin(250.18),Denver(550.60),Miami(560.89),
Atlanta        30000.00    No Parent      Dallas(860.28),Miami(320.61),Washington(420.24),
Chicago        30000.00    No Parent      Denver(570.19),
Washington     30000.00    No Parent      New York(250.37),
Seattle        30000.00    No Parent      New York(1320.52),Salt Lake(325.45),
Salt Lake      30000.00    No Parent      Phoenix(450.18),Santa Fe(379.20),
New York       30000.00    No Parent      Chicago(320.50),
Miami          30000.00    No Parent      Atlanta(457.60),

Print the Dijkstra algorithm running result

Source City: Seattle

Arrival City &emsp; Shortest Dist. &emsp;Shortest Path <br/>
Seattle        0.00           Seattle
Salt Lake      325.45         Seattle->Salt Lake
Santa Fe       704.65         Seattle->Salt Lake->Santa Fe
Phoenix        775.63         Seattle->Salt Lake->Phoenix
Austin         1276.83        Seattle->Salt Lake->Santa Fe->Austin
New York       1320.52        Seattle->New York
Dallas         1627.07        Seattle->Salt Lake->Santa Fe->Austin->Dallas
Chicago        1641.02        Seattle->New York->Chicago
Denver         2177.67        Seattle->Salt Lake->Santa Fe->Austin->Dallas->Denver
Miami          2187.96        Seattle->Salt Lake->Santa Fe->Austin->Dallas->Miami
Atlanta        2407.57        Seattle->Salt Lake->Santa Fe->Austin->Dallas->Atlanta
Washington     2827.81        Seattle->Salt Lake->Santa Fe->Austin->Dallas->Atlanta->Washington


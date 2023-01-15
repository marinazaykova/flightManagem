#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

static const char* const FILENAME_PLANE_CLASSES = "C:\\Users\\marin\\CLionProjects\\FlightManagement\\PlaneClasses.txt";
static const char* const FILENAME_PLANES = "C:\\Users\\marin\\CLionProjects\\FlightManagement\\Planes.txt";
static const char* const FILENAME_FLIGHTS = "C:\\Users\\marin\\CLionProjects\\FlightManagement\\Flight.txt";

class PlaneClass{
private:
    int id;
    string name;
    string manufacturer;
    string model;
    int numberOfSeats;
    double minLengthOfRunway;
    double averageSpeed;
    double maxTankCapacityInLiter;
    vector<string> possibleDestinations;

public:
    PlaneClass();
    PlaneClass(int id, string name, string manufacturer, string model, int numOfSeats, double minLenRunway,
               double speed, double maxTank, vector<string> destinations);
    PlaneClass(int id, string name, string manufacturer, string model,
               int numOfSeats, double minLenRunway, double speed, double maxTank);
    PlaneClass(const PlaneClass &plane1);

    int getId() const {
        return id;
    }

    void setId(int id) {
        PlaneClass::id = id;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        PlaneClass::name = name;
    }

    const string &getManufacturer() const {
        return manufacturer;
    }
    void setManufacturer(const string &manufacturer) {
        PlaneClass::manufacturer = manufacturer;
    }

    const string &getModel() const {
        return model;
    }
    void setModel(const string &model) {
        PlaneClass::model = model;
    }

    int getNumberOfSeats() const {
        return numberOfSeats;
    }
    void setNumberOfSeats(int numberOfSeats) {
        PlaneClass::numberOfSeats = numberOfSeats;
    }

    double getMinLengthOfRunway() const {
        return minLengthOfRunway;
    }
    void setMinLengthOfRunway(double minLengthOfRunway) {
        PlaneClass::minLengthOfRunway = minLengthOfRunway;
    }

    double getAverageSpeed() const {
        return averageSpeed;
    }
    void setAverageSpeed(double averageSpeed) {
        PlaneClass::averageSpeed = averageSpeed;
    }

    double getMaxTankCapacityInLiter() const {
        return maxTankCapacityInLiter;
    }

    void setMaxTankCapacityInLiter(double maxTankCapacityInLiter) {
        PlaneClass::maxTankCapacityInLiter = maxTankCapacityInLiter;
    }

    const vector<string> &getPossibleDestinations() const {
        return possibleDestinations;
    }

    void setPossibleDestinations(const vector<string> &possibleDestinations) {
        PlaneClass::possibleDestinations = possibleDestinations;
    }

    friend std::ostream & operator << (std::ostream &out, const PlaneClass & obj)
    {
        out << "Plane class " << obj.id << ": " << obj.name << "\nManufacturer: " << obj.manufacturer <<
            ", Model: "<< obj.model << ", Number of seats: " << obj.numberOfSeats <<
            "\nLength Of Runway: " << obj.minLengthOfRunway << "km, Average speed: " <<obj.averageSpeed<<
            "km/h, Fuel tank capacity: " << obj.maxTankCapacityInLiter << "l" << endl;

        return out;
    }

};
vector<PlaneClass> getClassesFromFile();
PlaneClass baseClass(0, "Base", "", "", 0, 0, 0,0, vector<string> {});

PlaneClass::PlaneClass(int id, string name, string manufacturer, string model, int numOfSeats, double minLenRunway, double speed,
                       double maxTank, vector<string> destinations) {
    PlaneClass::id = id;
    PlaneClass::name = name;
    PlaneClass::manufacturer = manufacturer;
    PlaneClass::model = model;
    PlaneClass::numberOfSeats = numOfSeats;
    PlaneClass:: minLengthOfRunway = minLenRunway;
    PlaneClass:: averageSpeed = speed;
    PlaneClass::maxTankCapacityInLiter = maxTank;
    for (const string &item: destinations) {
        possibleDestinations.push_back(item);
    }
}
PlaneClass::PlaneClass(const PlaneClass &plane1) {
    id = plane1.id;
    name = plane1.name;
    manufacturer = plane1.manufacturer;
    model = plane1.model;
    numberOfSeats = plane1.numberOfSeats;
    minLengthOfRunway = plane1.minLengthOfRunway;
    averageSpeed = plane1.averageSpeed;
    maxTankCapacityInLiter = plane1.maxTankCapacityInLiter;
    for (const string &item: plane1.possibleDestinations) {
        possibleDestinations.push_back(item);
    }
}

PlaneClass::PlaneClass(int id, string name, string manufacturer, string model, int numOfSeats,
                       double minLenRunway, double speed, double maxTank) : id(id), name(name),
                       manufacturer(manufacturer), model(model), numberOfSeats(numOfSeats),
                       minLengthOfRunway(minLenRunway), averageSpeed(speed),
                       maxTankCapacityInLiter(maxTank){}



class Plane{
private:
    int id;
    double costsPerEmployee;
    int numberOfEmployees;
    int costsForFuel;
    PlaneClass planeClass = baseClass;
public:
    Plane(double costsPerEmployee, int numberOfEmployees, double costsForFuel);
    Plane();
    Plane(const Plane &plane1);

    int getId() const {
        return id;
    }
    void setId(int id) {
        Plane::id = id;
    }

    const PlaneClass &getPlaneClass() const {
        return planeClass;
    }
    void setPlaneClass(const PlaneClass &planeClass) {
        Plane::planeClass = planeClass;
    }

    double getCostsPerEmployee() const {
        return costsPerEmployee;
    }
    void setCostsPerEmployee(double costsPerEmployee) {
        Plane::costsPerEmployee = costsPerEmployee;
    }

    int getNumberOfEmployees() const {
        return numberOfEmployees;
    }
    void setNumberOfEmployees(int numberOfEmployees) {
        Plane::numberOfEmployees = numberOfEmployees;
    }

    int getCostsForFuel() const {
        return costsForFuel;
    }
    void setCostsForFuel(int costsForFuel) {
        Plane::costsForFuel = costsForFuel;
    }

    double getCostsForAllEmployees() const{
        return getNumberOfEmployees() * getCostsPerEmployee();
    }

    bool checkIfPlaneIsSuitableForDestination(string destination) const;

    friend ostream &operator<<(ostream &output, const Plane &plane) {
        output << "Plane with id: " << plane.id << "\nClass " << plane.planeClass.getId() <<
            ": " << plane.planeClass.getName() << ", Number of Employees: " << plane.numberOfEmployees <<
            "\nFuel Expenses for 1km: " << plane.getCostsForFuel() <<
            "lv, Expenses For Employees: " << plane.getCostsForAllEmployees() << "lv.\n";
        return output;
    }

};
vector<Plane> getPlanesFromFile();
Plane basePlane(0, 0, 0);

Plane::Plane() {
    vector<Plane> allPlanes = getPlanesFromFile();
    if(allPlanes.size() == 0) {
        id = 1;
    } else {
        id = allPlanes.size() + 1;
    }
    cout << "Insert the costs spent for paying one employee: " << endl;
    cin >> costsPerEmployee;
    if(costsPerEmployee <= 50) {
        costsPerEmployee = 0;
        throw std::invalid_argument("Invalid data for costs for employees! Must be more than 50!");
    }
    cout << "Insert the number of employees on the plane during flight: " << endl;
    cin >> numberOfEmployees;
    if(numberOfEmployees <= 2) {
        numberOfEmployees = 0;
        throw std::invalid_argument("Invalid number of employees! Must be at least 3!");
    }
    cout << "Insert the costs for fuel: " << endl;
    cin >> costsForFuel;
    if(costsForFuel <= 10) {
        costsForFuel = 0;
        throw std::invalid_argument("Invalid number for costs for fuel! Must be more than 10!");
    }
    vector<PlaneClass> classes = getClassesFromFile();
    cout << endl << "Choose from current plane classes:" << endl;
    cout << "1.First-Class/2.Business Class/3.Premium Economy Class" << endl;
    int opt;
    cin >> opt;
    switch(opt) {
        case 1:
            setPlaneClass(classes[0]); break;
        case 2:
            setPlaneClass(classes[1]); break;
        case 3:
            setPlaneClass(classes[2]); break;
        default:
            throw std::invalid_argument("Invalid operation! Choose between 1 and 3!");
    }
}

Plane::Plane(const Plane &plane1) {
    id = plane1.id;
    planeClass = plane1.planeClass;
    costsPerEmployee = plane1.costsPerEmployee;
    numberOfEmployees = plane1.numberOfEmployees;
    costsForFuel = plane1.costsForFuel;
}

Plane::Plane(double costsPerEmployee, int numberOfEmployees, double costsForFuel)
        : costsPerEmployee(costsPerEmployee), numberOfEmployees(numberOfEmployees),
          costsForFuel(costsForFuel) {
}

bool Plane::checkIfPlaneIsSuitableForDestination(string destination) const{
    vector<string> possibleDest = getPlaneClass().getPossibleDestinations();
    if(!count(possibleDest.begin(), possibleDest.end(), destination)) {
        return false;
    }
    return true;
}

class Flight{
private:
    string destination;
    double lengthOfFlightInKm;
    Plane plane = basePlane;
public:
    Flight();
    Flight(const string &destination, double lengthOfFlightInKm);
    Flight(const Flight &flight);

    const Plane &getPlane() const {
        return plane;
    }
    void setPlane(const Plane &plane) {
        Flight::plane = plane;
    }

    const string &getDestination() const {
        return destination;
    }
    void setDestination(const string &destination) {
        Flight::destination = destination;
    }

    double getLengthOfFlightInKm() const {
        return lengthOfFlightInKm;
    }
    void setLengthOfFlightInKm(double lengthOfFlightInKm) {
        Flight::lengthOfFlightInKm = lengthOfFlightInKm;
    }

    int getDuration() const{
        return (int)(lengthOfFlightInKm / plane.getPlaneClass().getAverageSpeed());
    }

    long getAllCostsForFuel() const{
        double costsForFuel = plane.getCostsForFuel() * (lengthOfFlightInKm + plane.getPlaneClass().getMinLengthOfRunway());
        return (long)costsForFuel;
    }

    friend std::ostream & operator << (std::ostream &out, const Flight & obj)
    {
        out << "Flight to destination: " << obj.destination << "\nLength of flight: " << obj.lengthOfFlightInKm <<
            "km, Average duration of flight: " << obj.getDuration() <<
            "h\nPlane class " << obj.plane.getPlaneClass().getId() << ": " << obj.plane.getPlaneClass().getName() <<
            "\nNumbers of employees on board: " << obj.plane.getNumberOfEmployees() <<
            "\nAll costs for employees: " << obj.plane.getCostsForAllEmployees() << "lv, All costs for fuel: " <<
            obj.getAllCostsForFuel() << "lv.\n";

        return out;
    }
};
Flight baseFlight("", 1);

Flight::Flight() {
    vector<Plane> allPlanes = getPlanesFromFile();
    cout << "Insert destination of the flight: " << endl;
    cin >> destination;
    cout << "Insert length of flight in km: " << endl;
    cin >> lengthOfFlightInKm;
    if(lengthOfFlightInKm <= 0) {
        throw std::invalid_argument("Length cannot be less than 0!\n");
    }
    cout << endl << "Choose from current planes by entering the id of the plane:" << endl;
    cout << "Current ids: 1 - " << allPlanes.size() << endl;
    int id;
    cin >> id;
    if(id < 1 || id > allPlanes.size()) {
        throw std::invalid_argument("Invalid plane id! No such plane is registered!\n");
    }
    for (const auto &planeCurr: allPlanes) {
        if(planeCurr.getId() == id) {
            vector<string> destinationsToCheck = planeCurr.getPlaneClass().getPossibleDestinations();
            if(std::find(destinationsToCheck.begin(), destinationsToCheck.end(),
                         destination) != destinationsToCheck.end()) {
                cout << "Connecting the chosen plane to the flight...\n";
                Flight::plane = planeCurr;
                return;
            }
            throw std::invalid_argument( "This plane is not available for the chosen destination!" );

        }
    }
}

Flight::Flight(const string &destination, double lengthOfFlightInKm) {

    Flight::destination = destination;
    Flight::lengthOfFlightInKm = lengthOfFlightInKm;

}

Flight::Flight(const Flight &flight) {
    plane = flight.plane;
    destination = flight.destination;
    lengthOfFlightInKm = flight.lengthOfFlightInKm;
}

void writePlaneClassesInFile() {
    vector<PlaneClass> planeClasses{};
    vector<string> destinationsA = {"France", "Mexico", "USA", "Italy",
                                    "Germany", "Austria", "Switzerland", "Belgium"};
    PlaneClass classA(1, "First-Class", "Boeing", "Boeing 757",
                      168, 2.6, 182, 300000, destinationsA);
    planeClasses.push_back(classA);

    vector<string> destinationsB = {"Turkey", "Greece", "Hungary", "Croatia", "Romania",
                                    "Bulgaria", "Netherlands", "Albania", "Poland"};
    PlaneClass classB(2, "Business Class", "Airbus", "AirbusA330",
                      260, 2.9, 180.5, 250000, destinationsB);
    planeClasses.push_back(classB);

    vector<string> destinationsC = {"Philippines", "Australia", "Japan", "South_Korea", "China",
                                    "Vietnam", "Ethiopia"};
    PlaneClass classC(3, "Premium Economy Class", "Boeing", "B787 Dreamliner",
                      240, 3.1, 185, 250000, destinationsC);
    planeClasses.push_back(classC);

    ofstream file1;
    file1.open(FILENAME_PLANE_CLASSES, ios::app);

    for (int i = 0; i < planeClasses.size(); ++i) {
        file1 << planeClasses[i].getId() << "," << planeClasses[i].getName() << "," << planeClasses[i].getManufacturer() << ","
              << planeClasses[i].getModel() << "," << planeClasses[i].getNumberOfSeats()
              << "," << planeClasses[i].getMinLengthOfRunway() << "," << planeClasses[i].getAverageSpeed()
              << "," << planeClasses[i].getMaxTankCapacityInLiter() << endl;

        for (int j = 0; j < planeClasses[i].getPossibleDestinations().size(); ++j) {
            if(j == planeClasses[i].getPossibleDestinations().size() - 1) {
                file1 << planeClasses[i].getPossibleDestinations()[j] << endl;
            }else {
                file1 << planeClasses[i].getPossibleDestinations()[j] << ",";
            }
        }
    }
    file1.close();
}

void writePlaneIntoFile() {
    try {
        Plane plane;
        ofstream file1;
        file1.open(FILENAME_PLANES, ios::app);

        file1 << plane.getId() << "," << plane.getCostsPerEmployee()
              << "," << plane.getNumberOfEmployees() << "," << plane.getCostsForFuel() << ","
              << plane.getPlaneClass().getId() << endl;

        file1.close();
    }catch(std::invalid_argument ex) {
        cout << ex.what() << endl;
        cout << "Plane was not registered! Try again!" << endl;
    }

}

void writeFlightIntoFile() {
    try {
        Flight flight;
        ofstream file1;
        file1.open(FILENAME_FLIGHTS, ios::app);

        file1 << flight.getDestination() << "," << flight.getLengthOfFlightInKm()
              << "," << flight.getPlane().getId() << endl;

        file1.close();
    }catch(std::invalid_argument ex) {
        cout << ex.what() << endl;
        cout << "Flight was not registered! Try again!" << endl;
    }

}

vector<PlaneClass> getClassesFromFile() {
    ifstream in(FILENAME_PLANE_CLASSES);
    vector<PlaneClass> classes{};
    vector<vector<string>> destinationsForEveryClass{};
    string line{};
    int count = 1;
    while(getline(in, line)) {
        istringstream iss(line);

        string substring{};
        vector<string> substrings{};

        while(getline(iss, substring, ',')) {
            substrings.push_back(substring);
        }
        if(count % 2 != 0) {
            PlaneClass class1 = baseClass;
            class1.setId(stoi(substrings[0]));
            class1.setName(substrings[1]);
            class1.setManufacturer(substrings[2]);
            class1.setModel(substrings[3]);
            class1.setNumberOfSeats(stoi(substrings[4]));
            class1.setMinLengthOfRunway(stod(substrings[5]));
            class1.setAverageSpeed(stod(substrings[6]));
            class1.setMaxTankCapacityInLiter(stod(substrings[7]));
            classes.push_back(class1);
        } else {
            vector<string> destinations{};
            for (const auto &item: substrings) {
                destinations.push_back(item);
            }
            destinationsForEveryClass.push_back(destinations);
            classes.at(destinationsForEveryClass.size()-1).setPossibleDestinations(destinations);
        }
        count++;
    }
    return classes;
}

void readPlaneClassesFromFile() {
    vector<PlaneClass> classes = getClassesFromFile();
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "--------------------Plane classes-----------------------" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < classes.size(); ++i) {
        cout << classes[i];
        cout << "Possible destinations:" << endl;

        for (int j = 0; j < classes[i].getPossibleDestinations().size(); ++j) {
            if(j == classes[i].getPossibleDestinations().size() - 1) {
                cout << classes[i].getPossibleDestinations()[j] << endl;
            }else {
                cout << classes[i].getPossibleDestinations()[j] << ",";
            }
        }
        cout << endl;
    }
}

vector<Plane> getPlanesFromFile() {
    ifstream in(FILENAME_PLANES);
    vector<Plane> planes{};
    string line{};
    vector<PlaneClass> planeClasses = getClassesFromFile();

    while(getline(in, line)) {
        istringstream iss(line);

        string substring{};
        vector<string> substrings{};

        while(getline(iss, substring, ',')) {
            substrings.push_back(substring);
        }

        Plane plane1 = basePlane;
        plane1.setId(stoi(substrings[0]));
        plane1.setCostsPerEmployee(stod(substrings[1]));
        plane1.setNumberOfEmployees(stoi(substrings[2]));
        plane1.setCostsForFuel(stod(substrings[3]));
        for (const auto &item: planeClasses) {
            if(item.getId() == stoi(substrings[4])) {
                plane1.setPlaneClass(item);
                break;
            }
        }
        planes.push_back(plane1);
    }
    return planes;
}

void readPlanesFromFile() {
    vector<Plane> planes = getPlanesFromFile();
    if(planes.empty()) {
        cout << endl << "No registered planes currently!";
        return;
    }
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "------------------Registered planes---------------------" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < planes.size(); ++i) {
        cout << planes[i];
        cout << "Possible destinations:" << endl;
        vector<string> possibleDest = planes[i].getPlaneClass().getPossibleDestinations();
        for (int j = 0; j < possibleDest.size(); ++j) {
            if(j == possibleDest.size() - 1) {
                cout << possibleDest[j] << endl;
            }else {
                cout << possibleDest[j] << ",";
            }
        }
        cout << endl;
    }
}

void readFlightsFromFile() {
    ifstream in(FILENAME_FLIGHTS);
    vector<Flight> flights{};
    vector<Plane> planes = getPlanesFromFile();
    string line{};

    while(getline(in, line)) {
        istringstream iss(line);

        string substring{};
        vector<string> substrings{};

        while(getline(iss, substring, ',')) {
            substrings.push_back(substring);
        }
        Flight flight = baseFlight;
        flight.setDestination(substrings[0]);
        flight.setLengthOfFlightInKm(stod(substrings[1]));
        for (const auto &item: planes) {
            if(item.getId() == stoi(substrings[2])) {
                flight.setPlane(item);
                break;
            }
        }
        flights.push_back(flight);
    }
    if(flights.empty()) {
        cout << endl << "No flights registered currently!" << endl;
        return;
    }
    cout << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "------------------Registered flights--------------------" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < flights.size(); ++i) {

        cout << flights[i];
        cout << endl;
    }

}

void printPlanesSuitableForDestination() {
    string destination{};
    cout << "Enter preferred destination:" << endl;
    cin >> destination;
    vector<Plane> allPlanes = getPlanesFromFile();
    vector<Plane> chosenPlanes{};
    for (const auto &item: allPlanes) {
        if(item.checkIfPlaneIsSuitableForDestination(destination)) {
            chosenPlanes.push_back(item);
        }
    }
    if(chosenPlanes.empty()) {
        cout << "No planes available for destination " << destination << "!\n";
    } else {
        cout << "All planes suitable for destination " << destination << ":\n";
        for (const auto &item: chosenPlanes) {
            cout << item << endl;
        }
    }
}

void menu() {

    int code;
    do {
        cout << "--------------------------------------------------------" << endl;
        cout << "---------------Flight management platform---------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "1. Register new plane-----------------------------------" << endl;
        cout << "2. Register new flight----------------------------------" << endl;
        cout << "3. Print all registered planes.........................." << endl;
        cout << "4. Print all registered flights-------------------------" << endl;
        cout << "5. Print all plane classes------------------------------" << endl;
        cout << "6. Print all planes suitable for a destination----------" << endl;
        cout << "7. Exit-------------------------------------------------" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Choose option from the menu-----------------------------" << endl;

        cin >> code;
        switch(code) {
            case 1: writePlaneIntoFile(); break;
            case 2: writeFlightIntoFile(); break;
            case 3: readPlanesFromFile(); break;
            case 4: readFlightsFromFile(); break;
            case 5: readPlaneClassesFromFile(); break;
            case 6: printPlanesSuitableForDestination(); break;
            case 7: cout << "Exiting the platform!" << endl; break;
            default: cout << "Invalid operation! Choose between 1 and 7!" << endl; break;
        }
    }while(code != 7);
}

int main() {

    menu();
    return 0;
}

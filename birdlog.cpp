#include <iostream>
#include <string>
#include <stdexcept>

//class for Bird objects
class Bird{
    public:
    Bird();
    Bird(std::string name, std::string colour, unsigned int weight, unsigned int size);

    //to get private variables in a Bird object
    std::string name();
    std::string colour();
    unsigned int weight();
    unsigned int size();

    //to set/change the private variables in a Bird object
    void setName(std::string newName);
    void setColour(std::string newColour);
    void setWeight(unsigned int newWeight);
    void setSize(unsigned int newSize);

    //private variables to store infomation about Bird objects
    private:
    std::string name_;
    std::string colour_;
    unsigned int weight_; //in g
    unsigned int size_; //in cm
};

//Empty Bird object
Bird::Bird():
    name_{""},
    colour_{""},
    weight_{0},
    size_{0}{

    }

//Constructor for Bird
Bird::Bird(std::string name, std::string colour, unsigned int weight, unsigned int size):
    name_{name},
    colour_{colour},
    weight_{weight},
    size_{size}{
        if(name_ == ""){
            throw std::invalid_argument{ "Name cannot be \"\"" };
        }
        if(colour_ == ""){
            throw std::invalid_argument{ "Colour cannot be \"\"" };
        }
        if(weight_ == 0){
            throw std::invalid_argument{ "Weight cannot be 0" };
        }
        if(size_ == 0){
            throw std::invalid_argument{ "Size cannot be 0" };
        }
    }

//get methods
std::string Bird::name(){
    return name_;
}
std::string Bird::colour(){
    return colour_;
}
unsigned int Bird::weight(){
    return weight_;
}
unsigned int Bird::size(){
    return size_;
}

//set methods
void Bird::setName(std::string newName){
    name_ = newName;
}
void Bird::setColour(std::string newColour){
    colour_ = newColour;
}
void Bird::setWeight(unsigned int newWeight){
    weight_ = newWeight;
}
void Bird::setSize(unsigned int newSize){
    size_ = newSize;
}


int main(){

    std::size_t a_bird_capacity{10};
    std::size_t a_bird_count{0};
    Bird *a_bird{new Bird[a_bird_capacity]};

    //creating birds
    while(true){

        //to get the information to create a bird
        std::string name;
        std::cout << "Enter the name of the bird" << std::endl;
        std::cin >> name;

        std::string colour;
        std::cout << "Enter the colour of the bird" << std::endl;
        std::cin >> colour;

        unsigned int weight;
        std::cout << "Enter the weight of the bird (in g)" << std::endl;
        std::cin >> weight;

        unsigned int size;
        std::cout << "Enter the size of the bird (in cm)" << std::endl;
        std::cin >> size;

        //increase the array size if it's full
        if(a_bird_count >= a_bird_capacity){
            std::size_t old_capacity{a_bird_capacity};

            //duplicate a_bird array
            Bird *old_a_bird{a_bird};
            //increase the capacity by 10
            a_bird_capacity += 10;

            //reset a_bird to an array with the new capacity
            a_bird = new Bird[a_bird_capacity];

            //copy everything over from the copy of a_bird
            for( std::size_t i{0}; i < old_capacity; ++i){
                a_bird[i] = old_a_bird[i];
            }

            delete[] old_a_bird;
            old_a_bird = nullptr;
        }

        //create a bird and store it in a_bird at the index a_bird_count
        a_bird[a_bird_count] = Bird(name, colour, weight, size);
        ++a_bird_count;


        char add_bird;
        std::cout << "Do you want to add another bird? (n to exit)" << std::endl;
        std::cin >> add_bird;

        //break when the user inputs 0
        if(add_bird == 'n'){
            break;
        }
        std::cout << std::endl;
    }


    //print out the names of all the birds in the list
    std::cout << std::endl << "Birds: " << std::endl;

    for(std::size_t k{0}; k < a_bird_count; ++k){
        std::cout << (k+1) << ". " << a_bird[k].name() << std::endl;
    }

    std::cout << std::endl;


    //allow the used to get information from previously stored information
    while(true){
        char action;
        std::cout << "Get information about the birds!" << std::endl << "(c)olour, (w)eight, (s)ize" << std::endl;
        std::cin >> action;

        std::size_t bird_index;
        std::cout << "Which bird are you getting information about? (input the number)" << std::endl;
        std::cin >> bird_index;
        bird_index --;

        if(action == 'c'){
            std::cout << "The bird " << a_bird[bird_index].name() << " has the colour of " << a_bird[bird_index].colour() << "!" << std::endl;
        }
        else if(action == 'w'){
            std::cout << "The bird " << a_bird[bird_index].name() << " has the weight of " << a_bird[bird_index].weight() << "!" << std::endl;
        }
        else if(action == 's'){
            std::cout << "The bird " << a_bird[bird_index].name() << " has the size of " << a_bird[bird_index].size() << "!" << std::endl;
        }

        std::cout << std::endl;

    }


    return 0;

}
#include <iostream>
#include <string>
using namespace std; 
// HEADAER FOR PHOTO CLASS

// superclass Photo
class Photo {
    // members must be changed with getters and setters
    private:
    double width, height;

    // allows only child classes to set a new price 
    protected:
    double price;

    // public functions include: calculate_price, constructors, getters and setters,
    //      and a virtual function for calculating price 
    public:
    virtual double calculate_price() {
        if(width == 8 && height == 10)
            return 3.99;
        else if(width == 10 && height == 12)
            return 5.99;
        else
            return 9.99;
    }

    // default constructor for 1x1 photo
    Photo() {
        width = 1;
        height = 1;
        price = calculate_price();
    } 
    // constructor for preset dimensions
    Photo(double w, double h) {
        if(w > 0)
            width = w;
        else 
            width = 1;
        if(h > 0) 
            height = h;
        else
            height = 1;
        price = calculate_price();
    }

    // SETTERS
    // both call calculate_price() to update the price accordingly 
    void set_width(double w) {
        width = w;
        price = calculate_price();         
    }
    void set_height(double h) {
        height = h; 
        price = calculate_price();         
    }
    
    // GETTERS
    double get_width() { return width; }
    double get_height() { return height; }
    double get_price() { return price; }

    // display() is a virtual public function, so subclasses can modify 
    virtual void display() {
    cout << width << "x" << height
    << "in photo: $" << price << endl;
    }
};

// CHILD class MattedPhoto 
// adds matte "color" member 
// colors are preset, otherwise matte color is white
class MattedPhoto : public Photo {
    private:
    string color;
    
    public:
    // partial override for price calculation 
    double calculate_price() {
        return Photo::calculate_price() + 10;
    }

    // default constructor with white matte
    MattedPhoto() {
        color = "white";
    }

    // constructor
    MattedPhoto(string selected_color) {
        set_color(selected_color);
        price = calculate_price();
    }

    // SETTERS and GETTERS
    void set_color(string selected_color) { 
        if(selected_color == "black" || selected_color == "blue" || 
            selected_color == "red" || selected_color == "gray") {
            color = selected_color;
        }
        else { color = "white"; }
    }
    string get_color() { return color; }

    // override parent class display() function
    void display() {
        cout << get_width() << "x" << get_height() << "in "
        << get_color() << " matted photo: $" << get_price() << endl;
    }
};

// CHILD class FramedPhoto
// adds members for frame material and frame style
// material and style options are preset and has default option
class FramedPhoto : public Photo {
    private: 
    string material, style;

    public:
    // partial override price from parent class
    double calculate_price() {
        return Photo::calculate_price() + 25;
    }
    // default constructor with plain, wooden frame
    FramedPhoto() {
        material = "wood";
        style = "plain";
    }
    // constructor calls setters 
    FramedPhoto(string selected_material, string selected_style) {
        set_material(selected_material);
        set_style(selected_style);
    }
    // SETTERS and GETTERS
    // validates frame material and style options 
    // if invalid input, defaults to a plain wooden frame
    void set_material(string selected_material) { 
        if(selected_material == "silver" || selected_material == "gold" || 
            selected_material == "diamond") {
            material = selected_material;
        }
        else { 
            material = "wood"; }
    }
    void set_style(string selected_style) {
        if(selected_style == "modern" || selected_style == "rustic" || 
            selected_style == "gradient") {
                style = selected_style;
            }
        else { 
            style = "plain"; }
    }
    string get_material() { return material; }
    string get_style() { return style; }
    
    // override parent class display() function
    void display() {
        cout << get_width() << "x" << get_height() << "in " << get_style() << ", "
        << get_material() << " framed photo: $" << get_price() << endl;
    }
};
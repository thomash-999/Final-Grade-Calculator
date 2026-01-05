
#include "photo.h"

int main() {
    // can change the number of photos to ask for 
    // then create a pointer to an array of photos that size 
    const int NUMBER_PHOTOS = 2;
    Photo* photo_list[NUMBER_PHOTOS];

    for (int i = 0; i < NUMBER_PHOTOS; i++) {
        // declare variables for user's input
        string photo_type;
        int width, height;

        // ask user for photo type and dimensions 
        // if photo_type is invalid, skips that photo selection
        cout << "Type of photo for photo " << i + 1 << " (regular, matte, or framed): ";
        cin >> photo_type;
        if(photo_type != "regular" && photo_type != "matte" && photo_type != "framed") {
            cout << "Invalid photo type.\n";
            continue;
        }
        
        // ask user for photo dimensions
        cout << "Width: ";
        cin >> width;
        cout << "Height: ";
        cin >> height;

        // asked for corresponding member based on user selection
        if(photo_type == "regular") {
            photo_list[i] = new Photo(width, height);
        }
        // branch for matte photos
        else if(photo_type == "matte") {
            string color;
            cout << "Matte color (white (default), black, red, or gray): ";
            cin >> color;
            photo_list[i] = new MattedPhoto(color);

            // call setters for base photo 
            photo_list[i]->set_width(width);
            photo_list[i]->set_height(height);
        }
        else if(photo_type == "framed") {
            string frame_material, frame_style;
            cout << "Frame material (wood (default), gold, silver, or diamond): ";
            cin >> frame_material;
            cout << "Frame style (plain (default), modern, rustic, or gradient): ";
            cin >> frame_style;

            // Assign user input values to object members
            photo_list[i] = new FramedPhoto(frame_material, frame_style);

            // call setters for base photo
            photo_list[i]->set_width(width);
            photo_list[i]->set_height(height);
        }
        // prints corresponding display() function
        photo_list[i]->display();
        
        
            
        
    }
    
}
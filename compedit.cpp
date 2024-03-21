#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <cstdlib>
#include "cimage.h"
#include "bmplib.h"

using namespace std;
void doInputLoop(std::istream& istr, CImage& img); // prototype

int main(int argc, char *argv[])
{
    if(argc < 2) {
        cout << "Usage ./compedit in_img_filename <option option-args>" << endl;
        return 1;
    }

    // ===================
    // TO DO: Fill in the argument to the constructor below


    // ===================
    // TO DO: call findComponents


    // ===================
    // Complete - Do not alter
    //   Option handling
    int option = 0;
    if(argc >= 3) {
        option = atoi(argv[2]);
    }
    if(option == 1) {
        // Complete - Do not alter
        img1.printComponents();
        return 0;
    }
    else if(option == 2 || option == 3) {
        // Complete - Do not alter
        if(argc < 4) {
            cout << "Please provide an extra argument of the filename to save the image." << endl;
        }
        else if(option == 2){
            img1.labelToRGB(argv[3]);
        }
        else if(option == 3){
            img1.drawBoundingBoxesAndSave(argv[3]);
        }
        return 0;
    }

		// ===================
		// Setup input stream
		if(option == 4) {
        if(argc < 4) {
            cout << "Please provide an extra argument of the command filename." << endl;
            return 0;
        }        
        string cmd_error = "Bad command filename";

        // ===================
        // TODO: Create appropriate input stream. Print the string cmd_error and return 0
        // if the file can't be opened


        if(    ){
            cout << cmd_error << endl;
            return 0;
        }
        // ===================
        //  Pass the input stream you created
        doInputLoop(/* pass your input stream */, img1);  
        // ===================
        //  TODO: Close the file

		}
    else {
        doInputLoop(cin, img1);
    }

    // ===================
    // If necessary, add any cleanup code


    return 0;
}

void doInputLoop(std::istream& istr, CImage& img)
{
    // ===================
    // TODO: Complete the implementation to process user commands
    //  of t - translate, f - forward, b - backward, s - save, and
    //  any other input letter to quit.
    string option_error = "Bad option";
    char option = 'q';
    int cid;
    bool again = true;
    do {
        img.printComponents();
        cout << "\nEnter a command [t,f,b,s,q]: " << endl;
        istr >> option;
        if(option == 't') {
            int nr, nc;
            // ==================
            // TODO: Read cid, nr, and nc from the input stream,
            //       printing "Bad option" and breaking from the 
            //       loop if any of the input is not read successfully



            img.translate(cid, nr, nc);
        }
        else if(option == 'f' || option == 'b') {
            int delta;
            // ==================
            // TODO: Read cid and delta from the input stream
            //       printing "Bad option" and breaking from the 
            //       loop if any of the input is not read successfully




            if(option == 'f') {
                img.forward(cid, delta);
            }
            else {
                img.backward(cid, delta);
            }
        }
        else if(option == 's') {
            string filename;
            // ==================
            // TODO: Read filename from the input stream,
            //       printing "Bad option" and breaking from the 
            //       loop if any of the input is not read successfully




            img.save(filename.c_str());
        }
        else {
            again = false;
        }
    } while(again);
}

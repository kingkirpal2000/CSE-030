#include <iostream>
#include <RandomSupport.h>
#include <TimeSupport.h>
#include <SomethingCool.h>

using namespace std;


// A function that performs linear search through an array
bool search(long* arr, long n, long val){
    // Go through the whole array
    for (long i = 0; i < n; i++) {
        // If you found the value you want, stop and return
        if (arr[i] == val){
            return true;
        }
    }
    // If you complete the loop and have not returned
    // that means the value you are looking for is not there
    return false;
}


int main() {
    // How big should our array be
    long N = 10000000;
    
    // Search range
    long K = 1000;
    
    // Declare the array as a pointer to a location
    // big enough to store N long integers
    long* arr = new long[N];

    // This is the data structure that allows efficient searching
    MyStruct* coolDataStructure = new MyStruct();
    
    // Setup a random number generator (randomizer)
    randomizer device = new_randomizer();
    // Set up a distribution to sample from, ranging 1 to N
    uniform_distribution dist = new_distribution(1, N);

    cout << "Generating " << N << " random numbers:" << endl;
    
    // Fill up the array with N random numbers
    for (long i = 0; i < N; i++) {
        long rand = sample(dist, device);
        // Save the number in the array
        arr[i] = rand;
        
        // Now save it in the efficient data structure as well
        coolDataStructure->insert(rand); 
    }

    cout << "Done." << endl << endl;

    cout << "Performing " << K << " searches (naive method):" << endl;
    
    // Get a timestamp before starting the searches
    timestamp start = current_time();
    
    // Search for every number in the range
    // Output if found
    for (int i = 0; i < K; i++){
        bool temp = search(arr, N, i);
        // if (temp){
        //     cout << i << " found." << endl;
        // }
    }
    
    // Get a timestamp right after you're done searching
    timestamp end = current_time();
    
    // How much time passed between the two timestamps
    long duration = time_diff(start, end);
    
    // Print out the duration
    cout << "Took " << duration << " ms." << endl << endl;


    cout << "Performing " << K << " searches (efficient method):" << endl;

    // Get a timestamp before starting the searches
    start = current_time();
    
    // Search for every number in the range
    
    for (int i = 0; i < K; i++){
        bool temp = coolDataStructure->search(i);
        // if (temp){
        //     cout << i << " found." << endl;
        // }
    }
    
    // Get a timestamp right after you're done searching
    end = current_time();
    
    // How much time passed between the two timestamps
    duration = time_diff(start, end);
    
    // Print out the duration
    cout << "Took " << duration << " ms." << endl;
    
    // Release the memory occupied by the array and the other data structure
    // This is important
    delete[] arr;
    delete coolDataStructure;
}

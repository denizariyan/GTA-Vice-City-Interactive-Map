# GTA Vice City Interactive Map

Intention of this project is to create a dev tool for GTA Vice City to be used for further development. Utilizing memory reading to read the location of the player and memory manipulation to teleport.


## Demonstration
Check [this video](https://youtu.be/_q_Z3azR6bw) for a demonstration.


## Installation

### Using a precompiled executable (Recommended) - x64 only

1. Go to [the releases page](https://github.com/denizariyan/GTA-Vice-City-Interactive-Map/releases) and download the latest release.
1. Extract the contents to a location.
1. Run GTA Vice City
1. Run the provided executable with admin permissions
1. Follow the instructions for usage below

### By compiling Yourself

1. `git clone https://github.com/denizariyan/GTA-Vice-City-Interactive-Map.git`
1. `cd GTA-Vice-City-Interactive-Map`
1. Delete the `.git` folder
1. Open the project using Visual Studio or open the source code using your preferred compiler
1. Set the paths for requirements such as OpenCV and compile
1. Follow the instructions for usage below


## Usage

1. Launch the GTA Vice City
1. Run the executable with admin permissions
1. The red marker on the map will always show the current location of the player
1. Click on the generated map window to teleport to the location. In some cases where the game engine did not load the location which you are teleporting to, you might fall through the floor. The game should teleport you back to a safe location nearby in that case
1. Make sure to close the software before closing the game else you might get a warning about memory access violation


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## Disclaimer

Rockstar Games does NOT endorse or sponsor this project. This is a community made project to enrich the user experience.

## License
Copyright (c) 2020 Deniz Ariyan

[MIT](https://choosealicense.com/licenses/mit/)

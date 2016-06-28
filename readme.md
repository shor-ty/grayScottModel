# README #

## Description of the Gray-Scott-Model

The solver calculates two simple reaction-diffusion equations that are coupled. The model can be used to investigate into numerical schemes and code validations.

### OpenFOAM Versions ###
* Generated for version 
** 2.3.x **
** 3.0.x **

### What is this repository for? ###
* This model calculates two coupled reaction-diffusion equations
* It can be used to investigate into numerical schemes, code validations and get nice patterns


### Compiling the application ###
* Feel free to compile it where ever you want, but normally its nice to have a fixed folder for _user compiled stuff_
* Make a new folder
> mkdir -p $FOAM_RUN/../OpenFOAM_extensions
* Switch to the new folder
> cd $FOAM_RUN/../OpenFOAM_extensions
* Clone the repository to the new folder
> git clone git@bitbucket.org:shor-ty/grayScottModel.git
* Switch to the repository directory
> cd grayScottModel 
* Switch to the branch you need

* for version 2.3.x use the following command
> git checkout flameletModel-2.3.x
* for version 3.0.x use the following command
> git checkout flameletModel-3.0.x
* After that pull it
> git pull
* Now you have everything and you can start compiling
* For that just run the Allwmake script
> ./Allwmake
* Finally copy the tutorials to your run folder
> cp -r tutorials $FOAM_RUN/
* Finished

### Contribution guidelines ###
* If you have questions, hints or any suggestions please email me to Tobias.Holzmann@Holzmann-cfd.de

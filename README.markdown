See the folder fost-base for all projects files, licenses etc.

THIS IS PROBABLY THE WRONG CHECK OUT unless you are developing fost-base itself.

If you want to use fost-base in your code you want to add https://github.com/KayEss/fost-base.git to your project.

# Building the Docker container #

The container is aimed at producing a build environment for compiling the Fost libraries and packages.

To build you will need to have a host `apt-cacher` that points to an apt proxy.

To use the builder environment to perform builds you can use a docker command like the following:

    sudo docker run -v $(pwd):/src -it kayess/fost-builder fost-build fost-base/compile release

This will do a release build of the `fost-base` project files. They will end up in the d`ist-docker` folder.

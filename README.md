C++ Micro Services Test Driver
==============================

The [C++ Micro Services library](http://cppmicroservices.org/) provides a dynamic service registry and module system.

This repository provides a console driver to interface with the library.

Build Instructions
------------------

1. Download and install [biicode](http://www.biicode.com/).
2. Set up a new biicode project, and clone this repository into the `<project>/blocks/<user>/` directory.  

		bii init myproject
		cd myproject/blocks
		mkdir myuser && cd myuser
		git clone git@github.com:azriel91/ustestdriver.git
		bii find
		bii cpp:build

To run the driver, change to the project directory and run

	./bin/myuser_ustestdriver_main

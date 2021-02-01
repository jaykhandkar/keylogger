# Keylogger
Simple linux keylogger implemented as a linux kernel module.  
# Installation
Run ``make`` in the folder where the Makefile and sources are.  
If it compiles without errors, you should see the file ``keylogger.ko`` in the same directory.  
Use ``sudo insmod keylogger.ko`` to insert the module (root privileges required) and 
``sudo rmmod keylogger`` to remove it.


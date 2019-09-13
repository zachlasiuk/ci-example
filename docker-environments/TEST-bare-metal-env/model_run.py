#!/usr/bin/env python
import sys,os

# Set python path to Fast Models
try:
    sys.path.append(os.path.join(os.environ['PVLIB_HOME'], 'lib', 'python27')) 
except KeyError as e:
    print "Error! Make sure you source all from the fast models directory. Try something like this:"
    print "$ source <FMinstallDirectory>/FastModelsTools_11.0/source_all.sh"
    sys.exit()

from fm.debug import *


# Check Arguments
if len(sys.argv) != 5:
    print "Usage: %s <model_hostname> <model_port> <application_axf> <output_file>" % sys.argv[0]
    sys.exit()

# Connect to the running model on local host
m = NetworkModel(sys.argv[1], int(sys.argv[2]))

# Find the first CPU target
cpu = m.get_cpus()[0]

# Load the unit testing image into the model
cpu.load_application(sys.argv[3])

# Write stdout to a file
cpu.stdout = open(sys.argv[4], 'w')

# Start model execution
m.stop
cpu.reset
m.run()

#!/usr/bin/env python
import sys,os
import subprocess
import time

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


### Subprocess executing function
def execute(cmd):
    popen = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, universal_newlines=True)
    for stdout_line in iter(popen.stdout.readline, ""):
        yield stdout_line 
    popen.stdout.close()
    return_code = popen.wait()
    if return_code:
        raise subprocess.CalledProcessError(return_code, cmd)





# Start model process running, verify it has started before moving on
script_dir = sys.path[0]
cmd = [script_dir+'/Cortex-M33-FVP/FVP_MPS2_Cortex-M33','-C','fvp_mps2.DISABLE_GATING=1','-C','fvp_mps2.platform_type=1','--cadi-server']
print cmd
#for output_line in execute(cmd):
#	if "CADI Debug Server started" in output_line:
#		break

process = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
# Verify model has started before moving on, or timeout
timeout = time.time()+10 # 10 second timeout
while True:
	if "Info: FVP_MPS2_Cortex_M33: CADI Debug Server started for ARM Models..." in process.stdout.readline():
		break
	if time.time() > timeout:
		print 'Error; model never seemed to start. Exiting python script.'
		sys.exit()
	time.sleep(0.5)

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


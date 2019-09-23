import os
import sys
import pytest

# Get path to this file
test_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(1, test_dir+'/../src')
import myapp


# Tests
def test_socket_init():
	s = myapp.initWebCon('www.google.com',80)
	print type(s)
	assert isinstance(s,object)

def test_data_formatting():
	for data in myapp.device_data:
		assert isinstance(data,str)

# # Build command
# #     docker build -t test-linux-env:latest .
#
# # Run command
# #     docker run --network host -it test-linux-env:latest




FROM ubuntu:16.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y

### System Functionality ###
RUN apt-get install -y apt-utils iputils-ping python2.7
RUN apt-get install -y python-pip

### Python requirements
RUN apt-get install -y python-pytest

# # Build command
# #     docker build -t test-bare-metal-env:latest .
#
# # Run command
# #     docker run --network host -it test-bare-metal-env:latest




FROM ubuntu:16.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y

### System Functionality ###
RUN apt-get install -y apt-utils iputils-ping python2.7
RUN apt-get install -y python-pip

## AC6 dependencies
RUN apt-get install -y --fix-missing \

### Tool version selection
ARG AC_INSTALL=

### Install Fast Models
# # Copy Fast Model install file from same directory as this Dockerfile
COPY $AC_INSTALL.tgz /home/

# # install AC6, delete artifacts
RUN tar 

# # add setup to /init.sh
RUN echo "set +e; . /arm-tools/$FM_DIR/source_all.sh" >> /arm-tools/init.sh

# # add init.sh to bashrc
RUN echo "source /arm-tools/init.sh"


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

## Fast Models dependencies
RUN apt-get install -y --fix-missing \
	lsb-core     \
	libxext6     \
	libsm6       \
	libxcursor1  \
	libxft2      \
	libxrandr2   \
	libxt6       \
	libxinerama1
## Unity Junit conversion dependencies
RUN pip install pyparsing


### Tool version selection
ARG FM_INSTALL=FastModels_11-7-035_Linux64
ARG FM_DIR=FastModelsTools_11.7

### Install Fast Models
# # Copy Fast Model install file from same directory as this Dockerfile
COPY $FM_INSTALL.tgz /home/

# # install Fast Models, delete artifacts
RUN tar xvzf /home/$FM_INSTALL.tgz            &&\
		cd $FM_INSTALL                &&\
		./setup.sh --i-accept-the-license-agreement --basepath /arm-tools/     &&\
		rm /home/$FM_INSTALL.tgz      &&\
		rm -r /$FM_INSTALL/

# # add setup to /init.sh
RUN echo "set +e; . /arm-tools/$FM_DIR/source_all.sh" >> /arm-tools/init.sh

# # add init.sh to bashrc
RUN echo "source /arm-tools/init.sh"


### Add FVP
ARG FVP_TAR=Cortex-M33-FVP.tar
ADD $FVP_TAR /arm-tools/

### Add unity2junit result conversion file, make output directory for test results
ADD unity_to_junit.py /home/
RUN mkdir /home/output

### Set License
ENV ARMLMD_LICENSE_FILE=7010@localhost


#### TEMPORARY, TO BE REPLACED LATER


### Add software
COPY IOTKit_ARMv8MBL_test.axf /home/

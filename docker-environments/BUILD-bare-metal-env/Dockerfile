# # Build command
# #     docker build --build-arg AC_DIR=./ --build-arg AC_INSTALL=DS500-BN-00026-r5p0-14rel0.tgz -t build-bare-metal-env:latest .
#
# # Run command
# #     docker run --network host -it build-bare-metal-env:latest


FROM ubuntu:16.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update -y

### System Functionality ###
RUN apt-get install -y apt-utils iputils-ping make

## Test functionality
RUN apt install -y ruby-full
#RUN apt-get install -y --fix-missing \

RUN mkdir /arm-tools/
ARG TMP_DIR=/home/tmp/

### Install Arm Compiler 6
# # Copy Arm Compiler 6 install file from same directory as this Dockerfile
# MUST set arguments for AC6 tarball during build. Defaults:
ARG AC_DIR=./
ARG AC_INSTALL=DS500-BN-00026-r5p0-14rel0.tgz
ADD $AC_DIR/$AC_INSTALL $TMP_DIR

# # install AC6 
RUN $TMP_DIR/install_x86_64.sh --i-agree-to-the-contained-eula --no-interactive -d /arm-tools/AC6/

# delete artifacts
RUN rm -rf $TMP_DIR

# # add setup to /init.sh (adding to path)
RUN echo "export PATH=$PATH:/arm-tools/AC6/bin" >> /arm-tools/init.sh
RUN echo "export ARMLMD_LICENSE_FILE=7010@localhost" >> /arm-tools/init.sh
